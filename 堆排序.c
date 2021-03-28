#include "head.h"
#include <stdio.h>
#include <stdlib.h>

void swapInArray(SDataType *heap, int a, int b) {
  SDataType tmp = heap[a];
  heap[a] = heap[b];
  heap[b] = tmp;
}

void buildMinHeap(SDataType *a, int n, int i) {
  int smallest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  // 从左子树、右子树和根找出最小的
  if (l < n && a[l].totalcount < a[smallest].totalcount)
    smallest = l;
  if (r < n && a[r].totalcount < a[smallest].totalcount)
    smallest = r;
  if (smallest != i) // 如果子树小于根
  {
    swapInArray(a, i, smallest);
    buildMinHeap(a, n, smallest);
  }
}

void heapSort(PNode pList) {
  int n = listLen(pList);
  SDataType *a = toArray(pList);

  int i;
  for (i = n / 2 - 1; i >= 0; i--) {
    buildMinHeap(a, n, i);
  }
  //依次把最小值沉下去 从右到左断开最后一个元素，重新构造小顶堆
  for (i = n - 1; i >= 0; i--) {
    swapInArray(a, 0, i);
    buildMinHeap(a, i, 0);
  }

  PNode p = pList;
  for (i = 0; i < n; i++) {
    p->_PNext->_data = a[i];
    // printf("%s,%d\n", a[i].name, a[i].totalcount);
    p = p->_PNext;
  }
  free(a);
}