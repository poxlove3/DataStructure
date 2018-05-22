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

BinaryTreeNode* PreCreateBinaryTree(BinaryTreeNode* BTNode);//���򴴽� 
void PreOrderTransverse(BinaryTreeNode* BinaryTreeRoot);//������� 
BinaryTreeNode* InCreateBinaryTree(BinaryTreeNode* BTNode);
void InOrderTransverse(BinaryTreeNode* BinaryTreeRoot);
BinaryTreeNode* PostCreateBinaryTree(BinaryTreeNode* BTNode);
void PostOrderTransverse(BinaryTreeNode* BinaryTreeRoot);

int GetBTreeLeafNodesTotal(BinaryTreeNode* BinaryTreeRoot);//�ݹ鷽ʽ��Ҷ�ӽڵ���� 
int GetBTreeNodesTotal(BinaryTreeNode* BinaryTreeRoot);//�ݹ鷽ʽ��ڵ����� 
int GetBTeeeDepth(BinaryTreeNode* BinaryTreeRoot);

BinaryTreeNode* Exchange(BinaryTreeNode* BinaryTreeNode);

int main()
{
    BinaryTreeNode* BTree;
    BTree = PreCreateBinaryTree(BTree);
    PostOrderTransverse(BTree);
    printf("\n");
    printf("%d\n",GetBTreeLeafNodesTotal(BTree));
    printf("%d\n",GetBTreeNodesTotal(BTree));
    printf("%d\n",GetBTeeeDepth(BTree));

    BTree = Exchange(BTree);
    PostOrderTransverse(BTree);
    return 0;
}
BinaryTreeNode* Exchange(BinaryTreeNode* BinaryTreeRoot)
{
    if(BinaryTreeRoot->lChild == NULL && BinaryTreeRoot->rChild == NULL)
    {
        return BinaryTreeRoot;
    }
    BinaryTreeNode* temp = NULL;
    if(BinaryTreeRoot->lChild != NULL || BinaryTreeRoot->rChild != NULL)
    {
        BinaryTreeRoot->lChild = temp;
        BinaryTreeRoot->lChild = BinaryTreeRoot->rChild;
        BinaryTreeRoot->rChild = temp;
    }
    else
    {
        Exchange(BinaryTreeRoot->lChild);
        Exchange(BinaryTreeRoot->rChild);
    }
}

int GetBTeeeDepth(BinaryTreeNode* BinaryTreeRoot)
{
    int lDepth;
    int rDepth;
    if(BinaryTreeRoot == NULL)
    {
        return 0;
    }
    else
    {
        lDepth = GetBTeeeDepth(BinaryTreeRoot->lChild);
        rDepth = GetBTeeeDepth(BinaryTreeRoot->rChild);
    }

    return (((lDepth > rDepth) ? lDepth : rDepth) + 1);
}

int GetBTreeLeafNodesTotal(BinaryTreeNode* BinaryTreeRoot)
{
	if(BinaryTreeRoot == NULL)
    {
        return 0;
    }
    if(BinaryTreeRoot->lChild == NULL && BinaryTreeRoot->rChild == NULL)
    {
        return 1;
    }

    return(GetBTreeLeafNodesTotal(BinaryTreeRoot->lChild) + GetBTreeLeafNodesTotal(BinaryTreeRoot->rChild));
}

int GetBTreeNodesTotal(BinaryTreeNode* BinaryTreeRoot)
{
	if(BinaryTreeRoot == NULL)
    {
        return 0;
    }	
    else
    {
        return(GetBTreeNodesTotal(BinaryTreeRoot->lChild) + GetBTreeNodesTotal(BinaryTreeRoot->rChild) + 1);
    }
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
