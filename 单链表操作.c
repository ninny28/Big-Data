# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>

typedef char ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

/*建立链表，输入元素*/
LinkList CreateList(LinkList head)
{
    ElemType temp;
    LinkList p;
    printf("请输入结点值（输入0结束）");
    scanf("%c,&temp");
    while(temp!='0')
    {
        if(('A'<=temp&&temp<='Z')||('a'<=temp&&temp<='z'))
        {
            p=(LinkList)malloc(sizeof(LNode));
            p->data=temp;
            p->next=head->next;
            head->next=p;
        }
        printf("请输入结点值（输入0结束）：");
        scanf("%c",&temp);
    }
    return head;
}

/*顺序输出链表的内容*/
void ListPint(LinkList head)
{
    LinkList p;
    int i=0;
    p=head->next;
    while(p!=NULL)
    {
        i++;
        printf("单链表第%d个元素是:",i);
        printf("%c\n",p->data);
        p=p->next;
    }
}

/*插入元素*/
int ListInsert(LinkList head,int i,ElemType e)
{
    LinkList p=head;
    LiskList s;
    int j;
    p=p->next;
    for(j=1;j<i-1;j++)
    {
        if(p)
        p=p->next;
        else break;
    }
    if(!p||i<1)
    {
        printf("error!请输入正确的i的值！");
        return 0;
    }
    s=(LinkList)malloc(sizeof(LNode));
    s->data=e;
    s->next=p->next;
    p->next=s;
    return 1;
}


/*删除元素*/
int ListDel(LinkList head,int i)
{
    LinkList p,tmp;
    int j;
    p=head->next;
    tmp=head;
    for(j=1;j<i;j++)
    {
        if(p)
        {
            p=p->next;
            tmp=tmp->next;
        }
        else break;
    }if(!p||i<1)
    {
        printf("errpr!请输入正确的i值！");
        return 0;
    }
    tmp->next=p->next;
    free(p);
    return 1;
}

void main()
{
    int i;
    char cmd,e;
    LinkList head;
    head=(LinkList)malloc(sizeof(LNode));
    head->next=NULL;
    CreateList(head);
    ListPint(head);
    do
    {
        printf("i,I.....插入");
        printf("d,D.....删除");
        printf("q,Q.....退出");
        do
        {
            scanf("%c",&cmd);
        }
        while((cmd!='d')&&(cmd!='D')&&(cmd!='i')&&(cmd!='I')&&(cmd!='q')&&(cmd!='Q'));
        switch(cmd)
        {
            case 'i':
            case 'I':
            printf("请输入您要插入的数据：");
            scanf("%c",&e);
            printf("请输入您要插入的位置：");
            scanf("%d",&i);
            LinkInsert(head,i,e);
            ListPint(head);
            break;
            case 'd':
            case 'D':
            printf("请输入您要删除的位置：");
            scanf("%d",&i);
            LinkDel(head,i);
            ListPint(head);
            break;
        }
    }while((cmd!='q')&&(cmd!='Q'));
}