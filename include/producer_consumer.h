extern volatile int buffer;
extern volatile int maxDelay;
void rand_delay(int uS_max);
void producer(int, int, int, int);
void consumer(int, int, int, int);