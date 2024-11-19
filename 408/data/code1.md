# 线性表
## 顺序表
#### 顺序表定义
**静态定义**

```c
#define Maxsize 50
typedef struct{
    ElemType data[MaxSize];
    int length;
}SqList ;
```

**动态定义**

```c
#define InitSize 100
typedef struct {
    ElemType *data;//指示动态分配数组的指针
    int MaxSize，length;//数组的最大容量和当前个数
} SeqList;
```

#### 顺序表基本操作
**插入**

```c
bool ListInsert(SqList &L,int i,ElemType e){
    //本算法实现将元素e插入到顺序表L中第i个位置
    if(i<1lli>L.length+1)
    //判断i的范围是否有效
        return false;
    if(L.length>=MaxSize)
    //当前存储空间已满，不能插入
        return false;
    for(int i=L.length;i>=i;j--)
    //将第i个元素及之后的元素后移
        L.data[j]-L.data[j-1];
    L.data[i-1]=e;//在位置i处放入e
    L.length++;//线性表长度加1
    return true;
}
```

**删除**
```c
bool ListDelete(SqList &L,int i,ElemType &e){
    //本算法实现删除顺序表L中第1个位置的元素
    if(1<1I11>L.1 ength)
    //判断1的克图是否有效
        return false;
    e=L.data[i-l];
        //将被利除的元素赋值给e
    for(1ntj-1:j<L.length:j+)
    //将第1个位置之后的元素前移
        L.data[j-1]-L.data[j];
    L.length--;//线性表长度减1
    return true;
}
```

**按值查找**
```c
    int LocateElem(SqList L,ElemType e){
    //实现查找顺序表中值为e的元素
    int i;
    for(i=0;i < L.length;i++)
        if (L.data[i]==e)
            return i+1;//返回其位序i+1
    return 0;//退出循环，说明查找失败
}
```


## 单链表
#### 单链表节点定义

```c
typedef struct LNode{ //定义单链表结点类型
    ElemType data;//数据域
    struct LNode *next;//指针域
}LNode,*LinkList ;
```

#### 单链表基本操作
**头插法**
```c
LinkList CreateList1(LinkList &L){
    //从表尾到表头逆向建立单链表L，每次均在头结点之后插入元素
    LNode *s;int x;
    L=(LinkList)malloc(sizeof(LNode));//创建头结点
    L->next=NULL;//初始化为空链表
    while(scanf("%d",&x) != EOF){ //循环输入
        s=(LNode*)malloc(sizeof(LNode));//创建新结点
        s->data=x;
        s->next=L->next;
        L->next=s;//将新结点插入表中，L为头指针
        scanf("%d" ,&x);
    }//while结束
    return L;
}
```

**尾插法**
```c
LinkList CreatList2(LinkList &L){
    //从表头到表尾正向建立单链表L,每次均在表尾插入元素
    int x;//设元素类型为整型
    L=(LinkList)malloc(sizeof (LNode));
    LNode *s, *r=L; //r为表尾指针
    while(scanf("%a",kx) != EOF){
    //循环输入
    s=(LNode*)malloc(sizeof(LNode));
    s->data =xi
    r->next si
    x=s;//r指向新的表尾结点
    scanf ("%d",&x);
    }
    r->next=NULL;//尾结点指针置空
    return L;
}
```

**按序号索值**

```c
INode *GetElem(LinkList L,int i){//本算法取出单链表L(带头结点)中第1个位置的结点指针
    int j=1;//计数，初始化为1LNode *p=L->next;//头结点指针赋给P
    if(i==0)
        return L;//若i等于0.则返回头结点
    if(i<1)
        return NULL;//若i无效，则返回NULL
    while(p&&j<i){ //从第1个结点开始找，查找第i个结点
        p=p->next;
    }
    j++;
    return p;//返回第i个结点的指针，如果i大于表长，p=NULL,直接返回p即可
}
```

