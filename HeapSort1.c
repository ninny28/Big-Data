#include "head.h"
#include <stdio.h>

void swapInArray(SDataType *heap, int a, int b)
{
    SDataType tmp = heap[a];
    heap[a] = heap[b];
    heap[b] = tmp;
}

void buildMinHeap(SDataType *a, int n, int i)
{
    SDataType temp;
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    /* 左子树小于根节点 */
    if (l < n && a[l].totalcount < a[smallest].totalcount)
        smallest = l;
    if (r < n && a[r].totalcount < a[smallest].totalcount)
        smallest = r;
    if (smallest != i)
    {
        swapInArray(a, i, smallest);
        buildMinHeap(a, n, smallest);
    }
}

void heapSort(PNode pList)
{
    int n = listLen(pList);
    SDataType *a = malloc(sizeof(SDataType) * n);
    int i;
    PNode p = pList;
    for (i = 0; i < n; i++)
    {
        a[i] = p->_PNext->_data;
        p = p->_PNext;
    }
    p = pList;
    for (i = n / 2 - 1; i >= 0; i--)
    {
        buildMinHeap(a, n, i);
    }
    //依次把最小值沉下去 从右到左断开最后一个元素，重新构造小顶堆
    for (i = n - 1; i >= 0; i--)
    {
        swapInArray(a, 0, i);
        buildMinHeap(a, i, 0);
    }
    for (i = 0; i < n; i++)
    {
        p->_PNext->_data = a[i];
        // printf("%s,%d\n", a[i].name, a[i].totalcount);
        p = p->_PNext;
    }
}