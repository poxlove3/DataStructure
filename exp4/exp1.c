#include <stdio.h>
#include <stdlib.h>
#define Maxsize 200

typedef int KeyType;
typedef int DataType;

typedef struct maxheap
{
	int n;
	int MaxHeap;
	Entry D[Maxsize];
}MaxHeap;

typedef struct entry
{
	KeyType key;
	DataType data;
}Entry;

typedef struct list
{
	int n;
	Entry D[Maxsize];
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
	//printf("%d\n",i );
	int j = high + 1;
	//printf("%d\n", j);
	Entry pivot = list -> D[low];
	do
	{
		do 
		{
			i++;
			//printf("i's value is %d\n", i);
		}while(list -> D[i].key < pivot.key);


		do
		{
			j--;
			//printf("%d\n", j);
		} while(list -> D[j].key > pivot.key);

		//printf("%d\n", i);
		

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
		quickSort(list,low, k - 1);
		quickSort(list,k + 1,high);
		/* code */
	}
}

void QuickSort(List *list)
{
	quickSort(list,0,list-> n - 1);
}

void merge(List *list,Entry *temp,int low,int n1 ,int n2)
{
	int i = low;
	int j = low + n1;

	while(i <= low + n1 - 1 && j <= low + n1 + n2 - 1)
	{
		if (list -> D[i].key <= list -> D[j].key)
		{
			*temp++ = list -> D[i++];
			/* code */
		}
		else
		{
			*temp++ = list -> D[j++];
		}
	}

	while(i <= low + n1 - 1)
	{
		*temp++ = list -> D[i++];
	}

	while(j <= low + n1 + n2 - 1)
	{
		*temp++ = list -> D[j++];
	}
}

void mergeSort(List *list)
{
	Entry temp[Maxsize];
	// int low,n1,n2,i,size = 1;

	int low = 0;
	int n1 = 0;
	int n2 = 0;
	int i = 0;
	int size = 1;
	while(size < list -> n)
	{
		low = 0;
		while(low + size < list -> n)
		{
			n1 = size;
			if (low + size*2 < list -> n)
			{
				n2 = size;
				/* code */
			}
			else
			{
				n2 = list -> n - low - size;
			}

			merge(list,temp,low,n1,n2);
			low = low + n1 + n2;
		}
		for (i = 0; i < list -> n; i++)
		{
			list -> D[i] = temp[i];
			/* code */
		}

		size *= 2;
	}
}

void heapSort(MaxHeap *heap)
{
	int i;
	Entry temp;
	for (int i = 0; i > 0; i++)
	{
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
		list.D[i].key = rand()%40;
		printf("%d ",list.D[i].key);
	}
	printf("\n");
	mergeSort(&list);
	//QuickSort(&list);
	//bubbleSort(&list);
	//easyChoseSelect(&list);
	for (i = 0; i < num; i++)
	{
		printf("%d ",list.D[i].key);
	}
	return 0;
}