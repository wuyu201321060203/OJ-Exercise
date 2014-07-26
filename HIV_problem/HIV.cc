#include <stdio.h>

#include "UFS.h"

#define MAXSTU 30000
#define MAXCOMM 500

int main(void)
{
    UINT studentNum , communityNum;
    UINT memberNum , studentId;
    while( scanf("%d%d" , &studentNum , &communityNum) && studentNum > 0
           && communityNum > 0 )
    {
        if(studentNum > MAXSTU || communityNum > MAXCOMM)
        {
            printf("studentNum or communityNum is too big, \
                    please check and run again\n");
            return -1;
        }
        UFS ufs(studentNum);
        UINT firstId;
        for(int i = 0 ; i != communityNum  ; ++i)
        {
            scanf("%d%d" , &memberNum , &firstId);

            for(int j = 0 ; j != memberNum - 1 ; ++j)
            {
                scanf("%d" , &studentId);
                ufs.UFSUnion(firstId , studentId);
            }
        }
        printf("%d\n" , ufs.UFSGetSetSize(0));
    }
    return 0;
}