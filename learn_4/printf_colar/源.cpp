#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>



    void printf_red(char* s)
    {
        printf("\033[0m\033[1;31m%s\033[0m", s);
        printf("\n");
    }

    void printf_green(const char* s)
    {
        printf("\033[0m\033[1;32m%s\033[0m", s);
    }

    void printf_yellow(const char* s)
    {
        printf("\033[0m\033[1;33m%s\033[0m", s);
    }

    void printf_blue(const char* s)
    {
        printf("\033[0m\033[1;34m%s\033[0m", s);
    }

    void printf_pink(const char* s)
    {
        printf("\033[0m\033[1;35m%s\033[0m", s);
    }

    void printf_cyan(const char* s)
    {
        printf("\033[0m\033[1;36m%s\033[0m", s);
    }

    int main()
    {
        char i = '1';
        char tmp[2] = { i ,'\0'};
        printf_red(tmp);
        printf_green("Hello World.\n");
        printf_yellow("Hello World.\n");
        printf_blue("Hello World.\n");
        printf_pink("Hello World.\n");
        printf_cyan("Hello World.\n");
        return 0;
    }


