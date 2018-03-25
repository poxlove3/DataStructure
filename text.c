#include <stdio.h>
#include <stdlib.h>
#define ERROR 0
#define OK 1
#define Overflow 2
#define Underflow 3
#define NotPresent 4
#define Duplicate 5

typedef struct Node
{
    int element;
    struct Node* link;
}Node;

typedef struct headerList
{
    struct Node* head;
    int n;
}headerList;

typedef int Status;

Status Init(headerList* L)
{
	Node* Head;
	Node* pNode;
	Head = (Node*)malloc(sizeof(Node));
	pNode = (Node*)malloc(sizeof(Node));
	L->head = pNode; 
	pNode->link = Head;
	Head->link = NULL;
	L->n = 0;
	return OK;
}

Status Insert(headerList* L,int i,int x)
{
	Node* Head;
	Node* pNode;
//	Head = malloc(sizeof(Node));
//	pNode = malloc(sizeof(Node));
	Head = (Node*)malloc(sizeof(Node));
	pNode = (Node*)malloc(sizeof(Node));
	pNode = L->head;
    pNode->link = Head;
	int j = 0;
	Node* p;
	Node* q;
	if(i < 0 || i > L->n)
	{
		printf("love ms\n");
		return ERROR;	
	}	
	p = Head;
	for(j = 0;j < i;j++)
	{
		p = p->link;
	}
	//q = malloc(sizeof(Node));
	q = (Node*)malloc(sizeof(Node));
	q->element = x;
	if(p->link == NULL)
	{
		p->link = q;
	}
	q->link = p->link;
	p->link = q;
	L->n++;
	//printf("now the n's value is%d",L->n); 
	return OK;
}

int main()
{
	int i = 0;
	headerList list;
	Init(&list);
	for(i = 0;i < 10;i++)
	{
		Insert(&list,i ,i);
		printf("the main%d",i);
	}
	return 0;
}
