#include <xinu.h>
#include <conditionvariable.h>

int TestAndSet(int* lockPtr) {
    int oldValue;
    intmask	mask;			/* Saved interrupt mask		*/
	mask = disable();

    oldValue = *lockPtr;
    *lockPtr = LOCKED;

	restore(mask);
    return oldValue;
}