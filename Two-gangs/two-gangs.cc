#include <cstdio>
#include <iostream>

#include "UFS.h"

using std::string;

int main(void)
{
    int numOfTestCase , numOfPeople , numOfMessages;
    char notSure[] = "Not Sure Yet";
    char same[] = "Same Gang";
    char notSame[] = "Not Same Gang";

    scanf("%d" , &numOfTestCase);
    scanf("%d%d" , &numOfPeople , &numOfMessages);

    char MessageType;
    int firstPerson;
    int secondPerson;

    UFS ufs(numOfPeople);

    while(numOfTestCase--)
    {
        while(numOfMessages--)
        {
            std::cin >> MessageType >> firstPerson >> secondPerson;
            if(MessageType == 'A')
            {
                int pf = ufs.UFSFind(firstPerson);
                int ps = ufs.UFSFind(secondPerson);
                if(pf == ps)
                {
                    int rt = (ufs.rGangInfo_[firstPerson] -
                              ufs.rGangInfo_[secondPerson] + 2) % 2;

                    if(rt == 0)
                        printf("%s\n" , same);
                    else
                        printf("%s\n" , notSame);
                }
                else
                {
                    printf("%s\n" , notSure);
                }
            }
            else if(MessageType == 'D')
            {
                int pf = ufs.UFSFind(firstPerson);
                int ps = ufs.UFSFind(secondPerson);
                ufs.makeRelation(pf , ps);
            }
            else
            {
                printf("MessageType[A|D] is invalid\n");
                exit(-1);
            }
        }
    }
    return 0;
}