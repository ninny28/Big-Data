#define LENGTH 30
typedef struct User_login
{
    char name[LENGTH];//用户名
    int totalcount;//登录次数
} SDataType;  //链表的节点
typedef struct SListNode
{
    SDataType _data;
    struct SListNode *_PNext;
} Node, *PNode;   //封装链表节点和next指针

PNode createList();
void addNode(PNode pList, SDataType data);
void merge(PNode pList);
void travelList(PNode pList);
void deleteList(PNode pList);
int listLen(PNode pList);
SDataType* toArray(PNode pList);

int lessThan(PNode p, PNode q);
void swapData(PNode pList, PNode p, PNode q);

void read(char *fileName, PNode pList);
void readFast(char *fileName, PNode pList);
void write(char *fileName, PNode pList);

void bubbleSort(PNode pList);
void quickSort(PNode pList);
void heapSort(PNode pList);
void radixSort(PNode pList);