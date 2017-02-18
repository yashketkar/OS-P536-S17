extern volatile int readers;
extern volatile int writers;
extern volatile int maxDelay;

extern volatile int* readArr;
extern volatile int* writeArr;

void reader(int, int, int, int);

void writer(int, int, int);