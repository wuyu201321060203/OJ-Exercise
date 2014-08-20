#include <strings.h>
#include <stdio.h>

#define MAXN 1000001

struct node_t
{
    int left , right;
    int count;
};

node_t g_Array[MAXN * 4];

int sum = 0;

#define L(t) (t << 1)
#define R(t) ( (t << 1) + 1)

#define max(a , b) ( (a > b ) ? (a) : (b) )
#define min(a , b) ( (a < b ) ? (a) : (b) )

void build(int root , int left , int right)
{
    g_Array[root].left = left;
    g_Array[root].right = right;
    g_Array[root].count = right - left + 1;


    if(left == right) return;

    int middle = (( left ^ right ) >> 1) + ( left & right );
    build( L(root) , left , middle );
    build( R(root) , middle + 1 , right);
}

int deleteNode(int root , int NodeNum)
{
    g_Array[root].count--;
    if(g_Array[root].left == g_Array[root].right)
    {
        printf("%d " , g_Array[root].left);
        return g_Array[root].left;
    }
    if(NodeNum <= g_Array[L(root)].count) return deleteNode(L(root) , NodeNum);
    else return deleteNode(R(root) , NodeNum - g_Array[L(root)].count);
}

int getCount(int root , int i)
{
    int left = g_Array[root].left;
    int right = g_Array[root].right;
    if(right <= i) return g_Array[root].count;
    int middle = (( left ^ right ) >> 1) + ( left & right );
    if(i > middle)
    {
        return g_Array[L(root)].count + getCount(R(root) , i);
    }
    else
    {
        return getCount(L(root) , i);
    }
}

int main(void)
{
    int n , m;
    scanf("%d%d" , &n , &m);
    build(1 , 1 , n);
    int j = 0;
    int realNum;
    for(int i = 0 ; i != n ; ++i)
    {
       j += m;
       j = j % g_Array[1].count;
       if(j == 0) j = g_Array[1].count;
       realNum = deleteNode(1 , j);
       j = getCount(1 , realNum);
    }
    return 0;
}
