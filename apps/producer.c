#include<producer_consumer.h>
#include<producer.h>

void producer(int mutex, int items, int spaces) {
	spaces.wait();
	
	mutex.wait();
	buffer = buffer + 1;	
	kprintf("Producer: %d\n", buffer);
	mutex.signal();
	
	items.signal();
}
