# 第一章

### 复杂度

1.
```c
for(i=0;i<n;i++)
    b[i]=a[n-i-1];
    for(i=0;i<n;i++)
        a[i]=b[i];
```
空间复杂度O(n)
2.
```c
for(i=0;i<n;i++)
    t=a[i]
    a[i]=a[n-i-1];
    a[n-i-1]=t;
```
只计算t
空间复杂度O(1)
3.
```c
int m=0,i,j
for(i=1;i<n;i++)
    for(j=1;j<=2*i;j++)
    m++;
```
计算等差数列第n项 **m++** 执行的次数：n(n+1)

- 逻辑上把数据结构分为线性、非线性

- 算法原地工作：不需要辅助空间，需要的空间为常量
同样算法，语言级别越低，执行效率越**高**

- 长度为m,n的升序列表，合并为m+n的降序列表，最坏情况的时间复杂度O(max(m,n))

# 第二章

## 线性表
定义
```c
#include "stdio.h"
#include "windows.h"
#include "stdlib.h"

#define MAXSIZE 20//顺序表最大长度
#LIST INIT SIZE 10
/*定义顺序表*/
typedef struct {
	int data[MAXSIZE];
	int length;
}SeqList;
```
初始化
```c
status InitList sq(sqList &L)//构造一个空的顺序表L
{
    L.elem=(ElemType*) mallOC(LIST INIT SIZE*sizeof(ElemType));
    if(!L.elem)
        exit(OVERFLOW);//存储空间分配失败
    L.length=0;
    L.listsize=LIST INIT SIZE;
    return Ok;
}
```
销毁
```c
void DestroyList_sq(sqList &L)
{
    free(L.elem);
    L.elem=NULL;
    L.length=0;
    L.listsize=0;
}
```
判空
```c
void ListEmpty_sq(L)
{
    return (L.length==0);
}
```
输出
```c
status DispList sq(sqList L)
{
    if( ListEmpty_Sq(L))
        return ERROR;
    for(i=0; i<L.length; i++)
        printf( L.elem[i]);
    return Ok;

}
```
插入
```c
status ListInsert sq( sqList &L, int i, ElemType e)
{
    if(i<1 i>L.length+1)
        return ERROR;
    if(L.Length>=L.listsize)
    {
        newbase=(ElemType*)realloc(L.elem,(L.listsize + LISTINCREMENT)*sizeof(ElemType));
        if(!newbase)
            exit( OVERFLOW );//存储分配失败
        L.elem=newbase;
        L.listsize+=LISTINCREMENT;
    } 
    for(j=L.length; j>=i; j--)
        L.elem[j]= L.elem[j-1];
    L.elem[i-1]=e;
    ++L.length;
    return OK;
}
```
删除
```c
status ListDelete_sq(sqList &L, int i, ElemType &e)
{
    if(i<1||i>L,length)
        return ERROR;
    e=L.elem[i-1];
    for( j=i; j<L.length; j++ )
        L.elem[j-1]= L.elem[j];
    --L.length;
    return OK;
}
```
按位查找，获取表中第i个元素的值
```c
ElemType GetElem(seqList L,int i)
{
    return L.data[i-1];
}
```
获取值为e的值
```c
int LocateElem(seqList L,ElemType e)
{
    for(int i=0;i<L.length;i++)
        if(L.data[i]==e)
            return i+1;
    return 0;
}
```


## 单链表代码

 定义

```c
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

LNode *L;
LinkList L; 
// 声明指向单链表第一个节点的指针
```

 头节点

- 无头结点单链表
  空表时，head为NULL

- 有头结点单链表
  空表时，head指向头结点
  便于插入/删除的实现

 初始化无头结点单链表

```c
bool InitList(LinkList &L)
{
    L = NULL;
    return true;
}
```

判断链表是否为空

```c
bool Empty(LinkList L)
{
    if(L = NULL);
        return true;
    else
        return false;
}
```

 初始化有头结点单链表

```c
bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode));
    if(L = NULL);
        return true;
    L->next = NULL;
    return true;
}
```

判断链表是否为空

```c
bool Empty(LinkList L)
{
    if(L = NULL);
        return true;
    else
        return false;
}
```

 带头节点按位插入

> [!CITE]- test
> ```c
> status ListInsert(LinkList &L,int i, ElemType e)
> {
>     p=L; 
>     j=0;
>     while( j<i-1 && p!=NULL )
>     {
>         j++;
>         p=p->next;
>     }end of while
>     if(p==NULL| j>i-1)
>         return ERROR;
>     s=(LinkList)malloc(sizeof(LNode));
>     if(S ==NULL)
>         exit( OVERFLOW );
>     s->data=e;
>     s->next=p->next;
>     p->next=s;
>     return OK;
> }
>```
 
 
 不带头节点按位插入

```c
int ListInsert(LinkList &L,int i,ElemType e)
{
    if(i==1)
    {
        s=(LinkList)malloc(sizeof(LNode));
        if(S==NULL)
            exit(OVERFLOW);
        s->data=e;
        s->next=L;
        L=s;
    }
    else 
    {
        p=L; 
        j=1;
        ......
    }
    return Ok;
}
```
 删除第i个元素，带头节点

```c
int ListDelete(LinkList &L,int i, ElemType &e)
{
    j=0;
    p=L;
    while(j<i-1 && p->next)
    {
        j++;
        p=p->next;
    }
    if(!(p->next)|j>i-1)
        return ERROR;
    q=p->next;
    e=q->data;
    p->next=q->next;
    free(q);
    return oK;
}
```

 查找第i个元素

```c
int GetElem(LinkList L,int i, ElemType &e)
{
    p=L->next;
    j=1;
    while( j<i && p!=NULL )
    {
        j++;
        p=p->next;
    }
    if( j>i P==NULL )
        return 0;
    e=p->data;
    return 1;
}
```

查找值为e的元素，有则返回位置

```c
int LocateElem(LinkList L,ElemType e )
{
    p=L->next;
    n=1;
    while( p!=NULL && p->data!=e )
    {
        p=p->next;
        n++;
    }
    if(p==NULL)
        return 0;
    else return n;
}
```

尾插法

```c
void createList LR(LinkList &L,int n)
{
    L=(LinkList)malloc(sizeof(LNode));L->next=NULL;
    r=L;
    for( i=0; i<n; i++ )
    {
        s=(LinkList)malloc(sizeof(LNode))scanf(&s->data );
        r->next=s;
        r=S;
        r->next=NULL;
    }
}
```

头插法

```c
void createList LF(LinkList&L,int n)
{
    L=(LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    for(i=0;i<n;i++)
    {
        s=(LinkList)malloc(sizeof(LNode));
        scanf(&s->data);
        s->next =L->next;
        L->next = s;
    }
}
```

# 第三章 

# 第四章 

# 第五章 

# 第六章 