#include <process_ring.h>

void process_ring(int pid, int NUM_PROCESSES, int flag) {
	int process_id = pid;
	while(inbox[0] > 0)
	{
		if(pid == 0)
		{
			round+=1;
		}
		int val;
		val = (pid + 1) % NUM_PROCESSES;
		inbox[val] = inbox[pid]-1;
		kprintf("Ring Element %d : Round %d : Value : %d\n",process_id, round, inbox[process_id]);
		resume(ring[val]);
		suspend(getpid());
	}
}