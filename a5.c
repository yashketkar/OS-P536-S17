#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void rand_delay(int uS_max)
{
	/* Intializes random number generator */
	time_t t;
	srand((unsigned) time(&t));

	/* Generate the random number */
	int random_number = rand() % (uS_max + 1);
	int num_seconds = random_number/1000000;
	
	/* Print message and generate delay */
	printf("This program will exit in %d micro-seconds ~= %d seconds.\n",random_number,num_seconds);
	usleep(random_number);
}

int main()
{
	rand_delay(10000000);
	return 0;
}