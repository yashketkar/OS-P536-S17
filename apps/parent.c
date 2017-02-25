#include <babybird.h>

void parent(int wormsFetch) {

	//if global condition variable is false
	while(!globalCV->val);

	//fill the dish with worms
	wormsPool = wormsFetch;

	//print message
	printf("Parent bird filled the dish with %d worms!\n", wormsFetch);
	
	return;
}
