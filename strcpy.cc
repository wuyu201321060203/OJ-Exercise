#include <stdio.h>
#include <cassert>

char* strcpy(char* to , char const* from)
{
    assert(to != NULL && from != NULL);
    char* p = to;
    while( (*p++ = *from++) != '\0')
    {
    }
    return to;
}

int main(void)
{
    char from[] = "hello";
    char to[] = "worldhello";
    strcpy(to , from);
    printf("%s\n" , to);
    return 0;
}