/* xsh_babybird.c - xsh_babybird */

#include <xinu.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int babies;
int wormsFetch;
int wormsEat;
/*------------------------------------------------------------------------
 * xsh_babybird - Babybird Problem
 *------------------------------------------------------------------------
 */
shellcmd xsh_babybird(int nargs, char *args[]) {

	// base defaults
	babies = 2;
	wormsFetch = 3;
	wormsEat = 2;	

	/*
	cmd usage: babybird -b/--babies <num babies> -f/--fetch <num worms fetch> -e/--eat <num worms eat>
			   babybird -h --help
	*/
	printf("Hello from Babybird command \n");

	/* Output info for '--help' argument */

	if (nargs == 2 && (strncmp(args[1], "--help", 7) == 0) || (strncmp(args[1], "-h", 3) == 0)) {
		printf("Usage: %s\n\n", args[0]);
		printf("Description:\n");
		printf("\tThe Babybird Problem\n");
		printf("\tbabybird -b/--babies <num babies> -f/--fetch <num worms fetch> -e/--eat <num worms eat>\n");
		printf("Options (one per invocation):\n");
		printf("\t--help\tdisplay this help and exit\n");
		return 0;
	}

	//Fall to Default Gracefully
	if (nargs == 1) {
		//TODO
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

	int i=0, command=0;
	// Further Validations
	for(i=1; i<nargs; i+=2){
		printf("Cmd Arg: %s\n", args[i]);
		if(strncmp(args[i], "--babies", 9) == 0 || strncmp(args[i], "-b", 3) == 0){
			command = 1;
			if(atoi(args[i+1]) < 1){
				printf("At least 1 baby required\n");
			}
			else{
				babies = atoi(args[i+1]);
				printf("Number of babies = %d\n", babies);
			}
		}
		if(strncmp(args[i], "--fetch", 8) == 0 || strncmp(args[i], "-f", 3) == 0){
			command = 2;
			if(atoi(args[i+1]) < 1){
				printf("At least 1 worm required to be fetched\n");
			}
			else{
				wormsFetch = atoi(args[i+1]);
				printf("Number of worms to fetch = %d\n", wormsFetch);
			}
		}
		if(strncmp(args[i], "--eat", 6) == 0 || strncmp(args[i], "-e", 3) == 0){
			command = 3;
			if(atoi(args[i+1]) < 1){
				printf("At least 1 worm required to eat\n");
			}
			else{
				wormsEat = atoi(args[i+1]);
				printf("Number of worms to eat = %d\n", wormsEat);
			}
		}

		if(command == 0){
			fprintf(stderr, "Please enter correct arguments\n");
			return 0;
		}

	}
	
	//TODO
	
	return 0;
}
