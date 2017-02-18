#include <xinu.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

volatile int NUM_PHILOSOPHERS;
volatile int NUM_CYCLES;
volatile int MAX_DELAY;

sid32 footman;
sid32* forks;
int* times_eaten;

void philosopher(int n);
void think(int n);
void eat(int n);

void rand_delay(int uS_max)
{
	long random_number = (rand()*1000000) % (uS_max + 1);
	long num_mseconds = random_number/1000;	
	sleepms(num_mseconds);
}

void createPhilosophers() {
	footman = semcreate(4);

	times_eaten = getmem(sizeof(int) * NUM_PHILOSOPHERS);
	forks = getmem(sizeof(sid32) * NUM_PHILOSOPHERS);

	int i = 0;
	for (i =0; i < NUM_PHILOSOPHERS; i++) {
		times_eaten[i] = 0;
	}

	i = 0;
	for (i =0; i < NUM_PHILOSOPHERS; i++) {
		forks[i] = semcreate(1);
	}

	for (i = 0; i < NUM_PHILOSOPHERS; i++) {
		resume(create(philosopher, 4096, 50, "philosopher", 1, i));
	}

}

void philosopher(int n) {
	while (times_eaten[n]<=NUM_CYCLES) {
    think(n);
	wait(footman);
	wait(forks[n]);
	wait(forks[(n+1)%NUM_PHILOSOPHERS]);
    eat(n);
    signal(forks[n]);
	signal(forks[(n+1)%NUM_PHILOSOPHERS]);
	signal(footman);
	}
}

void think(int n) {
		printf("Philosopher %d thinking %d\n", n, times_eaten[n]);
		rand_delay(MAX_DELAY);
}

void eat(int n) {
		printf("Philosopher %d eating %d\n", n, times_eaten[n]);
		times_eaten[n]++;
		rand_delay(MAX_DELAY);
}

shellcmd xsh_dining_philosophers(int nargs, char *args[])
{
	NUM_PHILOSOPHERS = atoi(args[1]);
	NUM_CYCLES = atoi(args[2]);
	MAX_DELAY = atoi(args[3]);

	resume(create(createPhilosophers, 4096, 50, "Initialize Processes", 0, 0));

	return 0;
}