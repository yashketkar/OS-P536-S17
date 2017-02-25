#include <conditionvariable.h>

// extern volatile unsigned char* buffer;
// extern volatile int maxDelay;
extern volatile int worms;
extern volatile int done;
// extern volatile int in;
// extern volatile int out;
// extern volatile int sent;
// extern volatile int received;
// extern volatile unsigned char counter;

void parentbird(mutex_t*,cond_t*,cond_t*,int);
void babybird(mutex_t*, cond_t*, cond_t*, int, int, int);

// void parentbird(int, int, int, int);
// void babybird(int, int, int, int, int );