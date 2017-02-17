#include<readers_writers.h>
#include<writer.h>

void writer(int roomEmpty) {
	kprintf("Hello says Writer");
	wait(roomEmpty);
	//TODO: write op here
	signal(roomEmpty);
}
