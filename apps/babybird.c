#include <baby_bird.h>
// #include <conditionvariable.h>

void babybird(mutex_t* lock, cond_t* cvP, cond_t* cvC, int eat, int birdindex, int done) {
// void babybird(int mutexP, int mutexC, int eat, int birdindex, int done) {
	int eaten = 0;
	int initial = 0;
	while(eaten<eat){
		 if(initial > 0){
 			cond_wait(cvC, lock);
		 }
		initial++;
		mutex_lock(lock);
		worms = worms - 1;
		eaten = eaten + 1;
		kprintf("Baby bird %d ate a worm! (%d total)\n", birdindex, eaten);
		if(worms == 0){
			kprintf("Plate is now empty.\n");
			cond_signal(cvP);
		}
		else {

		}
		mutex_unlock(lock);
		cond_signal(cvC);
	}
}