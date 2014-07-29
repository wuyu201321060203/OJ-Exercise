#include <climits>
#include <strings.h>
#include <stdio.h>

#define MAXN 50001

struct node_t
{
    int left , right;
    int max , min;
};

int g_Input[MAXN];
node_t g_Array[MAXN * 4];

int maxNum = -1;
int minNum = INT_MAX;

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
        g_Array[root].max = g_Array[root].min = g_Input[left];
        return;
    }

    int middle = (left + right) >> 1;
    build( L(root) , left , middle );
    build( R(root) , middle + 1 , right);
    g_Array[root].max = max(g_Array[L(root)].max , g_Array[R(root)].max);
    g_Array[root].min = min(g_Array[L(root)].min , g_Array[R(root)].min);
}

void query(int root , int left , int right)
{
    if(g_Array[root].left == left && g_Array[root].right == right)
    {
        if(maxNum < g_Array[root].max) maxNum = g_Array[root].max;
        if(minNum > g_Array[root].min) minNum = g_Array[root].min;
        return;
    }

    int middle = ( g_Array[root].left + g_Array[root].right ) >> 1;
    if(right <= middle) query( L(root) , left , right);
    else if(left > middle) query( R(root) , left , right);
    else
    {
        query( L(root) , left , middle);
        query( R(root) , middle + 1 , right);
    }
}

int main()
{
    int n, q, i;
    scanf("%d%d", &n, &q);
    for (i = 1; i <= n; i++) scanf("%d", &g_Input[i]);
    bzero(g_Array , sizeof g_Array);
    build(1, 1, n);
    while (q--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        query(1, a, b);
        printf("%d\n", maxNum - minNum);
        maxNum = -1;
        minNum = INT_MAX;
    }
    return 0;
}