**按值查找结点**

```c
LNode *LocateElem(LinkList L,ElemType e){//本算法查找单链表L(带头结点)中数据域值等于e的结点指针，否则返回NULL
    LNode *p=L->next;
    while(p!=NULL&&p->data!=e)//从第1个结点开始查找data域为e的结点
        p=p->next ;
    return p;//找到后返回该结点指针，否则返回NULL
}
```

**插入节点操作**(两种)
前插

```c
p-GetElem(L,i-1);//查找插入位置的前驱结点
s->next=p->next;
p->next=s;
```

后插

```c
//将*s结点插入到*p之前的主要代码片段
s->next=p->next;//修改指针域，不能颠倒
p->next=s;
temp-p->data;//交换数据域部分
p->data=s->data;
s->data=temp;
```

**删除节点操作**

```c
//删除所给节点后一节点
p=GetElem(L,i-1);//查找删除位置的前驱结点
q=p->next;//令g指向被删除结点
p->next=q->next;//将*q结点从链中“断开”
free(q);//释放结点的存储空间
//删除所给节点
q=p->next;//令q指向*p的后继结点
p->data=p->next->data;//和后继结点交换数据域
p->next=q->next;//将*q结点从链中“断开”
free(q);//释放后继结点的存储空间
```

## 双链表
#### 双链表节点定义

```c
typedef struct DNode{ //定义双链表结点类型
    ElemType data;//数据域
    struct DNode *prior,*next;//前驱和后继指针
}DNode,*DLinkList ;
```

#### 双链表基本操作
**插入** 

```c
s->next=p->next;//将结点*s插入到结点*p之后
p->next->prior=s;
s->prior=p;
p->next=s;
```

**删除**

```c
p->next=q->next;  
q->next->prior=p;  
free(q);
```

#### 静态链表

```c
#define MaxSize 50 //静态链表的最大长度
typedef struct{ //静态链表结构类型的定义
    ElemType data;//存储数据元素
    int next;//下一个元素的数组下标
}SLinkList[MaxSize];
```

# 栈和队列
## 栈
#### 顺序栈
**顺序栈的存储类型定义**

```c
#define MaxSize 50 //定义栈中元素的最大个数
    typedef struct{
    ElemType data[MaxSize];//存放栈中元素
    int top;//栈顶指针
}SqStack;
```

**顺序栈的基本运算**


```c
(1)初始化
void InitStack(&S){
//初始化栈
    s.top=-1;//初始化栈顶指针
}
(2)判断空
bool StackEmpty(S){
//判断栈是否为空
    if(s.top ==-1)//栈空
        return true;
    else //不空
    return false;
}
(3)进栈
bool Push(SqStack &S,ElemType x){
//进栈操作
    if(S.top ==MaxSize-1)//栈满，报错
        return false;
    S.data[++s.top]=x;//指针先加1，再入栈
    return true;
}
(4)出栈
bool Pop(SqStack &S,ElemType &x){
//出栈操作
    if(s.top ==-1)//栈空，报错
        return false;
    x=S.data[s.top--];//先出栈，指针再减1
    return true;
}
(5)获取栈顶元素
bool GetTop(SqStack S,ElemType &x){
//获取栈顶元素
    if(S.top == -1)//栈空，报错
        return false;
    x=S.data[S.top];//x记录栈顶元素return true;
}
```


#### 链式栈
**链式栈的存储定义**

```c
typedef struct Linknode{
    ElemType data;//数据域
    struct Linknode *next;//指针域
}*LiStack;
```

## 队列
#### 顺序队列
**顺序队列的定义**

```c
#define MaxSize 50//定义队列中元素的最大个数
typedef struct {
    ElemType data[MaxSize];//存放队列元素
    int front，rear;//队头指针和队尾指针} SqQueue;
}
```

**循环队列的操作**

