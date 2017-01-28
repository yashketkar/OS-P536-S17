#include <process_ring.h>

void process_ring(int pid, int NUM_PROCESSES, int version) {
	int process_id = pid;
	while(inbox[0] > 0)
	{
		if(version ==1)
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
		else if (version == 2){
			if(pid == 0)
			{
				round+=1;
			}
			int val;
			val = (pid + 1) % NUM_PROCESSES;
			inbox[val] = inbox[pid]-1;
			kprintf("Ring Element %d : Round %d : Value : %d\n",process_id, round, inbox[process_id]);
			suspend(getpid());			
			resume(ring[val]);
		}
		else if (version == 3){
			if(pid == 0)
			{
				round+=1;
			}
			int val;
			val = (pid + 1) % NUM_PROCESSES;
			inbox[val] = inbox[pid];
			kprintf("Ring Element %d : Round %d : Value : %d\n",process_id, round, inbox[process_id]);
			resume(ring[val]);
			suspend(getpid());
		}
		else if (version == 4){
			if(pid == 0)
			{
				round+=1;
			}
			int val;
			val = (pid + 1) % NUM_PROCESSES;
			inbox[val] = inbox[pid]-1;
			kprintf("Ring Element %d : Round %d : Value : %d\n",process_id, round, inbox[process_id]);
			//suspend(getpid());
			int i;
			for(i=0;i<NUM_PROCESSES;i++)
			{
				resume(ring[i]);	
			}
		}
	}
	kprintf("ZERO!");
}