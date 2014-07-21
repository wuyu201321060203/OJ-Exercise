#include <stdio.h>

size_t strlen(char const* str)
{
    char const* s = str;
    for(; *s ; ++s){}
    return s - str;
}

int main(void)
{
    char str[] = "helloworld";
    printf("%d\n" , strlen(str));
    return 0;
}