```c
(1)初始化
void InitQueue(SqQueue &Q){
//初始化循环队列
    Q.rear=Q.front=0;//初始化队首、队尾指针
}
(2)判空
bool isEmpty(SqQueue q){
//判断循环队列是否为空
    if(Q.rear==Q.front)
        return true;//队空条件
    else 
        return false;
}
(3)入队
bool EnQueue(SqQueue &Q，ElemType x){
//循环队列的入队操作
    if((Q.rear +1)%MaxSize==Q.front)
        return false:
    //队满报错
    Q.data[Q.rear]=x;
    Q.rear=(Q.rear+1)%MaxSize;//队尾指针加1取模
    return true;
}
(4)出队
bool DeQueue(SqQueue &Q，ElemType &x){
//循环队列的出队操作
    if(Q.rear ==Q.front)
        return false;//队空报错
    x=Q.data[Q.front];
    Q.front=(Q.front+1)%MaxSize;//队头指针加1取模
    return true;
}
```

#### 链式队列
链式队列的存储

```c
typedef struct{ //链式队列结点
    ElemType data;
    struct LinkNode *next;
}inkNode ;
typedef struct{ //链式队列
    LinkNode *front，*rear;//队列的对头和队尾指针
}LinkQueue;
```

链式队列的基本操作

```c
(1)初始化
void Initqueue(LinkQueue &){
//初始化链式队列
    Q.front=.rear=(LinkNode *)malloc(sizeof(LinkNode));//建立头结点
    Q.front->next=NULL;//初始为空
}
(2)判断空
bool IsEmpty(LinkQueue Q){
    if(Q.front==Q.rear)
        return true;
    else 
        return false;
}
(3)入队
void EnQueue(LinkQueue &Q,ElemType x){
//链式队列入队操作
    LinkNode *s=(LinkNode *)malloc(sizeof(LinkNode));
    s->data=x;s->next=NULL;//创建新结点，插入到链尾Q.rear->next = s;
    Q.rear =s;
}
(4)出队
bool DeQueue(LinkQueue &Q,ElemType &x){
//链式队列出队操作
    if(Q.front==Q.rear)
        return false;//空队
    LinkNode *p=Q.front->next;
    x= p->data;
    Q.front->next =p->next;
    if(Q.rear == p)
        Q.rear=Q.front;//若原队列中只有一个结点，删除后变空
    free(p);
    return true;
}
```
## 应用
栈在递归中的作用(斐波那契)

```c
int Fib(n){//斐波那契数列实现
    if(n==0)
        return 0;//边界条件
    else if(n==1)
        return 1;//边界条件
    else
        return Fib(n-1)+Fib(n-2);//递归表达式
}
```

# 树与二叉树
## 二叉树

#### 二叉树的概念

```c
typedef struct BiTNode{ //链式二叉树定义ElemType data;//数据域
    struct BiTNode *lchild，*rchild;//左、右孩子指针
} BiTNode, *BiTree;
```


#### 二叉树的操作
二叉树的遍历(**递归**)

```c
1.先序遍历
void PreOrder(BiTree T){
    if(T != NULL){
        visit(T);//访问根结点
        PreOrder(T->lchild);//递归遍历左子树
        PreOrder(T->rchild);//递归遍历右子树
    }
}
2.中序遍历
void InOrder(BiTree T){
    if(T != NULL){
        InOrder(T->lchild);//递归遍历左子树
        visit(T);//访问根结点
        InOrder(T->rchild);//递归遍历右子树
    }
}
3.后序遍历
void PostOrder(BiTree T){
    if(T != NULL){
    PostOrder(T->lchild);//递归遍历左子树
    PostOrder(T->rchild);//递归遍历右子树
    visit(T);//访问根结点
    }
}
```


二叉树的遍历(**非递归**)

