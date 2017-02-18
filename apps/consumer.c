#include<producer_consumer.h>
// #include<consumer.h>

void consumer(int mutex, int items, int spaces, int count) {
	while(1){
	wait(items);
	
	wait(mutex);
	//while(count > 0){
	   //kprintf("Consumer: %d\n", count);
	   //count = count - 1;	
	
	//}

	unsigned char item = buffer[out];
	out = (out+1)%n;
	kprintf("Consumer: %d\n", item);


	// buffer = buffer - 1;
	signal(mutex);

	signal(spaces);
	//rand_delay(maxDelay);
	}
}
