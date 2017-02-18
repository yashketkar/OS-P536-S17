/* xsh_producer_consumer.c - xsh_producer_consumer */

#include <xinu.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include<producer_consumer.h>
// #include<producer.h>
// #include<consumer.h>

volatile unsigned char* buffer;
// volatile int buffer;
volatile int maxDelay;
volatile unsigned char counter;
volatile int n;
volatile int in;
volatile int out;
volatile int count;

/*------------------------------------------------------------------------
 * xsh_producer_consumer - Producer Consumer Problem
 *------------------------------------------------------------------------
 */
shellcmd xsh_producer_consumer(int nargs, char *args[]) {
	/*
	cmd usage: producer_consumer <buffer size in bytes> <bytes to send> <max delay>
	*/

	counter = 0x00;
	n = atoi(args[1]);
	in =0;
	out=0;

	buffer = getmem(atoi(args[1]));
	// buffer = atoi(args[1]);
	int count;
	count = atoi(args[2]);
	
	maxDelay = atoi(args[3]);	

	int mutex;
	int items;
	int spaces;
	
	mutex = semcreate(1);
	spaces = semcreate(atoi(args[1])); //buffer size
	items = semcreate(0);
	
	//create a producer process
	resume(create(producer, 1024, 20, "producer", 4, mutex, items, spaces, count));

	//create a consumer process
	resume(create(consumer, 1024, 20, "consumer", 4, mutex, items, spaces, count));

	return 0;
}
