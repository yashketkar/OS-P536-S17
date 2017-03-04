#include <xinu.h>
#include <prodcons.h>

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <future.h>

volatile int n;

sid32 produced, consumed;

int parseNumber(char *str, int *ret, int max) {
	if (strnlen(str, max + 1) > max) {
		return 0;
	}
	int i=0, len=strnlen(str, max+1);
	int sum = 0;
	for (i=0; i<len; i++) {
		if (str[i] < '0' || str[i] > '9') {
			return 0;
		}
		sum = sum * 10 + (str[i]- '0');
	}
	*ret = sum;
	return 1;
}

shellcmd xsh_prodcons(int argc, char * argv[]) {
	if (argc == 2 && strncmp(argv[1], "--help", 7) == 0) {
		printf("Usage: %s [-f]\n\n", argv[0]);
		printf("Description:\n");
		printf("\tprints output of future producer consumer processes.\n");
		printf("\t-f flag makes use of Futures.\n");
		return 0;
	}

	if (argc > 2) {
		fprintf(stderr, "%s: Wrong Number of Arguments.\n", argv[0]);
		return -1;
	}
	int count = 2000;
	int useFuture = 0;
	if (argc == 2) {
		if (!strncmp(argv[1], "-f", 2)) {
			useFuture = 1;
		} else if (parseNumber(argv[1], &count, 9)) {
			//nothing. Number updated in the condition itself.
		} else {
			fprintf(stderr, "%s: Wrong Arguments.\n", argv[0]);
			return -2;
		}
	} else if (argc == 3) {
		if (!parseNumber(argv[2], &count, 9)) {
			fprintf(stderr, "%s: Wrong Arguments.\n", argv[0]);
			return -2;
					}
		if (strncmp(argv[1], "-f", 2)) {
			fprintf(stderr, "%s: Expected '-f' as the parameter", argv[0]);
		return -1;
			} else {
			useFuture = 1;
		}
	}

	if (useFuture == 1) {
		kprintf("Prod Cons Future\n");
		future_t *f_exclusive,*f_shared,*f_queue;

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
		   resume( create(future_prod, 1024, 20, "fprod4", 2, f_queue, 4) );
		   resume( create(future_prod, 1024, 20, "fprod5", 2, f_queue, 5) );
		   resume( create(future_prod, 1024, 20, "fprod6", 2, f_queue, 6) );
		      	}
	return 0;
}
