/* xsh_readers_writers.c - xsh_readers_writers */

#include <xinu.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include<reader_writer.h>
#include<reader.h>
#include<writer.h>

volatile int readers;
volatile int writers;
/*------------------------------------------------------------------------
 * xsh_readers_writers - Readers Writers Problem
 *------------------------------------------------------------------------
 */
shellcmd xsh_readers_writers(int nargs, char *args[]) {
	/*
	cmd usage: readers-writers <num writers> <num readers> <write cycles> <read cycles> <max delay>
	*/
	kprintf("Hello RW \n");

	int mutex;
	int roomEmpty;
	
	mutex = semcreate(1);
	roomEmpty = semcreate(1);

	int nWriters = atoi(args[1]);
	int nReaders = atoi(args[2]);

	int writeCycles = atoi(args[3]);
	int readCycles = atoi(args[4]);

	int maxDelay = atoi(args[5]);
	int i=1;
	for(i=1; i<=nReaders; i++){
		//create a reader process	
		resume(create(reader, 1024, 20, "reader", 4, mutex, roomEmpty, i, readCycles));	
	}

	for(i=1; i<=nWriters; i++){
		//create a writer process
		resume(create(writer, 1024, 20, "writer", 3, roomEmpty, i, writeCycles));
	}
	return 0;
}
