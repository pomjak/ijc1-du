/*
*       IJC-DU1 
*       Author : Pomsar Jakub
*       Organization : VUT FIT
*       Date : March 10, 2022
*       Compiled : gcc version 9.4.0 (Ubuntu 9.4.0-1ubuntu1~20.04)
*/
#include <stdarg.h>

#ifndef ERROR
#define ERROR
void warning_msg(const char *fmt);
void error_exit(const char *fmt);
#endif