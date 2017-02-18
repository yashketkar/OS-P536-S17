/* xsh_producer_consumer.c - xsh_producer_consumer */

#include <xinu.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include<producer_consumer.h>
#include<producer.h>
#include<consumer.h>

volatile char* buffer;

/*------------------------------------------------------------------------
 * xsh_producer_consumer - Producer Consumer Problem
 *------------------------------------------------------------------------
 */
shellcmd xsh_producer_consumer(int nargs, char *args[]) {
	/*
	cmd usage: producer_consumer <buffer size in bytes> <bytes to send> <max delay>
	*/
	
	buffer = getmem(atoi(args[1]));
	int count;
	count = atoi(args[2]);
	int maxDelay;
	maxDelay = atoi(args[3]);	

	int mutex;
	int items;
	int spaces;
	
	mutex = semcreate(1);
	items = semcreate(0);
	spaces = semcreate(atoi(args[1])); //buffer size
	
	//create a producer process
	resume(create(producer, 1024, 20, "producer", 3, mutex, items, spaces, count));

	//create a consumer process
	resume(create(consumer, 1024, 20, "consumer", 3, mutex, items, spaces, count));

	return 0;
}
