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

void PreOrderTransverse(BinaryTreeNode* BinaryTreeRoot);
void InOrderTransverse(BinaryTreeNode* BinaryTreeRoot);
void PostOrderTransverse(BinaryTreeNode* BinaryTreeRoot);
BinaryTreeNode* PreCreateBinaryTrlsee(BinaryTreeNode* BTNode);
BinaryTreeNode* InCreateBinaryTree(BinaryTreeNode* BTNode);
BinaryTreeNode* PostCreateBinaryTree(BinaryTreeNode* BTNode);

int main()
{
    BinaryTreeNode* BTree;
    BinaryTreeNode* BBTree;
    BBTree = InCreateBinaryTree(BTree);
    PreOrderTransverse(BBTree);
    return OK;
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
    return;
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
    return;
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
    return;
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
    return BTNode;
}
