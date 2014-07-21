#include <stdio.h>
#include <cassert>
#include <cstring>

char const* strStr(char const* haystack , char const* needle)
{
    assert(haystack);
    if(needle == NULL)
        return haystack;

    char const* end = haystack + strlen(needle);
    char const* p1 = haystack;
    char const* p1_old = p1;
    char const* p2 = needle;
    size_t len = strlen(haystack);

    for( ; end -  haystack != len + 1 ; ++end)
    {
        while(*p2 && *p1)
        {
            if(!(*p1 == *p2))
                break;
            else
            {
                ++p1;
                ++p2;
            }
        }
        if(!(*p2))
        {
            return p1_old;
        }
        p1 = ++p1_old;
        p2 = needle;
    }

    return NULL;
}

int main(void)
{
    char haystack[] = "helloworld";
    char needle[] = "sed";
    printf("%s\n" , strStr(haystack , needle));
    return 0;
}