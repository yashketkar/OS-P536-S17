/* xsh_readers_writers.c - xsh_readers_writers */

#include <xinu.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include <reader_writer.h>

volatile int readers;
volatile int writers;
volatile int maxDelay;

volatile int* readArr;
volatile int* writeArr;
/*------------------------------------------------------------------------
 * xsh_readers_writers - Readers Writers Problem
 *------------------------------------------------------------------------
 */
shellcmd xsh_readers_writers(int nargs, char *args[]) {
	/*
	cmd usage: readers-writers <num writers> <num readers> <write cycles> <read cycles> <max delay>
	*/
	printf("Hello RW \n");

	int mutex;
	int roomEmpty;
	
	mutex = semcreate(1);
	roomEmpty = semcreate(1);

	int nWriters = atoi(args[1]);
	int nReaders = atoi(args[2]);

	writeArr = getmem(sizeof(int) * nWriters);
	readArr = getmem(sizeof(int) * nReaders);

	int writeCycles = atoi(args[3]);
	int readCycles = atoi(args[4]);

	maxDelay = atoi(args[5]);
	int i=0;
	for(i=0; i<nReaders; i++){
		//create a reader process
		resume(create(reader, 4096, 20, "reader", 4, mutex, roomEmpty, i, readCycles));	
	}

	for(i=0; i<nWriters; i++){
		//create a writer process
		resume(create(writer, 4096, 20, "writer", 3, roomEmpty, i, writeCycles));
	}
	return 0;
}
