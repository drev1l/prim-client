#include <stdarg.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * print debug messages to stdout if DEBUG is true
 */

int output (FILE *stream, const char *format, va_list args)
{
    int status = 0;
    struct tm *lt;
    time_t now;
    time (&now);
    lt = localtime (&now);

    fprintf (stream, "%04d-%02d-%02d %02d:%02d:%02d - ", 
        lt->tm_year + 1900,
        lt->tm_mon + 1,
        lt->tm_mday,
        lt->tm_hour,
        lt->tm_min,
        lt->tm_sec);
    status = vfprintf (stream, format, args);

    return status;
}

int debug (int level, char * format, ...)
{
    int status = 0;
    va_list args;

    if (level == 0 && DEBUG == 0) 
    {
        va_start (args, format);
        status = output (stdout, format, args);
        va_end (args);
    }

    if (level <= 1 && DEBUG >= 1) 
    {
        va_start (args, format);
        status = output (stdout, format, args);
        va_end (args);
    }

    if (level <= 2 && DEBUG >= 2) 
    {
        FILE *outfile;
        outfile = fopen ("prim_srv.log", "a");
        va_start (args, format);
        status = output (outfile, format, args);
        va_end (args);
        fclose (outfile);
    }

    return status;
}

