#include "head.h"
#include <stdio.h>

PNode partiion(PNode pStart, PNode pEnd)
{

    PNode key = pStart; // 基准
    PNode p = pStart;   // 基准应该的位置
    PNode q = pStart;   // 扫描的指针
    while (q != pEnd)
    {
        if (q->_data.totalcount > key->_data.totalcount)
        {
            p = p->_PNext;
            swapData(NULL, p, q);
        }
        q = q->_PNext;
    }
    swapData(NULL, p, key);
    return p;
}

void quickSort1(PNode pList, PNode pStart, PNode pEnd)
{
    if (pStart == pEnd || pStart->_PNext == pEnd)
        return;
    PNode mid = partiion(pStart, pEnd);   // 划分两块
    quickSort1(pList, pStart, mid);       // 分治左侧
    quickSort1(pList, mid->_PNext, pEnd); // 分治右侧
}

void quickSort(PNode pList)
{
    // empty or one node
    if (pList == NULL || pList->_PNext == NULL)
        return;
    quickSort1(pList, pList->_PNext, NULL);
}