#include <stdio.h>

#include <boost/function.hpp>
#include <boost/bind.hpp>

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

void pre_order(BinaryTreeNode* root , VisitFunctor const& func)
{
    if(root == NULL)
        return;
    func(root);
    pre_order(root->left_ , func);
    pre_order(root->right_ , func);
}

void in_order(BinaryTreeNode* root , VisitFunctor const& func)
{
    if(root == NULL)
        return;
    in_order(root->left_ , func);
    func(root);
    in_order(root->right_ , func);
}

void visit(BinaryTreeNode* node)
{
    printf("%d\n" , node->value_);
}

int main(void)
{
    BinaryTreeNode left(NULL , NULL , 2);
    BinaryTreeNode right(NULL , NULL , 3);
    BinaryTreeNode root(&left , &right , 1);
    pre_order(&root , boost::bind(&visit , _1));
    printf("########\n");
    in_order(&root , boost::bind(&visit , _1));
    return 0;
}