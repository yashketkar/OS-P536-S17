#include <process_ring.h>

void process_ring(int pid) {
	int process_id;
	process_id = pid;//getpid();

	kprintf("inbox %d\n\n", inbox[process_id]);
	kprintf("getpid : %d\n\n", getpid());	

	while(inbox[0]>0)
	{
		if(process_id == 3)
		{
		inbox[0] = inbox[process_id] - 1;
		// kprintf("getpid : %d\n\n", getpid());	
		// kprintf("process_id : %d\n\n", process_id);
		kprintf("Countdown: %d\n\n",inbox[process_id]);
		// resume(getpid(2)+1);
		// suspend(getpid());
		}
		else
		{
		inbox[process_id+1] = inbox[process_id] - 1;
		// kprintf("getpid : %d\n\n", getpid());	
		// kprintf("process_id : %d\n\n", process_id);	
		kprintf("Countdown: %d\n\n",inbox[process_id]);

		}
		// yield();
		int val;
		val = (pid + 1) % 4;
		resume(ring[val]);
		suspend(getpid());

	}


//	*(inbox+) = *(inbox+process_id) -1;

	// while(*(inbox) > 0)
	// {
	// 	kprintf("Process ID : %d\n", process_id);
	// 	kprintf("Countdown: %d\n\n", *(inbox+process_id));

	// 	if(process_id == 3)
	// 	{
	// 	*(inbox) = *(inbox+process_id) - 1;	
	// 	kprintf("process_id is %d\n\n", process_id);
	// 	kprintf("Process 3 and inbox value is %d\n\n", *(inbox));
	// 	}
	// 	else
	// 	{
	// 	*(inbox+process_id+1) = *(inbox+process_id) -1;
	// 	}

	// }
}