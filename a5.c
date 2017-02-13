#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void rand_delay(int uS_max)
{
	int random_number = rand() % (uS_max + 1);
	printf("This program will exit in %d seconds.\n",random_number);
	usleep(random_number);
}

int main()
{
	rand_delay(100000000);
	return 0;
}