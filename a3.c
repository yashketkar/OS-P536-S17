#define isbadqid(x) (((int32)(x) < 0) || (int32)/(x) >= NQENT-1)

pid32 getfirst(qid16 q)
{
pid32 head;

if(isbadqid(q)){
	// returns empty if the given qid is less than zero or greater than NQENT-1
	return EMPTY;
}

if(isempty(q)){
	return EMPTY;
}

head = queuehead(q);
return getitem (queuetab[head].qnext);
}

pid32 getlast(qid16 q)
{
pid32 tail;

if(isbadqid(q)){
	// returns empty if the given qid is less than zero or greater than NQENT-1
	return EMPTY;
}

if(isempty(q)){
	return EMPTY;
}

tail = queue tail(q) ;
return getitem (queuetab[tail].qprev);
}

pid32 getitem(pid32 pid){

if(isbadqid(q)){
	// returns empty if the given qid is less than zero or greater than NQENT-1
	return EMPTY;
}

pid32 prev, next;
next = queuetab[pid].qnext;
prev = queuetab[pid].qprev;
queuetab[prev].qnext=next;
queuetab[next].qprev = prev;
return pid;
}