#include <stdio.h>
#include <stdlib.h>
#define ERROR 0
#define OK 1
#define Overflow 2
#define Underflow 3
#define NotPresent 4
#define Duplicate 5
typedef int Status;
typedef struct SeqList
{
 	int n;
 	int MaxLength;
 	int* element;
}SeqList;

Status Init(SeqList* L,int mSize,int number)
{ 
	int j = 0;
    L->MaxLength = mSize;
    L->n = number;
    L->element = malloc(sizeof(int) * mSize);
    for(j = 0;j <= L->n - 1;j++)
    {
        L->element[j] = j;
    }
    if(!L->element)
    {
        return ERROR;
    }
    return OK;
}

Status Opposite(SeqList* L)
{
	int i = 0;
    for (i = 0; i < L->MaxLength / 2; ++i)
    {
        L->element[i] = L->element[i] ^ L->element[L->MaxLength - i - 1];
        L->element[L->MaxLength - i - 1] = L->element[i] ^ L->element[L->MaxLength - i - 1];
        L->element[i] = L->element[i] ^ L->element[L->MaxLength - i - 1];
    }
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

int main()
{
    SeqList list;
    Init(&list,10,10);
    printf("Old linear list:\n");
    Output(list);
    Opposite(&list);
    printf("New linear list:\n");
    Output(list);
    free(list.element);
    //free(list);
    return 0;
}

/*用异或交换两个变量的值的代码
a = a ^ b;
b = a ^ b;
a = a ^ b;
*/
