/* process_ring.h */

#define PROCESS_RING_EXIT_BAD_COUNT -1
#define PROCESS_RING_EXIT_BAD_ARGS -2

extern volatile int inbox[101];
extern volatile int ring[101];

void process_ring(int, int);