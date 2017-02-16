#include<producer_consumer.h>
#include<producer.h>

void producer(int mutex, int items, int spaces) {
	wait(spaces);
	
	wait(mutex);
	buffer = buffer + 1;	
	kprintf("Producer: %d\n", buffer);
	signal(mutex);
	
	signal(items);
}
