/* xsh_readers_writers.c - xsh_readers_writers */

#include <xinu.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include<readers_writers.h>
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
	kprintf("Hello RW");

	int mutex;
	int roomEmpty;
	
	mutex = semcreate(1);
	roomEmpty = semcreate(1);

	//create a reader process
	resume(create(reader, 1024, 20, "reader", 2, mutex, roomEmpty));

	//create a writer process
	resume(create(writer, 1024, 20, "writer", 1, roomEmpty));

	return 0;
}
