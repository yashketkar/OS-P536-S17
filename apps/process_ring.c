#include <process_ring.h>

int process_id;
int round_no;

void process_ring(int pid) {
	process_id = pid;
	round_no = 0;

	kprintf("1. Countdown: %d\n\n", *(inbox+process_id));


	while(*(inbox+process_id) > 0)
	{

		kprintf("Process ID : %d\n", process_id);
		kprintf("Countdown: %d\n\n", *(inbox+process_id));

		if(process_id == 3)
		{
		*(inbox) = *(inbox+process_id) -1;	
		}
		else
		{
		*(inbox+process_id+1) = *(inbox+process_id) -1;	
		}

	}
}