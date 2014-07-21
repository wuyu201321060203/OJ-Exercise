#include <stdio.h>
#include <cassert>

char* strcpy(char* to , char const* from)
{
    assert(to != NULL && from != NULL);
    char* p = to;
    while((*p++ = *from++))
    {
    }
    return to;
}

int main(void)
{
    char from[] = "hello";
    char to[] = "worldworld";
    strcpy(from , to);
    printf("%s\n" , from);
    return 0;
}