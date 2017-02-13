#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void rand_delay(int uS_max)
{
	int random_number = rand() % (uS_max + 1);
	printf("The random number is : %d \n",random_number);
	usleep(random_number);
}

int main()
{
	printf("This c program will exit in 1 seconds.\n");
	rand_delay(100000000);
	return 0;
}