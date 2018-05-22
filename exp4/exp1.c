#include <stdio.h>
#include <stdlib.h>
#define Maxsiaze 200

typedef int KeyType;
typedef int DataType;

typedef struct entry
{
	KeyType key;
	DataType data;
}Entry;

typedef struct list
{
	int n;
	Entry D[Maxsiaze];
}List;

int findMin(List list,int startIndex)
{
	int i;
	int minIndex = startIndex;
	for(i = minIndex;i < list.n;i++)
	{
		if(list.D[i].key < list.D[minIndex].key)
		{
			minIndex = i;
			/* code */
		}
	}
	return minIndex;
}

int swap(Entry *D,int i,int j) 
{
	if (i == j)
	{
		return 0;
		/* code */
	}
	Entry temp = *(D + i);
	*(D + i) = *(D + j);
	*(D + j) = temp;
}

void easyChoseSelect(List *list)
{
	int minIndex = 0;
	int startIndex = 0;
	while(startIndex < list->n - 1)
	{
		minIndex = findMin(*list,startIndex);
		swap(list -> D,minIndex,startIndex);
		startIndex++;
	}
}

int main(int argc, char const *argv[])
{
	int i = 0;
	List list;
	list.n = 10;
	for(i = 0;i < 10;i++)
	{
		list.D[i].key = rand()%30;
		printf("%d ",list.D[i].key);
	}
	printf("\n");
	easyChoseSelect(&list);
	for (i = 0; i < 10; ++i)
	{
		printf("%d ",list.D[i].key);
	}
	return 0;
}