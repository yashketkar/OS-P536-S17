#include <future.h>

extern volatile int n;

extern sid32 produced, consumed;

uint future_prod(future_t*, int);
uint future_cons(future_t*);
