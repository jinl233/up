#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode {
    double data;
    struct LinkNode *next;
} LinkNode, *LinkList;

// �ϲ���������L1��L2�������������
LinkList mergeAndSort(LinkList L1, LinkList L2) {
    LinkNode *p1 = L1->next; // ָ��L1�ĵ�һ��Ԫ�أ�����ͷ�ڵ㣩
    LinkNode *p2 = L2->next; // ָ��L2�ĵ�һ��Ԫ�أ�����ͷ�ڵ㣩
    
    // �����������L������ͷ�ڵ�
    LinkList L = (LinkList)malloc(sizeof(LinkNode));
    L->next = NULL;
    LinkNode *current = L; // ����׷�ٽ�������β���ڵ�
    
    while (p1 && p2) {
        if (p1->data > p2->data) {
            current->next = p2;
            p2 = p2->next;
        } else {
            current->next = p1;
            p1 = p1->next;
        }
        current = current->next; // �ƶ����������ĩβ
    }
    
    // ������һ����������꣬����һ������ʣ�ಿ�����ӵ�������
    current->next = (p1 != NULL) ? p1 : p2;
    
    return L; // ���غϲ����������
}

// ��ӡ����
void printList(LinkList L) {
    LinkNode *current = L->next; // ����ͷ�ڵ�
    while (current) {
        printf("%.2f ", current->data);
        current = current->next;
    }
    printf("\n");
}

// ����������������Ԫ��
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
    
    printf("���� L1: ");
    printList(L1);
    
    printf("���� L2: ");
    printList(L2);
    
    LinkList result = mergeAndSort(L1, L2);
    
    printf("�ϲ������������: ");
    printList(result);
    
    return 0;
}

