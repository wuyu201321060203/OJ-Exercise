#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <cassert>

#define MAX 64

void build_post(char const* pre , char const* in , int len , char* post)
{
    if(len <= 0)
        return;
    assert(pre && in && post);
    int leftLen = strchr(in , pre[0]) - in;
    build_post(pre + 1 , in , leftLen , post);
    build_post(pre + leftLen + 1 , in + leftLen + 1 , len - leftLen - 1,
               post + leftLen);
    post[len - 1] = pre[0];
}

void build_post_test()
{
    char pre[MAX] = {0};
    char in[MAX] = {0};
    char post[MAX] = {0};
    int n;
    scanf("%s%s", pre, in);
    n = strlen(pre);
    build_post(pre, in, n, post);
    printf("%s\n", post);
}

int main(void)
{
    build_post_test();
    return 0;
}