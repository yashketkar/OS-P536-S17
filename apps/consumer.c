#include<producer_consumer.h>
#include<consumer.h>

void consumer(int mutex, int items, int spaces) {
	items.wait();
	
	mutex.wait();
	buffer = buffer - 1;
	kprintf("Consumer: %d\n", buffer);
	mutex.signal();

	spaces.signal();
}
