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

int main(int argc, const char * argv[])
{
    // max，min
    MaxAndMin();

    // find
    SortAndReverse();










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
    cout << "升序排序前的序列：";
    PrintVector(myVector);

    reverse(myVector.begin(), myVector.end());
    cout << "降序排序前的序列：";
    PrintVector(myVector);
}









