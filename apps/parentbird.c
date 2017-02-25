#include <baby_bird.h>
// #include <conditionvariable.h>

// void parentbird(int mutexP, int mutexC, int fetch, int done) {
void parentbird(mutex_t* lock, cond_t* cvP, cond_t* cvC, int fetch) {
	int initial = 0;
	// kprintf("Lock outside address is %x \n", lock);
	// kprintf("fetch is %d\n", fetch);	
	// kprintf("Parent Bird pid is %d\n", getpid());
	while(1){
		// wait(mutexP);
		if(initial > 0)
		{
			cond_wait(cvP,lock);
		}
		initial++;
		// mutex_lock(lock);
		worms = worms + fetch;
		kprintf("Parent bird filled the dish with %d worms!\n", fetch);
		// mutex_unlock(lock);

		cond_signal(cvC);
		// signal(mutexC);
	}
}