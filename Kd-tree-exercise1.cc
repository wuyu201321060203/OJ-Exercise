#include <strings.h>
#include <stdio.h>

#define MAXN 1000001

struct node_t
{
    int left , right;
    int sum;
};

int g_Input[MAXN];
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

    if(left == right)
    {
        g_Array[root].sum = g_Input[left];
        return;
    }

    int middle = (( left ^ right ) >> 1) + ( left & right );
    build( L(root) , left , middle );
    build( R(root) , middle + 1 , right);
    g_Array[root].sum = g_Array[L(root)].sum + g_Array[R(root)].sum;
}

void query(int root , int left , int right)
{
    if(g_Array[root].left == left && g_Array[root].right == right)
    {
        sum += g_Array[root].sum;
        return;
    }

    int middle = (( g_Array[root].left ^ g_Array[root].right ) >> 1) +
                 ( g_Array[root].left & g_Array[root].right );
    if(right <= middle) query( L(root) , left , right);
    else if(left > middle) query( R(root) , left , right);
    else
    {
        query( L(root) , left , middle);
        query( R(root) , middle + 1 , right);
    }
}

void add(int root , int pos , int addend)
{
    g_Array[root].sum += addend;
    int left = g_Array[root].left;
    int right = g_Array[root].right;
    if(left == right && left == pos)
        return;
    int middle = (( left ^ right ) >> 1) + ( left & right );
    if(pos <= middle) add( L(root) , pos , addend);
    else add( R(root) , pos , addend );
}

int main()
{
    int n, q, i;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &g_Input[i]);
    scanf("%d", &q);
    bzero(g_Array , sizeof g_Array);
    build(1, 1, n);
    while (q--)
    {
        int type , a, b;
        scanf("%d%d%d", & type , &a, &b);
        if(type == 1) add(1 , a , b);
        else if(type == 2)
        {
            query(1, a, b);
            printf("%d\n", sum);
            sum = 0;
        }
        else printf("invalid operation\n");
    }
    return 0;
}
