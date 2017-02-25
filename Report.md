# How the program works.

Here I have created 6 system calls as mentioned in the assignment. The 3 methods are for mutex and 3 for the
condition variables. The mutex implementation is using the Test-and-Set operation which is implemented in the system calls.
I have used the mutex implementation for creating the implementation of the condition variables.
The condition variable contains a queue of the process-ids and a mutex. This queue maintains the process in the condition variable.

For the baby bird program, I have done the follows:
In this program the various arguments are first taken from the command line. Then we create a parent process and num_babies 
number of baby bird processes. These processes are then called one after the other using the condition variable queue.
In case the number of worms are 0 and are finished, then we use the condition variable to signal the parent bird process.
The parent bird then updates the worms value and uses another condition variable to signal the baby bird processes.

# What is starvation? Is this protocol starvation-free?



# What is deadlock? Is this protocol deadlock-free?
