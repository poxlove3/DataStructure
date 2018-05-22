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

typedef struct ENode
{
	int adjVex;
	EleType w;
	struct ENode* nextArc;
}ENode;
typedef struct LGraph
{
	int n;
	int e;
	ENode **a;
}LGraph;

Status Init(LGraph *lg,int nSize)
{
	int i;
	lg -> n = nSize;
	lg -> e = 0;
	lg -> a = malloc(nSize*sizeof(ENode*));
	if (!lg -> a)
	{
		return ERROR;
		/* code */
	}
	else
	{
		for (i = 0;i < lg-> n;i++)
		{
			lg -> a[i] = NULL;
			/* code */
		}
		return OK;
	}
}

void Destroy(LGraph *lg)
{
	int i = 0;
	ENode *p = NULL,*q = NULL;
	for(i = 0;i < lg -> n;i++)
	{
		p = lg -> a[i];
		q = p;
		while(p)
		{
			p = p -> nextArc;
			free(q);
			q = p;

		}
	}
	free(lg -> a);
}

// Status Display(LGraph *lg)
// {
// 	int i = 0;
// 	for (i = 0; i < lg -> n; i++)
// 	{
// 		printf("%d\n",(lg -> a)-> adjVex);
// 		/* code */
// 	}
// }

Status Search(LGraph *lg,int u,int v)
{
	ENode *p;
	int len = (lg -> n) - 1;
	if (u < 0||v < 0||u > len||v > len||u == v)
	{
		/* code */
		return ERROR;
	}

	p = lg -> a[u];
	while(p && p -> adjVex != v)
	{
		p = p -> nextArc;
	}
	if (!p)
	{
		return ERROR;
		/* code */
	}
	return OK;
}

Status Insert(LGraph *lg,int u,int v,EleType w)
{
	ENode *p;
	int len = (lg -> n) - 1;
	if (u < 0||v < 0||u > len||v > len||u == v)
	{
		/* code */
		return ERROR;
	}
	if (Search(lg,u,v) == 1)
	{
		return Duplicate;
		/* code */
	}
	p = malloc(sizeof(ENode));
	p -> adjVex = v;
	p -> w = w;
	p -> nextArc = lg -> a[u];

	lg -> a[u] = p;
	lg -> e++;
	return OK;
}

Status Remove(LGraph *lg,int u,int v)
{
	ENode *p = NULL,*q = NULL;
	int len = (lg -> n) - 1;
	if (u < 0||v < 0||u > len||v > len||u == v)
	{
		/* code */
		return ERROR;
	}
	p = lg -> a[u];
	q = NULL;
	while(p && p -> adjVex != v)
	{
		q = p;
		p = p -> nextArc;
	}
	if (!p)
	{
		return NotPresent;
		/* code */
	}
	else
	{
		lg -> a[u] = p -> nextArc;
	}
	free(p);
	lg -> e--;
	return OK;

}

int main(int argc, char const *argv[])
{
	LGraph Graph;	
	Init(&Graph,5);
	//Display(&Graph);
	Destroy(&Graph);
	return 0;
}