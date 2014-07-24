#include <stdio.h>
#include <queue>

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

typedef std::queue<BinaryTreeNode*> TreeNodeQueue;
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

void post_order(BinaryTreeNode* root , VisitFunctor const& func)
{
    if(root == NULL)
        return;
    post_order(root->left_ , func);
    post_order(root->right_ , func);
    func(root);
}

void level_order(BinaryTreeNode* root , VisitFunctor const& func)
{
    if(root == NULL)
        return;
    TreeNodeQueue queue;
    queue.push(root);
    while(!queue.empty())
    {
        BinaryTreeNode* node = queue.front();
        queue.pop();
        func(node);
        if(node->left_ != NULL)
            queue.push(node->left_);
        if(node->right_ != NULL)
            queue.push(node->right_);
    }
}

void visit(BinaryTreeNode* node)
{
    printf("%d\n" , node->value_);
}

int main(void)
{
    BinaryTreeNode leftleft(NULL , NULL , 4);
    BinaryTreeNode leftright(NULL , NULL , 5);
    BinaryTreeNode left(&leftleft , &leftright , 2);
    BinaryTreeNode right(NULL, NULL , 3);
    BinaryTreeNode root(&left , &right , 1);
    pre_order(&root , boost::bind(&visit , _1));
    printf("########\n");
    in_order(&root , boost::bind(&visit , _1));
    printf("########\n");
    post_order(&root , boost::bind(&visit , _1));
    printf("########\n");
    level_order(&root , boost::bind(&visit , _1));
    return 0;
}