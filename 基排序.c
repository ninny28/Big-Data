#include "head.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int BASE = 10;

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

// 获取最长的位数
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

// s=1个/2十/3百/4千/5万，获取s位数的数字
int getGigit(SDataType userLogin, int s)
{
    int tmp = 1, i;
    for (i = 0; i < s - 1; i++)
    {
        tmp *= 10;
    }
    return (userLogin.totalcount / tmp) % BASE;
}

void radixSort(PNode pList)
{
    int n = listLen(pList);
    SDataType *a = toArray(pList);

    int i, j, k;
    SDataType *radixArray[BASE]; // SDataType数组，每个数组里面有n个元素。实验数据最高3位数，需要空间3n
    int idx[BASE];
    for (i = 0; i < BASE; i++)
    {
        idx[i] = 0;
        radixArray[i] = malloc((n) * sizeof(SDataType));
    }
    int maxLen = getLoopTimes(findMax(a, n));
    int s; // 位数，个十百千万
    for (s = 1; s <= maxLen; s++)
    {
        // 按第s位，将a的元素分配到10个桶
        for (i = 0; i < n; i++)
        {
            int digit = getGigit(a[i], s); // 0-9
            radixArray[digit][idx[digit]].totalcount = a[i].totalcount;
            strcpy(radixArray[digit][idx[digit]].name, a[i].name);
            idx[digit]++;
        }
        // 按基数放回
        for (i = 0, k = 0; i < BASE; i++)
        {
            // 逐个桶放回
            for (j = 0; j < idx[i]; j++, k++)
            {
                // a[k] = radixArray[i][j];
                strcpy(a[k].name, radixArray[i][j].name);
                a[k].totalcount = radixArray[i][j].totalcount;
            }
            idx[i] = 0;
        }
    }
    for (i = 0; i < BASE; i++)
    {
        free(radixArray[i]);
    }
    PNode p = pList;
    for (i = n - 1; i >= 0; i--)
    {
        p->_PNext->_data = a[i];
        p = p->_PNext;
    }
}