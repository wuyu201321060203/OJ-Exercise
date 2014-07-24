#include <stdio.h>
#include <queue>

using namespace std;

queue<int> g_queue;

void yanghui_triangle(const int n)
{
    g_queue.push(1);

    for(int i = 0 ; i <= n ; ++i)
    {
        int base = 0;
        for(int j = 0 ; j != i + 2 ; ++j)
        {
            if( j == i + 1 )
            {
                g_queue.push(base);
                continue;
            }
            int a = g_queue.front();
            g_queue.pop();
            printf("%d " , a);
            g_queue.push(base + a);
            base = a;
        }
        printf("\n");
    }
}

int main(void)
{
    yanghui_triangle(5);
    return 0;
}