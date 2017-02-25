#include <babybird.h>

void baby(int babyID, int wormsEat) {

	while(wormsEat > 0){
		//if worm pool gets empty
		if(wormsPool == 0){
			globalCV->val = false;
			cond_signal(globalCV);
		}

		//eat a worm
		if(!globalCV->val){
			printf("Baby bird %d ate a worm! (%d more left to eat)\n", babyID, wormsEat);
			wormsEat--;
			wormsPool--;	
		}
	}

	//print final message
	printf("Baby bird %d finished eating \n", babyID);

	return;
}
