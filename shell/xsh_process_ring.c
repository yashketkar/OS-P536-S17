/* xsh_process_ring.c - xsh_process_ring */

#include <xinu.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <process_ring.h>

volatile int *inbox;

int NUM_PROCESSES;
int num_rounds;
int countdown;

/*------------------------------------------------------------------------
 * xsh_process_ring - Print countdown of numbers
 *------------------------------------------------------------------------
 */
shellcmd xsh_process_ring(int nargs, char *args[]) {

	/* Output info for '--help' argument */

	if (nargs == 1 && strncmp(args[1], "--help", 7) == 0) {
		printf("Usage: %s\n\n", args[0]);
		printf("Description:\n");
		printf("\tPrints the countdown of numbers\n");
		printf("\tArguments taken from the command line are -p -r -v -h.\n");
		printf("Options (one per invocation):\n");
		printf("\t--help\tdisplay this help and exit\n");
		return 0;
	}

	if (nargs == 1) {
		//printf("Hello %s, Welcome to the world of Xinu!!\n",args[1]);
		NUM_PROCESSES = 4;
		num_rounds = 5;
		countdown = NUM_PROCESSES * num_rounds;
		int my_inbox[NUM_PROCESSES];
		my_inbox[0]=countdown;
		inbox = my_inbox;
		int i = 0;
		for(i=0;i<NUM_PROCESSES;i++)
		{
		resume(create(process_ring, 1024, 20, "process_ring", 1, i));	
		}
	}

	/* Check argument count */

	if (nargs > 1) {
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


	return 0;
}