//
//  main.cpp
//  STL_algorithm
//
//  Created by chenyufeng on 8/15/16.
//  Copyright © 2016 chenyufeng. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void PrintVector(vector<int> v);
void MaxAndMin();
void SortAndReverse();
void FindVector();
void EqualVector();
void MergeVector();
void SwapObject();

int main(int argc, const char * argv[])
{
    // max，min
    MaxAndMin();

    // sort
    SortAndReverse();

    // find
    FindVector();

    // equal
    EqualVector();

    // merge
    MergeVector();

    // swap
    SwapObject();








    return 0;
}



void PrintVector(vector<int> v)
{
    vector<int>::iterator vIterator;
    for (vIterator = v.begin(); vIterator != v.end(); vIterator++)
    {
        cout << *vIterator << " ";
    }
    cout << endl;
}

void MaxAndMin()
{
    int maxI = 3;
    int maxJ = 4;
    cout << "较大值为：" << max(maxI,maxJ) << endl;
    cout << "较小值为：" << min(maxI,maxJ) << endl;
}

void SortAndReverse()
{
    vector<int> myVector;
    myVector.push_back(2);
    myVector.push_back(9);
    myVector.push_back(1);
    myVector.push_back(0);
    myVector.push_back(7);

    cout << "排序前的序列：";
    PrintVector(myVector);

    sort(myVector.begin(), myVector.end());
    cout << "升序排序后的序列：";
    PrintVector(myVector);

    reverse(myVector.begin(), myVector.end());
    cout << "降序排序后的序列：";
    PrintVector(myVector);
}

void FindVector()
{
    vector<int> myVector;
    myVector.push_back(2);
    myVector.push_back(4);
    myVector.push_back(6);
    myVector.push_back(8);
    myVector.push_back(0);

    vector<int>::iterator vIterator;
    vIterator = find(myVector.begin(), myVector.end(), 6);
    if (vIterator == myVector.end())
    {
        cout << "未找到" << endl;
    }
    else
    {
        cout << "找到：" << *vIterator << endl;
    }
}

void EqualVector()
{
    vector<int> myVector1;
    myVector1.push_back(1);
    myVector1.push_back(5);
    myVector1.push_back(7);
    myVector1.push_back(9);

    vector<int> myVector2;
    myVector2.push_back(1);
    myVector2.push_back(5);
    myVector2.push_back(7);
    myVector2.push_back(9);

    bool isEqual = equal(myVector1.begin(), myVector1.end(), myVector2.begin());
    if (isEqual)
    {
        cout << "相等" << endl;
    }
    else
    {
        cout << "不相等" << endl;
    }
}

void MergeVector()
{
    vector<int> myVector1;
    myVector1.push_back(1);
    myVector1.push_back(5);
    myVector1.push_back(7);
    myVector1.push_back(9);

    vector<int> myVector2;
    myVector2.push_back(2);
    myVector2.push_back(3);
    myVector2.push_back(4);
    myVector2.push_back(5);

    // 需要在合并前排序
    sort(myVector1.begin(), myVector1.end());
    sort(myVector2.begin(), myVector2.end());

    // 需要指定结果集的大小
    vector<int> myResult(8);
    merge(myVector1.begin(), myVector1.end(), myVector2.begin(), myVector2.end(), myResult.begin());

    cout << "合并后的序列为：";
    PrintVector(myResult);
}

void SwapObject()
{
    int i = 2;
    int j = 3;
    swap(i, j);
    cout << "i = " << i << ";j = " << j << endl;
}









