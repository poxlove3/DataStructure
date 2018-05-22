#include <stdlib.h>
#include <stdio.h>

typedef struct pNode
{
    int coef;//系数
    int exp;//指数
    struct pNode *link;
}pNode;

typedef struct polynominal
{
    struct pNode *head;
}polynominal;

void Create(polynominal *p);
void 

int main()
{
    return 0;
}

void Create(polynominal *p)
{
    pNode* pn;
    pNode* q;
    pNode* pre;
    p->head = malloc(sizeof(pNode));
    p->head->exp = -1;
    p->head->link = NULL;
    for(;;)
    {
        pn = malloc(sizeof(pNode));
        printf("coef:\n");
        scanf("%d",&pn->coef);
        printf("exp:\n");
        scanf("%d",&pn->exp);
        if(pn->exp < 0)
        {
            break;
        }
        pre = p->head;
        q = p->head->link;
        while(q && q->exp > pn->exp)
        {
            pre = q;
            q = q->link;
        }
        pn->link = q;
        pre->link = pn;
    }
}
