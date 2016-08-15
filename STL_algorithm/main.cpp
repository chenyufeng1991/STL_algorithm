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
void UniqueVector();
void ReplaceVector();
void RemoveVector();
void ForEach();
void PrintElement(int &ele);
void CountVector();
void CopyVector();
void TransformVector();
int SquareVector(int num);
void GenerateVector();
void MoveVector();
void FillVector();
void RotateVector();

void Heap();

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

    // unique
    UniqueVector();

    // replace
    ReplaceVector();

    // remove
    RemoveVector();

    // for-each
    ForEach();

    // count
    CountVector();

    // copy
    CopyVector();

    // transform
    TransformVector();

    // generate
    GenerateVector();

    // heap
    Heap();

    // move
    MoveVector();

    // fill
    FillVector();

    // rotate
    RotateVector();









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
    cout << "交换之前两个数的值：";
    cout << "i = " << i << ";j = " << j << endl;
    swap(i, j);
    cout << "交换之后两个数的值：";
    cout << "i = " << i << ";j = " << j << endl;
}

// 去重的操作：sort-->unique-->erase
// vector可以由数组进行初始化
void UniqueVector()
{
    int array[] = {5, 3, 1, 3, 2, 5};
    vector<int> vectorFromArray(array, array + sizeof(array) / sizeof(int));

    sort(vectorFromArray.begin(), vectorFromArray.end());
    vector<int>::iterator iter = unique(vectorFromArray.begin(), vectorFromArray.end());
    vectorFromArray.erase(iter, vectorFromArray.end());

    cout << "去重之后的序列：";
    PrintVector(vectorFromArray);
}

void ReplaceVector()
{
    int array[] = {2, 4, 6, 8, 9};
    vector<int> myVector(array, array + sizeof(array) / sizeof(int));

    cout << "替换之前的序列：";
    PrintVector(myVector);
    replace(myVector.begin(), myVector.end(), 8, 888);
    cout << "替换之后的序列：";
    PrintVector(myVector);
}

// 删除操作和去重操作是类似的，实际使用remove的时候，并没有删除那个元素，而是用后面的那个
// 元素替代了想要删除的元素。最后要使用erase方法删除。
// 但是只能删除第一次出现的那个数字，而第二个元素不可删除。
void RemoveVector()
{
    int array[] = {1, 2, 3, 4, 5};
    vector<int> myVector(array, array + sizeof(array) / sizeof(int));

    cout << "删除元素前的序列：";
    PrintVector(myVector);

    vector<int>::iterator Iter = remove(myVector.begin(), myVector.end(), 4);
    myVector.erase(Iter);

    cout << "删除元素前的序列：";
    PrintVector(myVector);
}

// 遍历序列中的每个元素，然后去执行某个方法
void ForEach()
{
    int array[] = {3, 5, 7, 9, 1};
    vector<int> myVector(array, array + sizeof(array) / sizeof(int));

    cout << "for-each之前的序列：";
    PrintVector(myVector);

    for_each(myVector.begin(), myVector.end(), PrintElement);
    cout << "for-each之后的序列：";
    PrintVector(myVector);
}

// 传引用，就可以改变原序列
void PrintElement(int &ele)
{
    ele = ele * ele;
}

void CountVector()
{
    int array[] = {4, 4, 6, 9, 0, 0, 0};
    vector<int> myVector(array, array + sizeof(array) / sizeof(int));

    // 这里默认返回的是long
    long num = count(myVector.begin(), myVector.end(), 0);
    cout << "某个值出现的次数为：" << num << endl;
}

void CopyVector()
{
    int arr[] = {2, 3, 4, 5, 6};
    vector<int> myVector(arr, arr + sizeof(arr) / sizeof(int));

    // 这里需要指定大小
    vector<int> myVectorCopy(5);

    copy(myVector.begin(), myVector.end(), myVectorCopy.begin());
    cout << "拷贝后的序列为：";
    PrintVector(myVectorCopy);
}

void TransformVector()
{
    int arr[] = {2, 3, 4, 5, 6};
    vector<int> myVector(arr, arr + sizeof(arr) / sizeof(int));

    vector<int> myVectorTransform(5);

    // 第四个参数需要有返回值
    transform(myVector.begin(), myVector.end(), myVectorTransform.begin(), SquareVector);
    cout << "转换-拷贝后的序列为：";
    PrintVector(myVectorTransform);
}

int SquareVector(int num)
{
    return num * num;
}

void GenerateVector()
{
    vector<int> myVector(6);
    generate(myVector.begin(), myVector.end(), rand);
    cout << "生成的随机序列为：";
    PrintVector(myVector);
}

// 关于堆的操作
void Heap()
{
    int arr[] = {3, 7, 9, 1, 0, 6};
    vector<int> myVector(arr, arr + sizeof(arr) / sizeof(int));

    // 建立一个最大堆,第三个参数less为最大堆，greater为最小堆；默认为最大堆；
    make_heap(myVector.begin(), myVector.end(),less<int>());
    PrintVector(myVector);

    // 新添加一个元素在末尾，然后重新调整堆序。也就是把元素添加在底层vector的end处。
    // 要先在容器中加入数据，再调用push_heap;
    myVector.push_back(99);
    push_heap(myVector.begin(), myVector.end());
    PrintVector(myVector);

    // 把堆顶元素取出来，放到数组或者是vector的末尾，用原来末尾元素去替代。
    // 要先调用pop_heap,再到容器中删除数据；
    pop_heap(myVector.begin(), myVector.end());
    myVector.pop_back();
    PrintVector(myVector);

    // 排序之后就不是一个合法的堆了
    sort_heap(myVector.begin(), myVector.end());
    PrintVector(myVector);
}

void MoveVector()
{
    int arr[] = {4, 6, 8, 2, 0};
    vector<int> myVector(arr, arr + sizeof(arr) / sizeof(int));

    vector<int> myVectorMove(10); // 初始值为0
    move(myVector.begin(), myVector.end(), myVectorMove.begin() + 5);
    cout << "移动后的序列为：";
    PrintVector(myVectorMove);
}

/**
 *  vector的初始化可以用array，也可以直接用{}.
 */
void FillVector()
{
    vector<int> myVector{3, 4, 5, 6, 7};

    cout << "初始的序列为：";
    PrintVector(myVector);
    // 数据全部填充为**
    fill(myVector.begin(), myVector.end(), 99);
    cout << "填充后的序列为：";
    PrintVector(myVector);
}

// rorate函数将[first, middle)内的元素和[middle, last)内的元素互换，middle所指元素成为容器的第一个元素。
void RotateVector()
{
    vector<int> myVector{4, 5, 0, 1, 9};

    cout << "旋转前的序列为：";
    PrintVector(myVector);
    rotate(myVector.begin(), myVector.begin() + 3, myVector.end());
    cout << "旋转后的序列为：";
    PrintVector(myVector);
}










