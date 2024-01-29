#ifndef MAIN_H
#define MAIN_H


#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>


#define BUFF_SIZE 1024
#include "_strlen.c"
#include "stringfromint.c"
#include "rev_string.c"
#include "print_unsigned_int.c"
#include "dec2binstring.c"
#include "dec2octalstring.c"
#include "dec2hexstrin.c"
#include "dec2HEXstring.c"



int _strlen(char *s);
void stringfromint(int no, char *str);
void dec2binstring
	(unsigned int no, int *chars_count, char *buffer, int *buffer_indx);
void rev_string(char *s, int b);
void print_unsigned_int
	(int no, int *chars_count, char *buffer, int *buffer_indx);
void dec2octalstring
	(unsigned int no, int *chars_count, char *buffer, int *buffer_indx);
void dec2hexstring
	(unsigned int no, int *chars_count, char *buffer, int *buffer_indx);
void dec2HEXstring
	(unsigned int no, int *chars_count, char *buffer, int *buffer_indx);

int _printf(const char *format, ...);


int _strlen(char *s);




#endif

