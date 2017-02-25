/* xsh_babybird.c - xsh_babybird */

#include <xinu.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include <baby_bird.h>

/*------------------------------------------------------------------------
 * xsh_babybird - Baby Bird Program
 *------------------------------------------------------------------------
 */

volatile int worms=0;
volatile int done;
int num_baby_birds;
int fetch;
int eat;

shellcmd xsh_babybird(int nargs, char *args[]) {

	/* Output info for '--help' argument */
	if (nargs == 2 && strncmp(args[1], "--help", 7) == 0) {
		printf("Usage: %s\n\n", args[0]);
		printf("Description:\n");
		printf("\tRuns the Baby Bird Program\n");
		printf("\tArguments taken from the command line are -b -f -e.\n");
		printf("Options (one per invocation):\n");
		printf("\t--help\tdisplay this help and exit\n");
		return 0;
	}

	if (nargs == 1) {
		// default mode
		num_baby_birds = 5;
		fetch = 10;
		eat = 10;

		mutex_t* lock = (mutex_t*)getmem(sizeof(mutex_t));
		mutex_create(lock);

		cond_t* cvP = (cond_t*)getmem(sizeof(cond_t));
		cond_init(cvP);

		cond_t* cvC = (cond_t*)getmem(sizeof(cond_t));
		cond_init(cvC);

		done = 0;

		int i=0;
		for(i=0;i<num_baby_birds;i++){
			//create a consumer process
			printf("Created Baby Bird #%d\n", i+1);
			pid32 mypid;
			mypid = create(babybird, 1024, 20, "babybird", 6, lock, cvP, cvC, eat, i+1, done);
			insertinQueue(cvC, mypid);
		}

		//create a producer process
		printf("Created Parent Bird \n");
		pid32 parentid = create(parentbird, 1024, 20, "parentbird", 5, lock, cvP, cvC, fetch);
		resume(parentid);

		return 0;
	}

	/* Check argument count */
	if(nargs%2 == 0){
		//command name + set of parameters is always odd
		fprintf(stderr, "Please enter correct arguments -b -f -e\n");
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

	// Correct Arguments Run Program Now
	// To Do
	//true input

	int i = 0;
	int command = 0;
	
	for(i=1; i<nargs; i+=2){
		printf("Cmd Arg: %s\n", args[i]);
		//int command = validateAndGetCommand(args[i]);
		if(strncmp(args[i], "--babies", 12) == 0 || strncmp(args[i], "-b", 3) == 0){
			command = 1;
			num_baby_birds = atoi(args[i+1]);
			if(num_baby_birds > 100 || num_baby_birds < 1){
				//too many processes are denied
				printf("Too many or too less babybirds\n");
				num_baby_birds = 4;
			}
			printf("Number of babybirds = %d\n", num_baby_birds);
		}
		if(strncmp(args[i], "--fetch", 9) == 0 || strncmp(args[i], "-f", 3) == 0){
			command = 2;
			fetch = atoi(args[i+1]);
			if(fetch < 1){
				//too many processes are denied
				printf("Too many or too less worms to fetch\n");
				fetch = 5;
			}
			printf("Number of worms to fetch = %d\n", fetch);
		}
		if(strncmp(args[i], "--eat", 10) == 0 || strncmp(args[i], "-e", 3) == 0){
			command = 3;
			eat = atoi(args[i+1]);
			if(eat < 1){
				//too many processes are denied
				printf("Too many or too less worms to eat\n");
				eat = 5;
			}
			printf("Number of worms to eat = %d\n", eat);			
		}
		
		if(command == 0){
			fprintf(stderr, "Please enter correct arguments\n");
			return 0;
		}
	}

	mutex_t* lock = (mutex_t*)getmem(sizeof(mutex_t));
	mutex_create(lock);

	cond_t* cvP = (cond_t*)getmem(sizeof(cond_t));
	cond_init(cvP);

	cond_t* cvC = (cond_t*)getmem(sizeof(cond_t));
	cond_init(cvC);

	done = 0;

	for(i=0;i<num_baby_birds;i++){
		//create a consumer process
		printf("Created Baby Bird #%d\n", i+1);
		pid32 mypid;
		mypid = create(babybird, 1024, 20, "babybird", 6, lock, cvP, cvC, eat, i+1, done);
		insertinQueue(cvC, mypid);
	}

	//create a producer process
	printf("Created Parent Bird \n");
	pid32 parentid = create(parentbird, 1024, 20, "parentbird", 5, lock, cvP, cvC, fetch);
	resume(parentid);

	return 0;
}