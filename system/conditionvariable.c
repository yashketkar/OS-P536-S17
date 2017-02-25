// struct cond_t {
//     proc next;  /* doubly linked list implementation of */
//     proc prev;  /* queue for blocked threads */ 
//     mutex mx; /*protects queue */
//   };
#include <xinu.h>
#include <conditionvariable.h>

int TestAndSet(int* lockPtr) {
    int oldValue;

    intmask	mask;			/* Saved interrupt mask		*/
	// int32	count;			/* Current sempahore count	*/

	mask = disable();

    // Start of atomic segment
    // The following statements should be interpreted as pseudocode for
    // illustrative purposes only.
    // Traditional compilation of this code will not guarantee atomicity, the
    // use of shared memory (i.e. not-cached values), protection from compiler
    // optimization, or other required properties.
    oldValue = *lockPtr;
    *lockPtr = LOCKED;
    // End of atomic segment


	restore(mask);

    return oldValue;
}