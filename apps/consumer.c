#include<producer_consumer.h>
#include<consumer.h>

void consumer(int mutex, int items, int spaces, int count) {
	while(1){	
	wait(items);
	
	wait(mutex);
	//while(count > 0){
	   //kprintf("Consumer: %d\n", count);
	   //count = count - 1;	
	//}
	buffer = buffer - 1;
	kprintf("Consumer: %d\n", buffer);
	signal(mutex);

	signal(spaces);
	//rand_delay(maxDelay);
	}
}
