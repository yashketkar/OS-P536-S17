#include<producer_consumer.h>
#include<producer.h>


void producer(int mutex, int items, int spaces, int count) {
	int i=0;
	while(1){
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
	buffer = buffer + 1;	
	kprintf("Producer: %d\n", buffer);
	signal(mutex);
	
	signal(items);
	}
}