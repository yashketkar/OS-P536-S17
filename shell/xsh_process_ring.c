/* xsh_process_ring.c - xsh_process_ring */

#include <xinu.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <process_ring.h>

volatile int inbox[101];
volatile int ring[101];
volatile int round;

int NUM_PROCESSES;
int num_rounds;
int countdown;
int version;

/*------------------------------------------------------------------------
 * xsh_process_ring - Print countdown of numbers
 *------------------------------------------------------------------------
 */
shellcmd xsh_process_ring(int nargs, char *args[]) {

	NUM_PROCESSES = 4;
	num_rounds = 5;
	version = 1;		
	/* Output info for '--help' argument */

	if (nargs == 2 && (strncmp(args[1], "--help", 7) == 0) || (strncmp(args[1], "-h", 3) == 0)) {
		printf("Usage: %s\n\n", args[0]);
		printf("Description:\n");
		printf("\tPrints the countdown of numbers\n");
		printf("\tArguments taken from the command line are -p -r -v -h.\n");
		printf("Options (one per invocation):\n");
		printf("\t--help\tdisplay this help and exit\n");
		return 0;
	}

	if (nargs == 1) {
		//default mode
		countdown = NUM_PROCESSES * num_rounds;
		inbox[0] = countdown;

		int i = 0;
		for(i=0;i<NUM_PROCESSES;i++)
		{
		ring[i] = create(process_ring, 1024, 20, "process_ring", 3, i, NUM_PROCESSES, version);
		}

		resume(ring[0]);
		return 0;
	}

	/* Check argument count */
	if(nargs%2 == 0){
		//command name + set of parameters is always odd
		fprintf(stderr, "Please enter correct arguments\n");
		return 1;
	}


	if (nargs > 7) {
		fprintf(stderr, "%s: too many arguments\n", args[0]);
		fprintf(stderr, "Try '%s --help' for more information\n",
			args[0]);
		return 1;
	}

	if (nargs < 1) {
		fprintf(stderr, "%s: too few arguments\n", args[0]);
		fprintf(stderr, "Try '%s --help' for more information\n",
			args[0]);
		return 1;
	}

	//true input
	int i = 0;
	int command = 0;
	
	for(i=1; i<nargs; i+=2){
		printf("Cmd Arg: %s\n", args[i]);
		//int command = validateAndGetCommand(args[i]);
		if(strncmp(args[i], "--processes", 12) == 0 || strncmp(args[i], "-p", 3) == 0){
			command = 1;
			NUM_PROCESSES = atoi(args[i+1]);
			if(NUM_PROCESSES > 100 || NUM_PROCESSES < 1){
				//too many processes are denied
				printf("Too Many or too less Processes\n");
				NUM_PROCESSES = 4;
			}
			printf("Number of processes = %d\n", NUM_PROCESSES);
		}
		if(strncmp(args[i], "--rounds", 9) == 0 || strncmp(args[i], "-r", 3) == 0){
			command = 2;
			num_rounds = atoi(args[i+1]);
			if(num_rounds < 1){
				//too many processes are denied
				printf("Too Many or too less Rounds\n");
				num_rounds = 5;
			}
			printf("Number of rounds = %d\n", num_rounds);
		}
		if(strncmp(args[i], "--version", 10) == 0 || strncmp(args[i], "-v", 3) == 0){
			command = 3;
			if(strncmp(args[i+1], "work", 5) == 0){
				version = 1;
			}
			if(strncmp(args[i+1], "hang", 5) == 0){
				version = 2;
			}
			if(strncmp(args[i+1], "loop", 5) == 0){
				version = 3;
			}
			if(strncmp(args[i+1], "chaos", 6) == 0){
				version = 4;
			}
		}

		//printf("command: %s\n", command);
		
		if(command == 0){
			fprintf(stderr, "Please enter correct arguments\n");
			return 0;
		}

	}

	countdown = NUM_PROCESSES * num_rounds;
	inbox[0] = countdown;
	for(i=0;i<NUM_PROCESSES;i++)
	{
	ring[i] = create(process_ring, 1024, 20, "process_ring", 3, i, NUM_PROCESSES, version);
	}
	resume(ring[0]);

	return 0;
}