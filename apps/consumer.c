#include<producer_consumer.h>
#include<consumer.h>

void consumer(int mutex, int items, int spaces) {
	wait(items);
	
	wait(mutex);
	buffer = buffer - 1;
	kprintf("Consumer: %d\n", buffer);
	signal(mutex);

	signal(spaces);
}
