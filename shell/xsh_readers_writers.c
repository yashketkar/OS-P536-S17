/* xsh_readers_writers.c - xsh_readers_writers */

#include <xinu.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/*------------------------------------------------------------------------
 * xsh_readers_writers - Readers Writers Problem
 *------------------------------------------------------------------------
 */
shellcmd xsh_readers_writers(int nargs, char *args[]) {
	/*
	cmd usage: readers-writers <num writers> <num readers> <write cycles> <read cycles> <max delay>
	*/
	kprintf("Hello RW");

	return 0;
}
