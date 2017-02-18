#include<producer_consumer.h>
// #include<producer.h>


void producer(int mutex, int items, int spaces, int count) {
	while(count > 0){
	// rand_delay(maxDelay);
	wait(spaces);
	
	wait(mutex);
	/*while(count > 0){
	    for(i=0; i<sizeof(buffer); i++){
	    	kprintf("Producer: %d \n", count);
		buffer[i] = count;
	    }
	    count = count - 1;	
	}*/
	// buffer = buffer + 1;
	buffer[in] = counter;
	kprintf("Producer: %d\n", buffer[in]);
	counter = (counter+1)%0xff;
	in = (in + 1)%n;

	signal(mutex);
	
	signal(items);
	}
}
