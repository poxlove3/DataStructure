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

typedef struct SingleList
{
    struct Node* first;
    int n;
}SingleList;

typedef int Status;

Status Init(SingleList* L)
{
	Node* p;
    L->first = NULL;
    L->n = 0;
    return OK;
}

Status Insert(SingleList* L,int i,int x)
{
	int j = 0;
	Node* p;
	Node* q;
	if(i < -1 || i > L->n - 1)
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
	if(i > -1)
	{
		q->link = p->link;
		p->link = q;
	}
	else
	{
		q->link = L->first;
		L->first = q;
	}
	L->n = L->n + 1;
	return OK;
}

Status Output(SingleList L)
{
    Node* p;
    if(L.n == 0)
    {
        return ERROR;
    }
    p = L.first->link;
    while(p)
    {
        printf("%d ",p->element);
        p = p->link;
    }
    return OK;
}

void Display(SingleList L)
{
	printf("Now the list is:");
	Output(L);
	printf("\n");
} 

Status Opposite(SingleList* L)
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

Status Merge(SingleList* L1,SingleList* L2)
{
    int index = 0;
	Node* p = L1->first->link;
    Node* q = L2->first->link;
    while(q != NULL)
    {
        while((p != NULL) && (p->element < q->element))
        {
            p = p->link;
            index++;
        }
        Insert(L1,index,q->element);
        index++;
        q = q->link;
    }
    return OK;
}
	
int main()
{
	int i,j = 0;
	int x = 0;
	SingleList list1,list2;
	Init(&list1);
	Init(&list2);
	for(i = 0;i < 10;i++)
	{
		Insert(&list1,i - 1,i);
	}
	for(j = 0;j < 10;j++)
	{
		Insert(&list2,j - 1,j + 5);
	}
	Display(list1);
	Display(list2);
	Opposite(&list1);
	Display(list1);
	Opposite(&list1);
	Display(list1);
	Merge(&list1,&list2);
	Display(list1);
	return 0;
} 
