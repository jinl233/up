#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode {
    double data;
    struct LinkNode *next;
} LinkNode, *LinkList;

// 合并降序链表L1和L2，并按升序输出
LinkList mergeAndSort(LinkList L1, LinkList L2) {
    LinkNode *p1 = L1->next; // 指向L1的第一个元素（跳过头节点）
    LinkNode *p2 = L2->next; // 指向L2的第一个元素（跳过头节点）
    
    // 创建结果链表L，设置头节点
    LinkList L = (LinkList)malloc(sizeof(LinkNode));
    L->next = NULL;
    LinkNode *current = L; // 用于追踪结果链表的尾部节点
    
    while (p1 && p2) {
        if (p1->data > p2->data) {
            current->next = p2;
            p2 = p2->next;
        } else {
            current->next = p1;
            p1 = p1->next;
        }
        current = current->next; // 移动到新链表的末尾
    }
    
    // 若其中一个链表遍历完，将另一个链表剩余部分连接到新链表
    current->next = (p1 != NULL) ? p1 : p2;
    
    return L; // 返回合并后的新链表
}

// 打印链表
void printList(LinkList L) {
    LinkNode *current = L->next; // 跳过头节点
    while (current) {
        printf("%.2f ", current->data);
        current = current->next;
    }
    printf("\n");
}

// 创建降序链表并插入元素
LinkList createDescendingList(double arr[], int n) {
    LinkList L = (LinkList)malloc(sizeof(LinkNode));
    L->next = NULL;
    for (int i = 0; i < n; i++) {
        LinkNode *node = (LinkNode *)malloc(sizeof(LinkNode));
        node->data = arr[i];
        node->next = L->next;
        L->next = node;
    }
    return L;
}

int main() {
    double arr1[] = {9.0, 7.5, 5.3, 2.1};
    double arr2[] = {8.4, 6.2, 4.0, 3.3};
    
    LinkList L1 = createDescendingList(arr1, 4);
    LinkList L2 = createDescendingList(arr2, 4);
    
    printf("链表 L1: ");
    printList(L1);
    
    printf("链表 L2: ");
    printList(L2);
    
    LinkList result = mergeAndSort(L1, L2);
    
    printf("合并后的链表（升序）: ");
    printList(result);
    
    return 0;
}