```c
void InOrder2(BiTree T){
//二叉树中序遍历的非递归算法，需要借助一个栈
    InitStack(S);BiTreep=T;//初始化栈;p是遍历指针
    while(pll!IsEmpty(S)){//栈不空或p不空时循环
        if(p){ //一路向西~不对一路向左(
            Push(s,p);//当前节点入栈
            P=p->lchild;//左子树不空便继续往左走
        }
        else{ //退栈，访问根结点，遍历右子树
            Pop(S,p);visit(p);//退栈，访问根结点
            p=p->rchild;//再向右子树走
        }
    }
}
```

**二叉树的层次遍历**

```c
void Level0rder(BiTree T){
    //层次遍历
    InitQueue(Q);//初始化辅助队列
    BiTree p;
    EnQueue(Q,T);//将根结点入队
    while(!IsEmpty(Q)){//队列不空循环
        DeQueue(Q,p);//队头元素出队
        visit(p);//访问当前p所指向结点
    }
    if(p->lchild!=NULL)
        EnQueue(Q,p->lchild);//左子树不空，则入队列
    if(p->rchild!=NULL)
        Enqueue(Q,p->rchild);//右子树不空，则入队列
}
```

## 线索二叉树
#### 线索二叉树的概念
**线索二叉树节点定义**

```c
typedef struct ThreadNode {
//线索二叉树定义
    ElemType data;//数据元素
    struct ThreadNode *lchild，*rchild;//左、右孩子指针
    int ltag，rtag;//左、右线索标志
} ThreadNode, *ThreadTree;
```

#### 线索二叉树的操作
**线索二叉树的构造**

```c
void InTread(ThreadTree &p,ThreadTree &pre){//中序遍历对二叉树线索化的递归算法
    if(p!=NULL){
        InTread(p->lchild，pre);//递归，线索化左子树if(p->lchild ==NULL){ //左子树为空建立前驱线索
        p->lchild = pre;
        p->ltag =1;
    }
    if(pre!=NULL && pre->rchild == NULL){
        pre->rchild=p;//建立前驱结点的后继线索
        pre->rtag =1;
    }
    pre=p;//标记当前结点成为刚刚访问过的结点
    InTread(p->rchild，pre);//递归，线索化右子树
}//if{p!=NULL}
通过中序遍历建立中序线索二叉树线的主过程算法
void CreateInThread(ThreadTree T){
    //中序遍历建立中序线索二叉树
    ThreadTree pre= NULL;
    if(T!=NULL){ //非空二叉树，线索化
        InTread(T，pre);//线索化二叉树
        pre->rchild=NULL;//处理遍历的最后一个结点
        pre->rtag =1;
    }
}
```

**线索二叉树的遍历**

```c
(1)求中序线索二叉树中序序列下的第一个结点
ThreadNode *Firstnode(ThreadTree p){
    //求中序线索二叉树中序序列下的第一个结点
    while(p->ltag == 0)
        p=p->lchild;//最左下结点(不一定是叶结点)
    return p;
}
(2)求中序线索二叉树中结点p在中序序列下的后继结点
ThreadNode *Nextnode(ThreadNode *p){
    //求中序线索二叉树中结点p在中序序列下的后继结点
    if(p->rtag == 0)
        return Firstnode(p->rchild);
    else
        return p->rchild;//rtag==1直接返回后继线索
}
(1-1)求中序线索二叉树中序序列下的最后一个结点
ThreadNode *Lastnode(ThreadTree p){
//求中序线索二叉树中序序列下的最后一个结点
    while(p->rtag==0)
        p=p->rchild;
    return p;
}
(2-1)求中序线索二叉树中结点p在中序序列下的前驱结点
ThreadNode *Prenode(ThreadNode *p){
//求中序线索二叉树中结点P在中序序列下的前驱结点
    if(p->ltag == 0)
        return Lastnode(p->lchild);
    else
        return p>lchild;
}
(3)不带头结点的中序线索二叉树的中序遍历
void In0rder(ThreadTree T){
//不带头结点的中序线索二叉树的中序遍历
    for(ThreadNode *p=Firstnode(T);p!=NULL;pNextnode(p))
        visit(p);
}
```

