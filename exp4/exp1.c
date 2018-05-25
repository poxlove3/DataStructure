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

int Swap(Entry *D,int i,int j) 
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
		Swap(list -> D,minIndex,startIndex);
		startIndex++;
	}
}

void bubbleSort(List *list)
{
	int i = 0;
	int j = 0;
	int n = list -> n;
	int isSwap = 0;
	for (j = n;j > 1;j--)
	{
		for(i = 0;i < j - 1;i++)
		{
			if (list -> D[i].key > list -> D[i + 1].key)
			{
				Swap(list -> D,i,i + 1);
				isSwap = 1;
			}
		}
		if (isSwap == 0)
		{
			break;
		}
	}
}

int Part(List *list,int low,int high)
{
	int i = low;
	int j = high + 1;
	Entry pivot = list -> D[low];
	do
	{
		do {i++;}while(list -> D[i].key < pivot.key);
		do {j--;}while(list -> D[i].key > pivot.key);

		if (i < j)
		{
			Swap(list -> D,i,j);
			//printf("%s\n", "yes");
			/* code */
		}
	}while(i < j);
	Swap(list -> D,low,j);
	//printfArray(*list);
	return j;
}

void quickSort(List *list,int low,int high)
{
	int k;
	if (low < high)
	{
		k = Part(list,low,high);
		printf("%d\n",k);
		printf("%s\n", "yes");
		quickSort(list,low, k - 1);
		quickSort(list,k + 1,high);
		/* code */
	}
}

void printfArray(List list)
{
	int i = 0;
	for (i = 0; i < list.n; i++)
	{
		printf("%d\n",list.D[i].key);
		/* code */
	}
}

int main(int argc, char const *argv[])
{
	int i = 0;
	List list;
	int num = 0;
	printf("%s\n","please input the number of list...");
	scanf("%d",&num);
	list.n = num;
	for(i = 0;i < num;i++)
	{
		list.D[i].key = rand()%30;
		printf("%d ",list.D[i].key);
	}
	printf("\n");
	quickSort(&list,0,num - 1);
	//bubbleSort(&list);
	//easyChoseSelect(&list);
	for (i = 0; i < num; i++)
	{
		printf("%d ",list.D[i].key);
	}
	return 0;
}