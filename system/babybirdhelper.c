#include <xinu.h>
#include <conditionvariable.h>

void insertinQueue(cond_t* cv, pid32 parentid)
{
	cv->queue[++cv->rear] = parentid;
}