#include <xinu.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include <reader_writer.h>

void rand_delay1(int uS_max);

void rand_delay1(int uS_max)
{
	long random_number = (rand()*1000000) % (uS_max + 1);
	long num_mseconds = random_number/1000;	
	sleepms(num_mseconds);
}

void writer(int roomEmpty, int writerNumber, int writeCycles) {
	while(writeArr[writerNumber] < writeCycles){

	wait(roomEmpty);

	writeArr[writerNumber]++;
	printf("Writer %d %d \n", writerNumber, writeArr[writerNumber]);	
	rand_delay1(maxDelay);

	signal(roomEmpty);

	}
}
