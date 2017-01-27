/* process_ring.h */

#define PROCESS_RING_EXIT_BAD_COUNT -1
#define PROCESS_RING_EXIT_BAD_ARGS -2

extern volatile int inbox[4];

void process_ring(int);