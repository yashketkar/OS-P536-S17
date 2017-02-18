extern volatile unsigned char* buffer;
extern volatile int maxDelay;
extern volatile int n;
extern volatile int in;
extern volatile int out;
extern volatile unsigned char counter;
void rand_delay(int uS_max);
void producer(int, int, int, int);
void consumer(int, int, int, int);