## 树、森林
#### 树的存储结构
**双亲表示法**

```c
#define MAXTREESIZE 100//树中最多结点数
typedef struct{ //树的结点定义
    ElemType data;//数据元素
    int parent;//双亲位置域
} PTNode ;
typedef struct{ //树的类型定义
    PTNode nodes[MAXTREESIZE];//双亲表示
    int n; //结点数
}PTree ;
```

**孩子兄弟表示法**

```c
typedef struct CSNode{
    ElemType data;//数据域
    struct CSNode *firstchild,*nextsibling;//第一个孩子和右兄弟指针
}CSNode ,*CSTree;
```

## 树的应用
#### 并查集
**并查集结构定义**

```c
#define SIZE 100
int UFSets[SIZE];//集合元素数组(双亲指针数组)
```

**并查集初始化**

```c
void Initial(int s[]){
    for(inti=0;i<MaxSize;i++)//每个自成单元素集合
        S[i]= -1;
}
```

**Find 操作**

```c
int Find(int s[],int x){
    while(S[x]>=0)//循环寻找x的根
        x = S[x];
    return x;//根的S[]小于0
}
```

**Union 操作**

```c
void Union(int S[],int Root1,int Root2){
//Root1与Root2不同并且表示子集合的名字
    S[Root2]=Root1;//将根Root2连接到另一根Root1下面
}
```

#### 二叉查找树
**二叉查找树非递归查找**

```c
BSTNode *BST_Search(BiTree T, ElemType key, BiTNode *&p
) {
//查找函数返回指向关键字值为key的结点指针，若不存在，返回NULL
    P=NULL;//p指向被查找结点的双亲结点，用于插入删除操作
    while(T!=NULL &&key!=T->data){
        P = T;
        if(key< T->data)
            T = T->lchild;
        else
            T=->rchild;
    }
    return T;
}
```

**二叉查找树插入**

```c
int BST Insert(BiTree &T,KeyType k){
//在二叉排序树T中插入一个关键字为k的结点
    if(T==NULL){ //原树为空，新插入的记录为根结点
        T=(BiTree)malloc(sizeof(BSTNode));
        T->key = k;
        T->lchild=T->rchild = NULL;
        return 1;//返回1，表示成功
    }
    else if(k== T->key)//树中存在相同关键字的结点
        return 0;
    else if(k<T->key)//插入到T的左子树中
        return BST Insert(T->lchild，k);
    else //插入到T的右子树中
        return BST Insert(T->rchild，k);
```

**二叉排序树构造**

```c
void Creat_BST(BiTree &T,KeyType str[],int n){//用关键字数组str[]建立一个二叉排序树
    T=NULL;//初始时bt为空树
    int i=0;
    while(i<n){ //依次将每个元素插入
        BST_Insert(T,str[i]);
        i++;
    }
}
```

# 查找
## 顺序查找和折半查找
#### 顺序查找

```c
typedef struct{ //查找表的数据结构
    ElemType *elem;//元素存储空间基址，建表时按实际长度分配，0号单元留空
    int TableLen;//表的长度
}SSTable ;
int Search Seq(SSTable ST,ElemType key){
//在顺序表ST中顺序查找关键字为key的元素。若找到则返回该元素在表中的位置
    ST.elem[0]=key;//“哨兵”
    for(i=ST.TableLen;ST.elem[i]!-key;--i){ //从后往前找
    }
    return i;//若表中不存在关键字为key的元素，将查找到i为0时退出for循环
}
```

#### 折半查找

