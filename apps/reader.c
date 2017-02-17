#include<reader_writer.h>
#include<reader.h>

void reader(int mutex, int roomEmpty, int readerNumber, int readCycles) {
	kprintf("Hello says Reader\n");
	wait(mutex);
	readers = readers + 1;
	if(readers == 1){
		wait(roomEmpty);	
	}
	signal(mutex);
	
	//TODO: read op here
	int i = 1;
	for(i=1; i<=readCycles; i++){
		kprintf("Reader %d %d \n", readerNumber, i);	
	}

	wait(mutex);
	readers = readers - 1;
	if(readers == 0){
		signal(roomEmpty);	
	}
	signal(mutex);
}
