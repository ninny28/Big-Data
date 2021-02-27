#include "head.h"
#include <stdio.h>

int findMax(SDataType *a, int n)
{
    int m = 0;
    int i;
    for (i = 0; i < n; i++)
    {
        if (a[i].totalcount > m)
            m = a[i].totalcount;
    }
    return m;
}

int getLoopTimes(int num)
{
    int count = 1;
    int temp = num / 10;
    while (temp != 0)
    {
        count++;
        temp /= 10;
    }
    return count;
}

//将数字分配到各自的桶中，然后按照桶的顺序输出排序结果
void sort2(SDataType *a, int n, int i)
{
    // tobe done
}
void bucketSort3(SDataType *a, int n)
{
    int maxCount = findMax(a, n);
    //获取最大数的位数，次数也是再分配的次数。
    int loopTimes = getLoopTimes(maxCount);
    int i;
    for (i = 0; i < loopTimes; i++)
    {
        sort2(a, n, i);
    }
}

void radixSort(PNode pList)
{
    int n = listLen(pList);
    SDataType *a = toArray(pList);
}