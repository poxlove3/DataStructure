#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0

typedef struct BinaryTreeNode
{
    char Data;
    struct BinaryTreeNode* lChild;
    struct BinaryTreeNode* rChild;
}BinaryTreeNode;

BinaryTreeNode* PreCreateBinaryTree(BinaryTreeNode* BTNode);
void PreOrderTransverse(BinaryTreeNode* BinaryTreeRoot);
BinaryTreeNode* InCreateBinaryTree(BinaryTreeNode* BTNode);
void InOrderTransverse(BinaryTreeNode* BinaryTreeRoot);
BinaryTreeNode* PostCreateBinaryTree(BinaryTreeNode* BTNode);
void PostOrderTransverse(BinaryTreeNode* BinaryTreeRoot);

int main()
{
    BinaryTreeNode* BTree;
    BTree = InCreateBinaryTree(BTree);
    PostOrderTransverse(BTree);
    printf("\n");
    return 0;
}

BinaryTreeNode* PreCreateBinaryTree(BinaryTreeNode* BTNode)
{
    char ch;

    ch = getchar();
    if(ch == '#')
    {
        BTNode = NULL;
    }
    else
    {
        BTNode = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
        BTNode->Data = ch;
        BTNode->lChild = PreCreateBinaryTree(BTNode->lChild);
        BTNode->rChild = PreCreateBinaryTree(BTNode->rChild);
    }
    return BTNode;
}

void PreOrderTransverse(BinaryTreeNode* BinaryTreeRoot)
{
    if(BinaryTreeRoot == NULL)
    {
        return;
    }
    printf("%c",BinaryTreeRoot->Data);
    PreOrderTransverse(BinaryTreeRoot->lChild);
    PreOrderTransverse(BinaryTreeRoot->rChild);
}

BinaryTreeNode* InCreateBinaryTree(BinaryTreeNode* BTNode)
{
    char ch;
    ch = getchar();
    if(ch == '#')
    {
        BTNode = NULL;
    }
    else
    {
        BTNode = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
        BTNode->lChild = InCreateBinaryTree(BTNode->lChild);
        BTNode->Data = ch;
        BTNode->rChild = InCreateBinaryTree(BTNode->rChild);
    }
    return BTNode;
}

void InOrderTransverse(BinaryTreeNode* BinaryTreeRoot)
{
    if(BinaryTreeRoot == NULL)
    {
        return;
    }
    InOrderTransverse(BinaryTreeRoot->lChild);
    printf("%c",BinaryTreeRoot->Data);
    InOrderTransverse(BinaryTreeRoot->rChild);
}

BinaryTreeNode* PostCreateBinaryTree(BinaryTreeNode* BTNode)
{
    char ch;
    ch = getchar();
    if(ch == '#')
    {
        BTNode = NULL;
    }
    else
    {
        BTNode = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
        BTNode->lChild = InCreateBinaryTree(BTNode->lChild);
        BTNode->rChild = InCreateBinaryTree(BTNode->rChild);
        BTNode->Data = ch;
    }
}

void PostOrderTransverse(BinaryTreeNode* BinaryTreeRoot)
{
    if(BinaryTreeRoot == NULL)
    {
        return;
    }
    PostOrderTransverse(BinaryTreeRoot->lChild);
    PostOrderTransverse(BinaryTreeRoot->rChild);
    printf("%c",BinaryTreeRoot->Data);
}