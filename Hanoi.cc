#include <stdio.h>
#include <stdlib.h>

void Hanoi(int slice, char from , char middle , char to)
{
    if(slice== 1)
    {
        printf("%d from %c to %c\n" , slice , from , to);
        return;
    }
    Hanoi(slice - 1 , from , to , middle);
    printf("%d from %c to %c\n" , slice , from , to);
    Hanoi(slice - 1 , middle , from , to);
}

int main(int argc , char** argv)
{
    printf("%d\n" , ( 1 << ( atoi( argv[1] ) ) ) - 1);
    Hanoi( atoi(argv[1]) , 'A' , 'B' , 'C' );
    return 0;
}