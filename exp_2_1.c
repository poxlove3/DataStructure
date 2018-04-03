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


int PreOrderTransverse(BinaryTreeNode* BinaryTreeRoot);
int InOrderTransverse(BinaryTreeNode* BinaryTreeRoot);
int PostOrderTransverse(BinaryTreeNode* BinaryTreeRoot);
BinaryTreeNode* PreCreateBinaryTree(BinaryTreeNode* BTNode);
BinaryTreeNode* InCreateBinaryTree(BinaryTreeNode* BTNode);
BinaryTreeNode* PostCreateBinaryTree(BinaryTreeNode* BTNode);

int main()
{
    BinaryTreeNode* BTNodeRoot;
    PreCreateBinaryTree(BTNodeRoot);
    PreOrderTransverse(BTNodeRoot);
    printf("233\n");
    return OK;
}

int PreOrderTransverse(BinaryTreeNode* BinaryTreeRoot)
{
    if(BinaryTreeRoot == NULL)
    {
        return ERROR;
    }
    printf("%c",BinaryTreeRoot->Data);
    PreOrderTransverse(BinaryTreeRoot->lChild);
    PreOrderTransverse(BinaryTreeRoot->rChild);
    return OK;
}

int InOrderTransverse(BinaryTreeNode* BinaryTreeRoot)
{
    if(BinaryTreeRoot == NULL)
    {
        return ERROR;
    }
    InOrderTransverse(BinaryTreeRoot->lChild);
    printf("%c",BinaryTreeRoot->Data);
    InOrderTransverse(BinaryTreeRoot->rChild);
    return OK;
}

int PostOrderTransverse(BinaryTreeNode* BinaryTreeRoot)
{
    if(BinaryTreeRoot == NULL)
    {
        return ERROR;
    }
    PostOrderTransverse(BinaryTreeRoot->lChild);
    PostOrderTransverse(BinaryTreeRoot->rChild);
    printf("%c",BinaryTreeRoot->Data);
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
}