```c
int Binary Search(SeqList L,ElemType key){//在有序表L中查找关键字为key的元素，若存在则分会其位置，不存在返回-1
    int low=0,high=L.length-1，mid;
    while(low<=high){
        mid=(low+high)/2;//取中间位置
    if(L.elem[mid]== key)
        return mid;//查找成功则返回所在位置
    else if(L.elem[mid]>key)
       high=mid-1;//从前半部分继续查找
    else
        low=mid +1;//从后半部分继续查找
    }
    return -1;
}
```

# 排序
## 插人排序
#### 直接插人排序

```c
void InsertSort(ElemType A[],int n){//直接插入排序
    int i, j;
    for(i=2;i<=n;i++)//依次将A[2]~A[n]插入到前面已排好的序列
        if(A[i].key<A[i -1].key){ //若A[i]的关键码小于其前驱，需将A[i]插入有序表
            A[0]=A[i];//复制为哨兵，A[0]不存放元素
            for(j=i-1;A[0].key <A[j].key;--j)//从后往前查找待插入位置
                A[j+1]= A[j];//向后挪位
            A[j+1]=A[0];//复制到插入位置
        }
}
```

#### 折半插人排序

```c
void InsertSort(ElemType A[], int n){//折半插入排序
    int i,j,low, high, mid;
    for(i=2;i<=n;i++){ //依次将A[2]~A[n]插入到前面已排序序列
        A[O]=A[i];//将A[i]暂存到A[0]
        low=1;high=i-1;//设置折半查找的范围
        while(low<=high){ //折半查找(默认递增有序)
            mid=(low+high)/2;//取中间点
            if(Amid].key>A[0].key)
                high=mid-1;//查找左子表
            else 
                low=mid +1;//查找右子表子
        }
        for(j=i-1;j>=high +1;--j)
            A[j+1]=A[j];//统一后移元素，空出插入位置
        A[high+1]=A[0];//插入操作
    }
}
```

#### 希尔排序

```c
void ShellSort(ElemType A[ ]，int n){
//希尔排序，对顶序表微希尔插入排序，比直接插入排序有如下修改
//1.前后记录的增量是dx,不是1
//2.A[0]只是暂存单元，不是哨兵，当j<=0时，插入位置已到
	int i,j,dk；//d:步长
    for(dk=n/2;dk>=1;dk=dk/2)//步长变化
        for(i= dk+ 1;i<=n; ++i)if(A[i].key<A[i- dk].key){ //需将A[i]插入有序增量子表
            A[O]=A[i];//暂存在A[0]
            for(j=i- dk;j>0 && A[0].key < A[j].key;j-= dk)
                A[j+ dk]= A[j];//记录后移，查找插入的位置
        A[j+ dk]= A[j];//插入
        }//if
}
```

## 交换排序
#### 冒泡排序

```c
void BubbleSort(ElemType Al],int n){//用冒泡排序法将序列A中的元素按从小到大排列
    bool flag;
    for(inti=0;i<n-1;i++){
        flag= false;//表示本趟冒泡是否发生交换的标志
        for(int j=n-1;j>i;j--) //一趟冒泡过程
            if(A[j-1].key >A[j].key){ //若为逆序
                swap(A[j-1]，A[j]);//交换
                flag = true;
            }
        if(flag == true)
            return;//本趟遍历后没有发生交换说明表已经有序
    }
}
```

#### 快速排序

```c
void QuickSort(ElemType A[]],int low, int high){//快速排序
    if(low< high){ //递归跳出的条件//Partition()就是划分操作，将表A[low...high]划分为满足上述条件的两个子表
        int pivotpos=Partition(A，low，high);//划分
        QuickSort(A，low，pivotpos-1);//依次对两个子表进行递归排序
        QuickSort(A,pivotpos + 1,high);
    }
}
int Partition(ElemType A[],int low,int high){
//严版教材中的划分算法（一趟排序过程）
    ElemType pivot=A[1ow];//将当前表中第一个元素设为枢轴值，对表进行划分
    while(1ow<high){/循环跳出条件
        while(low<high&&A[high]>= pivot)
            --high;
        A[low]=A[high];//将比枢轴值小的元素移动到左端
        while(low<high &&A[low]<= pivot)
            ++loW;  
        A[high]=A[low];//将比枢轴值大的元素移动到右端
    }
    A[low]=pivot;//枢轴元素存放到最终位置
    return low;//返回存放枢轴元素的位置
}
```

