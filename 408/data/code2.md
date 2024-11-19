#### 头插法建立单链表
```c
LinkList List_HeadInsert(LinkList &L)
{ // 头插法建立单链表
	LNode *s;
	int x;
	L = (LinkList)malloc(sizeof(LNode)); // 创建头结点
	L->next = NULL;						 // 初始为空链表
	scanf(“% d”, &x);					 // 输入结点的值
	While(x != -1)
	{										// 输入-1 表示结束
		s = (LNode *)malloc(sizeof(LNode)); // 创建新结点
		s->data = x;
		s->next = L->next;
		L->next = s; // 将新结点插入表中,L 为头指针
		scanf(“% d”, &x);
	}
	return L;
}
```

#### 尾插法建立单链表
```c
LinkList List_TailInsert(LinkList &L)
{ // 尾插法建立单链表
	LNode *s, *r = L;
	int x;
	L = (LinkList)malloc(sizeof(LNode)); // 创建头结点
	scanf(“% d”, &x);					 // 输入结点的值
	while (x != -1)
	{ // 输入-1 表示结束
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		// r 指向新的表尾结点
		scanf(“% d”, &x);
	}
	r->next = NULL; // 尾结点指针置空
	return L;
}
```
#### KMP 算法

```c
int Index_KMP(SString S, SString T, int next[])
{
	int i = 1, j = 1;
	while (i <= S.length && j <= T.length)
	{
		if (j == 0 || S.ch[i] == T.ch[j])
		{
			++i;
			++j; // 继续比较后继字符
		}
		else
			j = next[j];  // 模式串向右移动
		if (j > T.length) // 匹配成功
			return i - T.length;
		else
			return 0;
	}
}
```

#### 求模式串 T 的 next 数组

```c
void get_next(SString T, int next[])
{
	int i = 1, j = 0;
	next[1] = 0;
	while (i < T.length)
	{
		if (j == 0 || T.ch[i] == T.ch[j])
		{
			++i;
			++j;
			// 若 pi=pj,则 next[j+1]=next[j]+1
			next[i] = j;
		}
		Else
			// 否则令 j=next[j],循环继续
			j = next[j];
	}
}
```

#### 先序遍历

```c
void PreOrder(BiTree T)
{
	if (T ! = NULL)
	{
		visit(T);			 // 访问根结点
		PreOrder(T->lchild); // 递归遍历左子树
		PreOrder(T->rchild); // 递归遍历右子树
	}
	void PreOrder2(BiTree T)
	{
		InitStack(S);
		BiTree p = T; // 初始化栈 s,p 是遍历指针
		while (p || !IsEmpty(s))
		{ // 栈不空或 p 不空时循环
			if (p)
			{
				/ l 一路向左
						visit(p);
				Push(s, p);	   // 访问当前结点,并入栈
				p = p->lchild; // 左孩子不空,一直向左走
			}
			else
			{				   // 出栈,并转向出栈结点的右子树
				Pop(s, p);	   // 栈顶元素出栈
				p = p->rchild; // 向右子树走,p 赋值为当前结点的右孩子
			} // 返回 while 循环继续进入 if-else 语句
		}
	}
}
```
#### 中序遍历


```c
void InOrder(BiTree T)
{
	if (T != NULL)
	{
		InOrder(T->lchild); // 递归遍历左子树
		visit(T);			// 访问根结点
		InOrder(T->rchild); // 递归遍历右子树
	}
}
void InOrder2(BiTree T)
{
	InitStack(S);
	BiTree p = T; // 初始化栈 s,p 是遍历指针
	while (p || !IsEmpty(s))
	{ // 栈不空或 p 不空时循环
		if (p)
		{				// 一路向左
			Push(s, p); // 访问当前结点,并入栈
			p = p->lchild;
			// l 左孩子不空, 一直向左走
		}
		else
		{ // 出栈,并转向出栈结点的右子树
			Pop(s, p);
			visit(p);	   // 栈顶元素出栈
			p = p->rchild; // 向右子树走,p 赋值为当前结点的右孩子
		} // 返回 while 循环继续进入 if-else 语句
	}
}
```

