#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100000

typedef struct HFMTNode
{
    char Data;
    int w;
    int parent,lChild,rChild;
}HFMTNode;

void CreateHFMTree(HFMTNode Ht[],int N);
void Output(HFMTNode Ht[]);

int main() 
{
    int i = 0;
    HFMTNode HT[52];
    for(i = 1;i < 27 ;i++)
    {
    	HT[i].Data = (char)(i + 96);
        //scanf("%c",&HT[i].Data);
        //printf("%c",HT[i].Data);
    }
	CreateHFMTree(HT,26);
    Output(HT);	
}

void Output(HFMTNode Ht[])
{
    int i = 0;
    for(i = 1;i <= 26;i++)
    {
    	printf("my id is %d\n",i);
        printf("my parent is %d and my data is %c\n",Ht[i].parent,Ht[i].Data);
        printf("\n\n\n\n");
    }
    for(i = 27;i < 52;i++)
    {
        printf("my id is %d\n",i);
        printf("my lchild is %d and my rchild is %d\n",Ht[i].lChild,Ht[i].rChild);
        printf("my parent is %d and my data is %c\n",Ht[i].parent,Ht[i].Data);
        printf("\n\n\n\n");
    }
}

void CreateHFMTree(HFMTNode Ht[],int N)
{
    int i,j,k,lmin,rmin;
    int min1,min2;
    int MAX;
    for(i = 1;i < 2 * N;i++)
    {
        Ht[i].parent = Ht[i].lChild = Ht[i].rChild = -1;
    }

    for(i = N + 1;i < 2 * N;i++)
    {
        min1 = min2 = MAX_SIZE;
        lmin = rmin = -1;
        for(k = 1;k <= i - 1;k++)
        {
            if(Ht[k].parent == -1)
            {
                if(Ht[k].w < min1)
                {
                    min2 = min1;
                    rmin = lmin;
                    min1 = Ht[k].w;
                    lmin = k;
                }
                else if(Ht[k].w < min2)
                {
                    min2 = Ht[k].w;
                    rmin = k;
                }
            }
            Ht[lmin].parent = i;
            Ht[rmin].parent = i;
            Ht[i].w = Ht[lmin].w + Ht[rmin].w;
            Ht[i].lChild = lmin;
            Ht[i].rChild = rmin;
        }
    }
}
