#include <stdio.h>
#include <cassert>
#include <cstring>
#include <limits.h>

int atoi(char const* str)
{
    assert(str);
    int num = 0;
    unsigned int i = 0;
    int sign = 1;

    while(str[i] == ' ')++i;
    if(str[i] == '+' || str[i] == '-')
    {
        if(str[i] == '-')
            sign = -1;
        ++i;
    }
    unsigned int len = strlen(str);
    for( ; i != len ; ++i)
    {
        if(str[i] < '0' || str[i] > '9')
            break;
        if(num > INT_MAX/10 || (num == INT_MAX/10 && str[i] > INT_MAX%10))
            return sign == -1 ? INT_MIN : INT_MAX;
        num = num * 10 + (str[i] - '0');
    }
    return num * sign;
}

int main(int argc , char** argv)
{
    if(argc == 2)
        printf("%d\n" , atoi(argv[1]));
    else
        printf("invalid\n");
    return 0;
}