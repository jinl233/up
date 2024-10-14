#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构
typedef struct TreeNode
{
    int data;
    struct TreeNode *left, *right;
} TreeNode;

// 创建新节点
TreeNode *createNode(int data)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 求二叉树的宽度
int getTreeWidth(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    // 队列用于层次遍历
    TreeNode *queue[1000]; // 假设队列最大容量为1000
    int front = 0, rear = 0;

    // 初始化
    queue[rear++] = root;
    int maxWidth = 0;

    // 层次遍历
    while (front < rear)
    {
        // 当前层的节点数
        int levelWidth = rear - front;
        if (levelWidth > maxWidth)
        {
            maxWidth = levelWidth;
        }

        // 处理当前层的所有节点
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
    // 示例创建二叉树
    TreeNode *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);

    int width = getTreeWidth(root);
    printf("树的最大宽度为: %d\n", width);

    // 释放节点内存（省略，这里可以根据需要添加）
    return 0;
}
