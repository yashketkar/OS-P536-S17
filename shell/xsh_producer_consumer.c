/* xsh_producer_consumer.c - xsh_producer_consumer */

#include <xinu.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include<producer_consumer.h>
#include<producer.h>
#include<consumer.h>

volatile int buffer;

/*------------------------------------------------------------------------
 * xsh_producer_consumer - Producer Consumer Problem
 *------------------------------------------------------------------------
 */
shellcmd xsh_producer_consumer(int nargs, char *args[]) {
	/*
	cmd usage: producer_consumer <buffer size in bytes> <bytes to send> <max delay>
	*/
	
	buffer = atoi(args[1]);	

	int mutex;
	int items;
	int spaces;
	
	mutex = semcreate(1);
	items = semcreate(0);
	spaces = semcreate(buffer); //buffer size
	
	//create a producer process
	resume(create(producer, 1024, 20, "producer", 3, mutex, items, spaces));

	//create a consumer process
	resume(create(consumer, 1024, 20, "consumer", 3, mutex, items, spaces));

	return 0;
}
