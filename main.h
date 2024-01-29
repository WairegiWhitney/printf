#ifndef MAIN_H
#define MAIN_H


#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define BUFF_SIZE 1024

int _strlen(char *s);
void stringfromint(int no, char *str);
void dec2binstring(unsigned int no, int *chars_count);
void rev_string(char *s, int b);
void print_unsigned_int(int no, int *chars_count);
void dec2octalstring(unsigned int no, int *chars_count);
void dec2hexstring(unsigned int no, int *chars_count);
void dec2HEXstring(unsigned int no, int *chars_count);

int _printf(const char *format, ...);


int _strlen(char *s);




#endif

