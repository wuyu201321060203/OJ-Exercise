#include <stdio.h>
#include <vector>
#include <cstdlib>

void convert_base(int decimal , int const d) //d<=16
{
    std::vector<int> result;
    while(decimal > 0)
    {
        result.push_back(decimal%d);
        decimal /= d;
    }
    for(auto i = result.rbegin() ; i != result.rend() ; ++i)
        printf("%d" , *i);
    printf("\n");
}

int main(int argc , char* argv[])
{
    convert_base(atoi(argv[1]) , atoi(argv[2]));
    return 0;
}