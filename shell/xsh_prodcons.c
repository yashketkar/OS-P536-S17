/* xsh_prodcons.c - xsh_prodcons */

#include <xinu.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/*------------------------------------------------------------------------
 * xsh_prodcons - Producer Consumer Problem with Futures
 *------------------------------------------------------------------------
 */
shellcmd xsh_prodcons(int nargs, char *args[]) {
	
	/* Output info for '--help' argument */

	if (nargs == 2 && strncmp(args[1], "--help", 7) == 0) {
		printf("Usage: %s\n\n", args[0]);
		printf("Description:\n");
		printf("\tPrints the countdown of numbers\n");
		printf("\tArguments taken from the command line are -p -r -v -h.\n");
		printf("Options (one per invocation):\n");
		printf("\t--help\tdisplay this help and exit\n");
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

	if (nargs == 2 && strncmp(args[1], "-f", 3) == 0) {
		future_t* f_exclusive, * f_shared, * f_queue;

	  f_exclusive = future_alloc(FUTURE_EXCLUSIVE);
	  f_shared    = future_alloc(FUTURE_SHARED);
	  f_queue     = future_alloc(FUTURE_QUEUE);

	  // Test FUTURE_EXCLUSIVE
	  resume( create(future_cons, 1024, 20, "fcons1", 1, f_exclusive) );
	  resume( create(future_prod, 1024, 20, "fprod1", 2, f_exclusive, 1) );

	  // Test FUTURE_SHARED
	  resume( create(future_cons, 1024, 20, "fcons2", 1, f_shared) );
	  resume( create(future_cons, 1024, 20, "fcons3", 1, f_shared) );
	  resume( create(future_cons, 1024, 20, "fcons4", 1, f_shared) ); 
	  resume( create(future_cons, 1024, 20, "fcons5", 1, f_shared) );
	  resume( create(future_prod, 1024, 20, "fprod2", 2, f_shared, 2) );

	  // Test FUTURE_QUEUE
	  resume( create(future_cons, 1024, 20, "fcons6", 1, f_queue) );
	  resume( create(future_cons, 1024, 20, "fcons7", 1, f_queue) );
	  resume( create(future_cons, 1024, 20, "fcons8", 1, f_queue) );
	  resume( create(future_cons, 1024, 20, "fcons9", 1, f_queue) );
	  resume( create(future_prod, 1024, 20, "fprod3", 2, f_queue, 3) );
	  resume( create(future_prod, 1024, 20, "fprod4", 2, f_queue, 4) )
	  resume( create(future_prod, 1024, 20, "fprod5", 2, f_queue, 5) );
	  resume( create(future_prod, 1024, 20, "fprod6", 2, f_queue, 6) );
			return 0;
	}
}
