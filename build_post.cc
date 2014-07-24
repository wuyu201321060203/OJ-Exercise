#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <cassert>

#include <boost/function.hpp>
#include <boost/bind.hpp>

#define MAX 64

typedef int TreeNodeElement;

struct BinaryTreeNode
{
    BinaryTreeNode(BinaryTreeNode* left , BinaryTreeNode* right,
                   TreeNodeElement value):left_(left),
                                          right_(right),
                                          value_(value)
    {
    }

    BinaryTreeNode* left_;
    BinaryTreeNode* right_;
    TreeNodeElement value_;
};

typedef boost::function<void (BinaryTreeNode*)> VisitFunctor;

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

void rebuild(char const* pre , char const* in , int len , BinaryTreeNode** root)
{
    if(pre == NULL || in == NULL || len == 0)//len is used for detecting end condition
        return;
    int leftLen = strchr(in , pre[0]) - in;
    *root = new BinaryTreeNode(NULL , NULL , *pre);
    rebuild(pre + 1 , in , leftLen , &( (*root)->left_) );
    rebuild(pre + leftLen + 1 , in + leftLen + 1 , len - leftLen - 1,
            &( (*root)->right_ ) );
}

void print_post_order(BinaryTreeNode const* root)
{
    if(root == NULL)
        return;
    print_post_order(root->left_);
    print_post_order(root->right_);
    printf("%c" , root->value_);
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

void rebuild_test()
{
    char pre[MAX] = { 0 };
    char in[MAX] = { 0 };
    int n;
    BinaryTreeNode *root;
    scanf("%s%s", pre, in);
    n = strlen(pre);
    rebuild(pre , in , n , &root);
    print_post_order(root);
}

int main(void)
{
    build_post_test();
    rebuild_test();
    return 0;
}