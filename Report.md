# Assignment 2

### Brief Working


### Input Validations
- Checked for --help param
- Checked for run without parameters and if found, run default.
- Checked if even number of args, report error.
- Checked for more or less number of args than expected.
- Checked for correct parameter names.
- Checked for number of processes - limited it to be max 100.
- Checked for out of range param values - reassigned to default.

### Outputs
- work
```
xsh $ process_ring
xsh $ Ring Element 0 : Round 1 : Value : 20
Ring Element 1 : Round 1 : Value : 19
Ring Element 2 : Round 1 : Value : 18
Ring Element 3 : Round 1 : Value : 17
Ring Element 0 : Round 2 : Value : 16
Ring Element 1 : Round 2 : Value : 15
Ring Element 2 : Round 2 : Value : 14
Ring Element 3 : Round 2 : Value : 13
Ring Element 0 : Round 3 : Value : 12
Ring Element 1 : Round 3 : Value : 11
Ring Element 2 : Round 3 : Value : 10
Ring Element 3 : Round 3 : Value : 9
Ring Element 0 : Round 4 : Value : 8
Ring Element 1 : Round 4 : Value : 7
Ring Element 2 : Round 4 : Value : 6
Ring Element 3 : Round 4 : Value : 5
Ring Element 0 : Round 5 : Value : 4
Ring Element 1 : Round 5 : Value : 3
Ring Element 2 : Round 5 : Value : 2
Ring Element 3 : Round 5 : Value : 1
ZERO!
```

- hang
```
xsh $ process_ring -v hang
Cmd Arg: -v
Ring Element 0 : Round 6 : Value : 20
```

- loop
```
Ring Element 2 : Round 6101 : Value : 20
Ring Element 3 : Round 6101 : Value : 20
Ring Element 0 : Round 6102 : Value : 20
Ring Element 1 : Round 6102 : Value : 20
Ring Element 2 : Round 6102 : Value : 20
Ring Element 3 : Round 6102 : Value : 20
Ring Element 0 : Round 6103 : Value : 20
Ring Element 1 : Round 6103 : Value : 20
Ring Element 2 : Round 6103 : Value : 20
Ring Element 3 : Round 6103 : Value : 20
Ring Element 0 : Round 6104 : Value : 20
Ring Element 1 : Round 6104 : Value : 20
Ring Element 2 : Round 6104 : Value : 20
Ring Element 3 : Round 6104 : Value : 20
Ring Element 0 : Round 6105 : Value : 20
Ring Element 1 : Round 6105 : Value : 20
Ring Element 2 : Round 6105 : Value : 20
Ring Element 3 : Round 6105 : Value : 20
Ring Element 0 : Round 6106 : Value : 20
Ring Element 1 : Round 6106 : Value : 20
Ring Element 2 : Round 6106 : Value : 20
Ring Element 3 : Round 6106 : Value : 20
Ring Element 0 : Round 6107 : Value : 20
Ring Element 1 : Round 6107 : Value : 20
Ring Element 2 : Round 6107 : Value : 20
Ring Element 3 : Round 6107 : Value : 20
```

- chaos
```
Ring Element 0 : Round 99 : Value : 4
Ring Element 0 : Round 100 : Value : 4
Ring Element 2 : Round 100 : Value : 2
Ring Element 2 : Round 100 : Value : 2
Ring Element 2 : Round 100 : Value : 2
Ring Element 2 : Round 100 : Value : 2
Ring Element 2 : Round 100 : Value : 2
Ring Element 2 : Round 100 : Value : 2
Ring Element 2 : Round 100 : Value : 2
Ring Element 2 : Round 100 : Value : 2
Ring Element 2 : Round 100 : Value : 2
Ring Element 2 : Round 100 : Value : 2
Ring Element 1 : Round 100 : Value : 3
Ring Element 1 : Round 100 : Value : 3
Ring Element 1 : Round 100 : Value : 3
Ring Element 1 : Round 100 : Value : 3
Ring Element 1 : Round 100 : Value : 3
Ring Element 1 : Round 100 : Value : 3
Ring Element 1 : Round 100 : Value : 3
Ring Element 1 : Round 100 : Value : 3
Ring Element 1 : Round 100 : Value : 3
Ring Element 1 : Round 100 : Value : 3
Ring Element 3 : Round 100 : Value : 1
```

- Note: Output has been truncated. Please run the program to see entire output and the different variants.

### Contributions
Yash Ketkar (yketkar@indiana.edu)
- Implemented Core Logic
- Designed Workflow

Tejas Kumthekar (tejakumt@indiana.edu)
- Implemented Input Validations
- Worked on Report

### Follow-up Answers

- Why does your program hang? What is the name of this behavior in an operating system? 
An individual process or thread can get stuck due to many possible reasons like waiting for a resource, deadlocks, badly written program logic (infinite loops etc), race conditions, hardware issues etc. 
This is called a hang. A system hang can be broadly classified into an infinite loop or an indefinite wait.
(Ref. http://www.cse.unsw.edu.au/~yueli/papers/issre12.pdf) 

- Why does your program go into an infinite loop? What is the name of this behavior in an operating system?
A program can go into an infinite loop either because it never meets a terminating condition, or it fires itself continuously (recursively).
In this case we are not decrementing the countdown, and thus the stopping condition is never met,resulting in  an infinite loop.

- Why does your program print numbers out of order? What is the name of this behavior in an operating system? There is no synchronization between the processes, and since all of them run parallely, it results in a race condition. Xinu's resched makes the selection according to the scheduling policy - 'At any time, the highest priority eligible process is executing. Among
processes with equal priority scheduling is round-robin.'

- What property of Xinu allows the working version of your program to print values in the correct order? Xinu has two functions - resume and suspend. For each of these, we can specify the process ID and resume or suspend the process accordingly. Thus, Resume and Suspend allows to print values in a correct order.