#include <stdio.h>
#include <stdlib.h>

// ����������ڵ�ṹ
typedef struct TreeNode
{
    int data;
    struct TreeNode *left, *right;
} TreeNode;

// �����½ڵ�
TreeNode *createNode(int data)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// ��������Ŀ��
int getTreeWidth(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    // �������ڲ�α���
    TreeNode *queue[1000]; // ��������������Ϊ1000
    int front = 0, rear = 0;

    // ��ʼ��
    queue[rear++] = root;
    int maxWidth = 0;

    // ��α���
    while (front < rear)
    {
        // ��ǰ��Ľڵ���
        int levelWidth = rear - front;
        if (levelWidth > maxWidth)
        {
            maxWidth = levelWidth;
        }

        // ����ǰ������нڵ�
        int i = 0;
        for (i; i < levelWidth; i++)
        {
            TreeNode *current = queue[front++];
            if (current->left)
            {
                queue[rear++] = current->left;
            }
            if (current->right)
            {
                queue[rear++] = current->right;
            }
        }
    }

    return maxWidth;
}

int main()
{
    // ʾ������������
    TreeNode *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);

    int width = getTreeWidth(root);
    printf("���������Ϊ: %d\n", width);

    // �ͷŽڵ��ڴ棨ʡ�ԣ�������Ը�����Ҫ��ӣ�
    return 0;
}
