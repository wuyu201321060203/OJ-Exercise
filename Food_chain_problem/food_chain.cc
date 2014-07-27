#include <stdio.h>
#include <stdlib.h>

typedef struct ufs_t
{
    int *p;
    int *dist;

}ufs_t;

ufs_t* ufs_create(int n)
{
    int i;
    ufs_t *ufs = (ufs_t*)malloc(sizeof(ufs_t));
    ufs->p = (int*)malloc(n * sizeof(int));
    ufs->dist = (int*)malloc(n * sizeof(int));
    for(i = 0; i < n; i++) {
        ufs->p[i] = -1;
        ufs->dist[i] = 0;
    }
    return ufs;
}

void ufs_destroy(ufs_t *ufs)
{
    free(ufs->p);
    free(ufs->dist);
    free(ufs);
}

int ufs_find(ufs_t* ufs , int x)
{
    if(ufs->p[x] < 0) return x;
    int parent = ufs->p[x];
    ufs->p[x] = ufs_find(ufs , ufs->p[x]);
    ufs->dist[x] = (ufs->dist[parent] + ufs->dist[x]) % 3;
    return ufs->p[x];
}

int ufs_union(ufs_t *ufs, int root1, int root2)
{
    if(root1 == root2) return -1;
    ufs->p[root1] += ufs->p[root2];
    ufs->p[root2] = root1;
    return 0;
}

void ufs_add_relation(ufs_t* ufs , int x , int y , int relation)
{
    int px = ufs_find(ufs , x);
    int py = ufs_find(ufs , y);
    ufs_union(ufs , py , px);
    ufs->dist[px] = (ufs->dist[y] - ufs->dist[x] + relation - 1 + 3) % 3;
}

int main()
{
    int n, k;
    int result = 0; /* 假话的数目 */
    ufs_t *ufs;
    scanf("%d%d", &n, &k);
    ufs = ufs_create(n + 1);
    while(k--) {
        int d, x, y;
        scanf("%d%d%d", &d, &x, &y);
        if (x > n || y > n || (d == 2 && x == y)) {
            result++;
        } else {
            const int rx = ufs_find(ufs, x);
            const int ry = ufs_find(ufs, y);
            if (rx == ry) { /* 若在同一个集合则可确定 x 和 y 的关系 */
                if((ufs->dist[x] - ufs->dist[y] + 3) % 3 != d - 1)
                    result++;
            } else {
                ufs_add_relation(ufs, x, y, d-1);
            }
        }
    }
    printf("%d\n", result);
    ufs_destroy(ufs);
    return 0;
}