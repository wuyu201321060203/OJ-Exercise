#include <queue>
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

#define MAX 10000

int a[MAX];
int b[MAX];
int n;

struct Node
{
    Node(int sum , unsigned int bPos):sum_(sum),bPos_(bPos)
    {
    }

    bool operator > (Node const& rhs) const
    {
        return (sum_ > rhs.sum_) ? true : false;
    }

    int sum_;
    unsigned int bPos_;
};

void kmerge()
{
    std::priority_queue<Node , std::vector<Node> , std::greater<Node> > queue;
    for(int i = 0 ; i != n ; ++i)
    {
        Node tmp(a[i] + b[0] , 0);
        queue.push(tmp);
    }

    for(int i = 0 ; i != n ; ++i)
    {
        Node tmp = queue.top();
        queue.pop();
        std::cout << tmp.sum_ << " ";
        Node newNode(tmp.sum_ - b[tmp.bPos_] + b[tmp.bPos_ + 1] , ++tmp.bPos_);
        queue.push(newNode);
    }
    std::cout << "\n";
}

int main(void)
{
    std::cin >> n;
    for(int i = 0 ; i != n ; ++i) std::cin >> a[i];
    for(int i = 0 ; i != n ; ++i) std::cin >> b[i];

    std::sort(a , a + n);
    std::sort(b , b + n);

    kmerge();
    return 0;
}