## 选择排序
#### 简单选择排序

```c
void SelectSort(ElemType A[],int n){
//对表A进行简单的选择排序，A[]从0开始存放元素
    for(inti=0;i<n-1;i++){//一共进行n-1趟
        int min =i;//记录最小元素位置
        for(intj=i+1;j<n;j++)//在A[1...n-1]中选择最小的元素
            if(A[j]<A[min])min=j;//更新最小元素的位詈
        if(min!=i)swap(A[i]，A[min]);//与第i个位置互换
    }
}
```

#### 堆排序

```c
建立大根堆
void BuildMaxHeap(ElemType A[],int len){
    //建立大根堆
    for(inti=len/2;i>0;i--)//从i=[n/2]~1，反复调整堆
        AdjustDown(A，i,len);
}
void AdjustDown(ElemType A[l,int k,int len){//函数AdjustDown将元素k向下进行调整
    A[0]=A[k];//A[0]暂存
    for(inti=2*k;i<=len;i*=2){ //沿key较大的子结点向下筛选
        if(i <len && A[i]< A[i + 1])
            i++;//取key较大的子结点的下标
        if(A[0]>=A[i])
            break;//筛选结束
        else {
            A[k]=A[i];//将A[i]调整到双亲结点上
            k=i;//修改k值，以便继续向下筛选
        }
        A[k]=A[0];//被筛选结点的值放入最终位置
}
堆排序算法
void HeapSort(ElemType A[],int len){
//堆排序
    BuildMaxHeap(A，len);//建立初始堆
    for(inti=len;i>1;i--){//n-1趟的交换和建堆过程
        swap(A[i]，A[1]);//输出堆顶的元素(和堆底元素交换)
        AdjustDown(A，1，i-1);//整理，把剩余的i-1个元素整理成堆
    }
}
向上调整堆的算法
void AdjustUp(ElemType A[],int k){//参数k为向上调整的结点，也为堆的元素个数
    A[0]= A[k];
    inti=k/2;//若结点值大于双亲结点,则将双亲结点下调，并继续向上比较
    while(i>0 && A[i]<A[0]){ //循环退出条件A[k]= A[i];//双亲结点下调
        k = i;
        i=k/2;//继续向上比较
    }//while
    A[k]=A[0];//复制到最终位置
}
```

## 归并排序

```c
ElemType *B=(ElemType *)malloc((n+1)*sizeof(ElemType));//辅助数组B
void Merge(ElemType A[],int low,int mid,int high){//表A的两端A[low...mid]和A[mid+1...high]各自有序，将它们合并成一个有序表
    for(int k=low;k<=high;k++)
    B[k]=A[k];//将A中所有元素复制到B中
    for(i=low,j=mid+1,k=i;i<=mid&&j<=high;k++){
        if(B[i]<=B[i])//比较B的左右两段中的元素
            A[k]=B[i++];//将较小值复制到A中
        else
            A[k]=B[i++];
    }//for
    while(i<=mid)
        A[k++]=B[i++];//若第一个表未检测完，复制
    while(j<=high)
        A[k++]=B[j++];//若第二个表未检测完，复制
}//for
void MergeSort(ElemType A[l,int low,int high){
    if(1ow<high){
        int mid=(low+high)/2;//从中间划分两个子序列
        MergeSort(A,low,mid);//对左侧子序列进行递归排序
        MergeSort(A,mid+1,high);//对右侧子序列进行递归排
        
        Merge(A,low,mid,high);//归并
    }//if
}
```

