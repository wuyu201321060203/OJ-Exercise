#ifndef UFS_H
#define UFS_H

#include <boost/scoped_array.hpp>

typedef unsigned int UINT;
typedef boost::scoped_array<int> UFSArray;

class UFS
{
public:

    UFS(UINT n):array_(new int[n]) , gangInfo_(new int[n]) , rGangInfo_(gangInfo_)
    {
        for(UINT i = 0 ; i != n ; ++i) array_[i] = -1;
        for(UINT i = 0 ; i != n ; ++i) gangInfo_[i] = 0;
    }

    UINT UFSFind(UINT x)
    {
        if( array_[x] < 0 ) return x;
        int parent = array_[x];
        array_[x] = UFSFind(array_[x]);
        gangInfo_[x] = (gangInfo_[x] + gangInfo_[parent]) % 2;
        return array_[x];
    }

    void UFSUnion(UINT root1 , UINT root2)
    {
        array_[root1] += array_[root2];
        array_[root2] = root1;
    }

    void makeRelation(UINT x , UINT y)
    {
        int px = UFSFind(x);
        int py = UFSFind(y);
        UFSUnion(py , px);
        gangInfo_[px] = (1 + gangInfo_[px] - gangInfo_[py] + 2) % 2;
    }

private:

    UFSArray array_;
    UFSArray gangInfo_;

public:

    UFSArray const& rGangInfo_;

};

#endif