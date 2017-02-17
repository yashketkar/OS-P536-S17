#include<readers_writers.h>
#include<reader.h>

void reader(int mutex, int roomEmpty) {
	kprintf("Hello says Reader");
	wait(mutex);
	readers = readers + 1;
	if(readers == 1){
		wait(roomEmpty);	
	}
	signal(mutex);
	
	//TODO: read op here

	wait(mutex);
	readers = readers - 1;
	if(readers == 0){
		signal(roomEmpty);	
	}
	signal(mutex);
}
