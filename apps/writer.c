#include<reader_writer.h>
#include<writer.h>

void writer(int roomEmpty, int writerNumber, int writeCycles) {
	kprintf("Hello says Writer\n");
	wait(roomEmpty);

	//TODO: write op here
	int i = 1;
	for(i=1; i<=writeCycles; i++){
		kprintf("Writer %d %d \n", writerNumber, i);	
	}

	signal(roomEmpty);
}
