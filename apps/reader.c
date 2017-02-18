#include <xinu.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include <reader_writer.h>

void rand_delay2(int uS_max);

void rand_delay2(int uS_max)
{
	long random_number = (rand()*1000000) % (uS_max + 1);
	long num_mseconds = random_number/1000;	
	sleepms(num_mseconds);
}

void reader(int mutex, int roomEmpty, int readerNumber, int readCycles) {
	while(readArr[readerNumber] < readCycles){
	wait(mutex);
	readers = readers + 1;
	if(readers == 1){
		wait(roomEmpty);	
	}
	signal(mutex);
	
	readArr[readerNumber]++;
	printf("Reader %d %d\n", readerNumber, readArr[readerNumber]);
	
	rand_delay2(maxDelay);

	wait(mutex);
	readers = readers - 1;
	if(readers == 0){
		signal(roomEmpty);	
	}
	signal(mutex);
	}
}
