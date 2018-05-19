#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1
#define Overflow 2
#define Underflow 3
#define NotPresent 4
#define Duplicate 5
typedef int Status;
typedef int EleType;

typedef struct $
{
	EleType **a;
	int n;
	int e;
	EleType noEage;
}mGraph;
 
Status Init(mGraph *mg,int nSize,EleType noEdgeValue)
{
	int i = 0,j = 0;
	mg -> n = nSize;
	mg -> e = 0;
	mg -> noEage = noEdgeValue;
	mg -> a = malloc(nSize*sizeof(EleType*));
	if(!mg -> a)
	{
		return ERROR;
	}
	for (i = 0; i < mg -> n; i++)
	{
		/* code */
		mg -> a[i] = malloc(nSize*sizeof(EleType));
		for(j = 0; j < mg -> n;j++)
		{
			mg -> a[i][j] = 0;
		}
	}
	return OK;
}

void Destroy(mGraph *mg)
{
	int i = 0;
	for (i = 0; i < mg -> n; i++)
	{
		/* code */
		free(mg -> a[i]);
	}
	free(mg -> a);
}

Status Insert(mGraph *mg,int u,int v,EleType w)
{
	int len = (mg -> n) - 1;
	if (u < 0||v < 0||u > len||v > len||u == v)
	{
		return ERROR;
	}
	if (mg -> a[u][v] != mg ->noEage)
	{
		/* code */
		return Duplicate;
	}
	mg -> a[u][v] = w;
	mg -> e++;
	return OK;
}

Status Search(mGraph *mg,int u,int v)
{
	int len = (mg -> n) - 1;
	if (u < 0||v < 0||u > len||v > len||u == v||mg->a[u][v] == mg->noEage)
	{
		/* code */
		return ERROR;
	}
	return OK;
}

Status Remove(mGraph *mg ,int u,int v,EleType w)
{
	int len = (mg -> n) - 1;
	if (u < 0||v < 0||u > len||v > len||u == v)
	{
		return ERROR;
	}
	if (mg -> a[u][v] == mg ->noEage)
	{
		/* code */
		return NotPresent;
	}
	mg -> a[u][v] = mg->noEage;
	mg -> e--;
	return OK;
}

Status Display(mGraph *mg)
{
	int i = 0,j = 0;
	for (i = 0; i < mg -> n; i++)
	{
		for(j = 0; j < mg -> n; j++)
		{
			printf("%d ",mg -> a[i][j]);
		}
		printf("\n");
		/* code */
	}
}

Status getNum()
{
	int num;
	printf("%s\n","how many element do you have?");
	scanf("%d",&num);
	return num;
}




int main(int argc, char const *argv[])
{
	int num = getNum();
	mGraph Graph;
	Init(&Graph,num,0);
	Display(&Graph);
	return 0;
}