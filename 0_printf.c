#include "main.h"

int _printf(const char *format, ...){
    int char_count=0;
    va_list my_args;

    if (format == NULL){

        return (-1);
    }
    va_start(my_args, format);

    while(*format)
    {
        if (*format!='%'){
            write(1, format, 1);
            char_count++;
        }
        else
        {
            format++;
            if (*format=='\0')
                break;
            if(*format == '%')
            {
              write(1, format,1);
              char_count++;
            }
            else if(*format=='c')
            {
                char c = va_arg(my_args, int);
                write(1, &c , 1);
                char_count++;
            }
            else if(*format == 's'){
                char *str = va_arg(my_args, char*);
                int str_len=0;

                while(str[str_len] != '\0')
                    str_len++;

                write(1,str,str_len);
                char_count+=str_len;
            }
        }
        format++;
    }
    va_end(my_args);
    return char_count;
}
