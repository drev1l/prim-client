/* errexit.c - errexit */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
// #include "debug.c"

/*------------------------------------------------------------------------
 * errexit - print an error message and exit
 *------------------------------------------------------------------------
 */
int
errexit(const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	output (stderr, format, args);
//	vfprintf(stderr, format, args);
	va_end(args);
	exit(1);
}

