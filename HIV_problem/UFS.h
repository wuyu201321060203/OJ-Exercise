#ifndef UFS_H
#define UFS_H

#include <boost/scoped_array.hpp>

typedef unsigned int UINT;
typedef boost::scoped_array<int> UFSArray;

class UFS
{
public:

    UFS(UINT n):array_(new int[n])
    {
        for(UINT i = 0 ; i != n ; ++i) array_[i] = -1;
    }

    UINT UFSFind(UINT x)
    {
        if( array_[x] < 0 ) return x;
        return array_[x] = UFSFind(array_[x]);
    }

    int UFSUnion(UINT x , UINT y)
    {
        UINT lhs = UFSFind(x);
        UINT rhs = UFSFind(y);
        if(lhs == rhs)
        {
            return -1;

        }
        else
        {
            array_[x] += array_[y];
            array_[y] = x;
        }
    }

    UINT UFSGetSetSize(UINT x);
    {
        UINT rt = UFSFind(x);
        return -array_[rt];
    }

private:

    UFSArray array_;

};

#endif