#### 后序遍历

```c
void PostOrder(BiTree T)
{
	if (T ! = NULL)
	{
		PostOrder(T->lchild); // 递归遍历左子树
		PostOrder(T->rchild); // 递归遍历右子树
		visit(T);			  // 访问根结点
	}
}
void PostOrder2(BiTree T)
{
	InitStack(S);
	p = T;
	r = NULL;
	while (p != NULL || !IsEmpty(s))
	{
		if (p != NULL)
		{
			// 走到最左边
			push(S, p);
			p = p->lchild;
		}
		else
		{
			// 向右
			GetTop(S, p);
			// 读栈顶节点(非出栈)
			if (p->rchild && p->rchild != r)
			{ // 若右子树存在,且未被访问过
				p = p->rchild;
				// 转向右
			}
			else
			{
				// 否则弹出结点并访问
				pop(S, p);
				visit(p->data); // 访问该结点
				r = p;
				// 记录最近访问的结点
				p = NULL;
				// 结点访问完后,重置 p 指针
			}
		}
	}
}
```

#### 层序遍历

```c
void Levelorder(BiTree T)
{
	LinkQueue Q;
	InitQueue(Q); // 初始化辅助队列
	BiTree p;
	EnQueue(Q, T); // 将根结点入队
	while (!IsEmpty(Q))
	{ // 队列不空则循环
		DeQueue(Q, p);
		l			  // 队头结点出队
			visit(p); // 访问出队结点
		if (p->lchild != NULL)
			EnQueue(Q, p->lchid); // 左孩子入队
		if (p->rchild != NULL)
			EnQueue(Q, p->rchild); // 右孩子入队
	}
}
```

#### BFS 广度优先遍历

```c
bool visited[max] // 标记数组
	void
	BFSTraverse(Graph G)
{								   // 对图 G 进行广度优先遍历
	for (i = 0; i < G.vexnum; ++i) // 访问标记数组初始化
		visited[i] = FALSE;
	InitQueue(Q);				   // 初始化辅助队列 O
	for (i = 0; i < G.vexnum; ++i) // 从 0 号顶点开始遍历
		if (!visited[i])		   // 对每个连通分量调用一次 BFS
			BFS(G, i);			   // vi 未访问过,从 vi 开始 BFS
}
void BFS(Graph G, int v)
{					   // 从顶点 v 出发,广度优先遍历图 G
	visit(v);		   // 访问初始顶点 v
	visited[v] = TRUE; // 对 v 做已访问标记
	Enqueue(Q, v);	   // 顶点 v 入队列 Q
	while (!isEmpty(Q))
	{
		DeQueue(Q, v); // 顶点 v 出队列
		for (w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w))
		{ // 检测 v 所
			有邻接点
			if (!visited[w])
			{					   // w 为 v 的尚未访问的邻接顶点
				visit(w);		   // 访问顶点 w
				visited[w] = TRUE; // 对 w 做己访问标记
				EnQueue(Q, w);	   // 顶点 w 入队列
			}
			/ / if
		} // for
	} // while
}
```

#### DFS 深度优先遍历

```c
bool visited[max] // 标记数组
	void
	DFS(Graph G, int v)
{					   // 从顶点 v 出发,深度优先遍历图 G
	visit(v);		   // 访问顶点 v
	visited[v] = TRUE; // 设已访问标记
	for (w = FirstNeighbor(G, v); w >= 0; w = NextNeighor(G, v, w))
		if (!visited[w])
		{			   // w 为 u 的尚未访问的邻接顶点
			DFS(G, w); // if
		}
}
void DFSTraverse(Graph G)
{ // 对图 G 进行深度优先遍历
	for (v = 0; v < G.vexnum; ++v)
		visited[v] = FALSE;		   // 初始化已访问标记数据
	for (v = 0; v < G.vexnum; ++v) // 本代码中是从 v=0 开始遍历
		if (!visited[v])
			DFS(G, v);
}
```

