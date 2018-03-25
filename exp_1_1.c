#include <stdio.h>
#include <stdlib.h>
#define ERROR 0
#define OK 1
#define Overflow 2
#define Underflow 3
#define NotPresent 4
#define Duplicate 5

typedef struct
{
 	int n;
 	int MaxLength;
 	int* element;
}SeqList;
 
typedef int Status;
Status Init(SeqList* L,int mSize)
{
	L->MaxLength = mSize;
	L->n = 0;
	L->element = malloc(sizeof(int) * mSize);
	if(!L->element)
	{
		return ERROR;
	}
	return OK;
}

Status Find(SeqList* L,int i,int* x)
{
	if(i < 0 || i > L->n - 1)
	{
		return ERROR;
	}
	*x = L->element[i];
	return OK;
}

Status Insert(SeqList* L,int i,int x)
{
	int j;
	if(i < 0 || i > L->MaxLength - 1)
	{
		return ERROR;
	}
	if(L->n == L->MaxLength)
	{
		return ERROR; 
	}
	for(j = L->n - 1;j >= i;j--)
    {
	    L->element[j + 1] = L->element[j];
    }
	L->element[i] = x;
	L->n = L->n + 1;
	return OK;
}

Status Delete(SeqList* L,int i)
{
	int j;
	if(i < 0 || i > L->n - 1)
	{
		return ERROR;
	}
	if(!L->n)
	{
		return ERROR;
	}
	for(j = i + 1;j < L->n;j ++)
	{
		L->element[j - 1] = L->element[j];
	}
	L->n = L->n - 1;
	return OK;
}

Status Output(SeqList L)
{
	int i;
	if(L.n == 0)
	{
		return ERROR;	
	}
	for(i = 0;i <= L.n - 1;i++)
	{
		printf("%d",L.element[i]);
	}
	printf("\n");
	return 0;
} 

void Destory(SeqList *L)
{
	(*L).n = 0;
	(*L).MaxLength = 0;
	free((*L).element);
}

void Display(SeqList L)
{
	printf("Now the list is:");
	Output(L);
	printf("\n");
} 

int main()
{
	int i;
	SeqList list;
	Init(&list,10);
	for(i = 0;i < 9;i++)
	{
		Insert(&list,i - 1,i);
	}
    printf("Now the number of list is %d\n",list.n);
	Display(list);
	Delete(&list,0);
	printf("Now the number of list is %d\n",list.n);
	Display(list);
	Insert(&list,0,9);
	printf("Now the number of list is %d\n",list.n);
	Display(list);
	Destory(&list);
    Display(list);
	return 0; 
}
