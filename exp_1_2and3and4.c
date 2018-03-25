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
    struct Node* first;
    int n;
}headerList;

typedef int Status;

Status Init(headerList* L)
{
	Node* pNode;
	pNode = malloc(sizeof(Node));
	L->first = pNode;
	pNode->link = NULL;
	L->n = 0;
	return OK;
}

Status Insert(headerList* L,int i,int x)
{
	Node* p;
	Node* q;
	int j = 0;
	if(i < 0||i > L->n)
	{
		return ERROR; 
	}	
	p = L->first;
	for(j = 0;j < i;j++)
	{
		p = p->link;
	}
	q = malloc(sizeof(Node));
	q->element = x;
	q->link = p->link;
	p->link = q;
	L->n++;
	return OK; 
}

Status Output(headerList L)
{
    Node* p;
    if(L.n == 0)
    {
        return ERROR;
    }
    p = L.first->link;
    if(p == NULL)
    {
    	return ERROR;
	}
    while(p)
    {
        printf("%d ",p->element);
        p = p->link;
    }
    return OK;
}

void Display(headerList L)
{
	printf("Now the list is:");
	Output(L);
	printf("\n");
} 

Status Find(headerList L,int i,int* x)
{
	int j = 0;
    Node* p;
    if(i < 0 || i > (L.n - 1))
    {
        return ERROR;
    }
    p = L.first->link;
    for(j = 0;j <= i;j++)
    {
        p = p->link;
    }
    *x = p->element;
}

Status Delete(headerList* L,int i)
{
	int j = 0;
    Node* p;
    Node* q;
    if(L->n == 0)
    {
        return ERROR;                                  
    }
    if(i < 0 || i > L->n - 1)
    {
        return ERROR;
    }
    p = L->first;
    q = L->first;
    for(j = 0;j < i - 1;j++)
    {
        q = q->link;
    }
   	p = q->link; 
	q->link = p->link;
    free(p);
    L->n--;
    return OK;
}

Status Reverse(headerList* L)
{
	Node* p;
    Node* q;
    p = L->first->link;
	L->first->link = NULL;  
    while(p)  
    {    
        q = p;  
        p = p->link;  
        q->link = L->first->link;
		L->first->link = q;   
    }	
} 

Status Destory(headerList* L)
{
    Node* p;
    while(L->first->link)
    {
        p = L->first->link->link;
        free(L->first->link);
        L->first->link = p;
    }
    return 0;
}

Status SortList(headerList* L)
{
	if(L->first->link == NULL || L->first->link->link == NULL)
	{
		Display(*L);
	}	
	else
	{
		int flag = 0;
	}
}

int main()
{
	int i,j,x = 0;
	headerList list;
	Init(&list);
	Display(list);
	for(i = 0;i < 10;i++)
	{
		j = rand() % 100;
		Insert(&list,i,j);
	}
	Display(list);
	Reverse(&list);
	Display(list);
	Find(list,5,&x);
	printf("the x's element is%d\n",x);
	Delete(&list,4);
	Display(list);
	Destory(&list);
	Display(list);
	return 0;
}