#### 折半查找

```c
intsearch_Bin(SSTable ST, KeyTypekey)
{
	// 在有序表中折半查找其关键字等于 key 的数据元素
	// 若找到,则函数值为该元素在表中的位置,否则为 0.
	low = 1;
	high = ST.length; // 置查找区间初值
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (key == ST.R[mid].key)
			return mid; // 找到待查元素
		else if (key < ST.R[mid].key)
			high = mid - 1; // 继续在前一子表进行查找
		else
			low = mid + 1; // 继续在后一子表进行查找
	}
	return 0; // 表中不存在待查元素
}
```

#### 快速排序

```c
void QuickSort(ElemType A[],int low,int high){
	if (low < high)
	{
		// 递归跳出的条件
		// Partition ()是划分操作,将表 A[low...high]划分为满足上述条件的两个子表
		int pivotpos = Partition(A, low, high); // 划分
		QuickSort(A, low, pivotpos - 1);		// 依次对两个子表进行递归排序
		Quicksort(A, pivotpos + 1, high);
	}
}
int Partition(ElemType A[], int low,int high){//一趟划分
	ElemType pivot = A[low];				  // 将当前表中第一个元素设为枢轴,对表进行划分
	while (low < high)
	{ // 循环跳出条件
		while (low < high && A[high] >= pivot)
			--high; // 将比枢轴小的元素移动到左端
		A[low] = A[high];
		while (low < high && A[low] <= pivot)
			++low;
		A[high] = A[low]; // 将比枢轴大的元素移动到右端
	}
	A[low] = pivot; // 枢轴元素存放到最终位置
}
```
#### 归并排序

```c
void MergeSort(ElemType A[], int low, int high)
{
	if (low < high)
	{ // 从中间划分两个子序列
		int mid = (low + high) / 2;
		Mergesort(A, low, mid);		 // 对左侧子序列进行递归排序
		MergeSort(A, mid + 1, high); // 对右侧子序列进行递归排序
		Merge(A, low, mid, high);	 // 归并
	}
}
ElemType *B = (ElemType *)malloc((n + 1) * sizeof(ElemType)); // 辅助数组 B
void Merge(ElemType A[], int low, int mid, int high)
{				 // 表 A 的两段 A【low..mid】和 A【mid + 1..high】各自有序, 将它们合并成一个有序表 for (int k = low; k <= high; k++)
	B[k] = A[k]; // 将 A 中所有元素复制到 B 中
	for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++)
	{
		if (B[i] <= B[j])  // 比较 B 的左右两段中的元素
			A[k] = B[i++]; // 将较小值复制到 A.中
		else
			A[k] = B[j++];
	}/ /for
while(i<=mid)
A[k++]=B[i++];//若第一个表未检测完,复制
	while (j <= high)
		A[k++] = B[j++]; // 若第二个表未检测完,复制
}
```
#### 拓扑排序

```c
bool TopologicalSort(Graph G)
{
	InitStack(S);
	// 初始化栈,存储入度为 0 的顶点
	for (int i = 0; i < G.vexnum; i++)
	{
		if (indegree[i] == 0)
			Push(S, i);
		// 将所有入度为 0 的顶点进栈
	}
	int count = 0;
	// 计数,记录当前已经输出的顶点数
	while (!IsEmpty(S))
	{
		// 栈不空,则存入
		Pop(S, i);
		// 栈顶元素出栈
		print[count++] = i;
		// 输出顶点 i
		for (p = G.vertices[i].firstarc; p; p = p =->nextarc)
		{
			// 将所有 i 指向的顶点的入度减 1,并将入度为 0 的顶点压入栈
			v = p->adjvex;
			if (!(--indegree[v]))
				Push(S, v);
			// 入度为 0,则入栈
		}
	}
	if (count < G.vexnum)
		return false;
	// 排序失败
	else
		return true;
	// 排序成功
}
```
