/*
*       error.c
*       IJC-DU1 
*       Author : Pomsar Jakub
*       Organization : VUT FIT
*       Date : March 10, 2022
*       Compiled : gcc version 9.4.0 (Ubuntu 9.4.0-1ubuntu1~20.04)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "error.h"

void warning_msg(const char *fmt, ...)
{
    va_list list;
    va_start(list,fmt);
    vfprintf(stderr,fmt,list);
    va_end(list);
}

void error_exit(const char *fmt, ...)
{
    va_list list;
    va_start(list,fmt);
    vfprintf(stderr,fmt,list);
    va_end(list);
    exit(EXIT_FAILURE);
}
