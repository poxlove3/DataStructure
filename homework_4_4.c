#include <stdio.h>
#include <stdlib.h>
#define OK 1    //�������״̬
#define ERROR 0
#define MAX 100
typedef int Status;//�������״̬����

typedef struct Triple
{
    int i,j;    //��Ԫ����кš��кţ�
    int e;      //��Ԫ���ֵ;
}Triple;

typedef struct Matrix
{
    Triple data[MAX];//����Ԫ��Ԫ���ʾ
    int rpos[MAX];  //ϡ�������Ԫ�������ʼ����
    int mu,nu,tu;   //����������������ͷ���Ԫ����
}Matrix;

void Input(Matrix *M,Matrix *N);
Status CreateMatrix(Matrix *M);
Status PrintMatrix(Matrix M);
Status PlusMatrix(Matrix M, Matrix N, Matrix *D);

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    Matrix M,N,D,Q;
    Input(&M,&N);
    if(!PlusMatrix(M,N,&D))
        printf("They cannot be added.\n");
    if(!MultMatrix(M,N,&Q))
        printf("They cannot be multiplied.\n");
    return 0;
}

void Input(Matrix *M,Matrix *N)
{
    printf("Please input the rows and cols and number of the nonzero element:");
    if(!CreateMatrix(M))
        printf("Error Create M!\n");
    PrintMatrix(*M);

    printf("Please input the rows and cols and number of the nonzero element:");
    if(!CreateMatrix(N))
        printf("Error Create N!\n");
    PrintMatrix(*N);
}

Status CreateMatrix(Matrix *M)
{//����ϡ����󣬲�ȡ��Ԫ��洢
    int num[MAX]={0}; //��Ӧ�з���Ԫ����
    int flag[MAX][MAX]={0};//��Ƕ�Ӧλ���Ƿ����з���Ԫ
    int i,j,e;  //����Ԫ��Ԫ�����ʱ�洢����
    scanf(" %d%d%d",&M->mu,&M->nu,&M->tu);
    while(M->mu < 0 || M->nu < 0 || M->tu > M->mu * M->nu)
    {//�жϾ��������������ͷ���Ԫ�����Ƿ�Ϸ�
        printf("The rows,cols and number of nonzero element is out of normal range!!\n");
        printf("Please input again:");
        scanf(" %d%d%d",&M->mu,&M->nu,&M->tu);
    }

    if(!M->tu)
        return OK;//ȫ��Ϊ��Ԫ�أ�ֱ�ӷ���

    for(int k = 1;k <= M->tu;k++)
    {//�������Ԫ
        printf("Please input the row,col,and data of element:");
        scanf(" %d%d%d",&i,&j,&e);
        while(i <= 0 || i > M->mu || j <= 0 || j > M->nu)
        {//�ж��������Ԫ�кš��кźϷ�
            printf("The row,col and data of element is out of normal range!!\n");
            printf("Please input again:");
            scanf(" %d%d%d",&i,&j,&e);
        }
        while(!e)
        {//�ж��Ƿ����Ԫ
            printf("Zero element occurs!\n");
            scanf(" %d",&e);
        }
        if(!flag[i][j])
        {//�жϸ�λ���Ƿ����з���Ԫ
            flag[i][j] = 1;
        }
        else
        {
            printf("Here exists!\n");
            continue;
        }
        int l,m;
        //Ѱ�Ҹ���Ԫ���λ��
        if(k==1)
        {
            M->data[k].i = i;
            M->data[k].j = j;
            M->data[k].e = e;
            continue;
        }
        for(l = 1;l < k && (i > M->data[l].i || (i == M->data[l].i && j > M->data[l].j));l++);
        for(m = k-1;m >= l;m--){//��������ƶ�
            M->data[m+1] = M->data[m];
            //printf("%d\n",M->data[m+1].i);
        }
        //��������
        M->data[l].i = i;
        M->data[l].j = j;
        M->data[l].e = e;
        //printf("%d\t%d\t%d",M->data[k].i,M->data[k].j,M->data[k].e);
        //printf("%d\n",k);
    }
    //����з���Ԫ��ʼλ��
    if(M->tu){//�жϷ���Ԫ�����Ƿ�Ϊ0
        for(int m = 1;m <= M->tu;m++)
            ++num[M->data[m].i];//��M��ÿ�з���Ԫ�ظ���
        M->rpos[1] = 1;//��ʼλ�ø�ֵ
        for(int m = 2;m <= M->tu;m++)
            M->rpos[m] = M->rpos[m-1] + num[m-1];
    }
    return OK;
}

Status PlusMatrix(Matrix M, Matrix N, Matrix *D){//��ϡ�����ĺ�Q=M+N
    if(M.mu != N.mu || M.nu != N.nu)//���ϡ�����M��N�������������Ƿ��Ӧ���
        return ERROR;
    int i = 1,j = 1,k = 1;//��������Ԫ���ƶ���ʱ����
    D->mu = M.mu;
    D->nu = M.nu;
    D->tu = 0;
    if(M.tu*N.tu == 0)//�����ֱ�ӷ���
        return OK;
    while(i <= M.tu && j <= N.tu){//M��N����Ϊ��
        if(M.data[i].i < N.data[j].i || (M.data[i].i == N.data[j].i && M.data[i].j < N.data[j].j)){//����Ϊ����M�еĽڵ���Nǰ
            D->tu++;
            D->data[k++] = M.data[i++];//�ṹ�帳ֵ
        }
        else if(M.data[i].i == N.data[j].i && M.data[i].j == N.data[j].j){//M��N�ڵ��Ӧ
            if(M.data[i].e+N.data[j].e){//M��N���֮�Ͳ�Ϊ0
                D->data[k].i=M.data[i].i;
                D->data[k].j=M.data[i].j;
                D->data[k++].e=M.data[i].e+N.data[j].e;
                D->tu++;
                //printf("%d\n",D->data[k-1].e);
            }
            i++;
            j++;
        }
        else if(M.data[i].i > N.data[j].i ||(M.data[i].i == N.data[j].i && M.data[i].j > N.data[j].j)){//N�ڵ���Mǰ
            D->tu++;
            D->data[k++] = N.data[j++];
        }
    }
    while(i <= M.tu){//������N��ʣ��Ԫ�ز������
        D->tu++;
        D->data[k++] = M.data[i++];
    }
    while(j <= N.tu){//������M��ʣ��Ԫ�ز������
        D->tu++;
        D->data[k++] = N.data[j++];
    }
    //printf("%d\n",k);
    printf("Matrix A plus Matrix B is D:\n");
    PrintMatrix(*D);
    return OK;
}

Status MultMatrix(Matrix M, Matrix N, Matrix *Q){//���о���M��N���
    int arow,brow,ccol,ctemp[MAX];
    int p,q,tp,i,t;//p,q,iΪ�м������tp,t�ֱ�ΪM�ĸ���λ������
    if(M.nu != N.mu)//�ж�M��������N�������Ƿ����
        return ERROR;
    Q->mu = M.mu;
    Q->nu = N.nu;
    Q->tu = 0;
    if(M.tu*N.tu == 0)//�жϾ����Ƿ�Ϊ�������
        return OK;
    for(arow = 1;arow <= M.mu;arow++){//����M��ÿһ��
        for(i = 1;i <= N.nu;i++)//Ԫ���ۼ�����
            ctemp[i] = 0;
        Q->rpos[arow] = Q->tu+1;//��ʼ���긳ֵ
        if(arow < M.mu)//�ҵ������ƶ���������
            tp = M.rpos[arow+1];
        else
            tp = M.tu+1;
        for(p = M.rpos[arow];p < tp;p++){//��Q�е�arow�еķ���Ԫ
            brow = M.data[p].j;
            if(brow < N.mu)//�ҵ�N�и����ƶ���������
                t = N.rpos[brow+1];
            else
                t = N.tu+1;
            for(q = N.rpos[brow];q < t;q++){
                ccol = N.data[q].j;//�ɼ�Ԫ����N���к�
                ctemp[ccol] += M.data[p].e * N.data[q].e;
            }
        }
        for(ccol = 1;ccol <= Q->nu;ccol++){//�洢����Ԫ
            if(ctemp[ccol]){
                Q->tu++;
                Q->data[Q->tu].i = arow;
                Q->data[Q->tu].j = ccol;
                Q->data[Q->tu].e = ctemp[ccol];
            }
        }
    }
    printf("Matrix A multiply Matrix B is Q:\n");
    PrintMatrix(*Q);
    return OK;
}

Status PrintMatrix(Matrix M){//��ӡ����
    int i,j,k = 1;//��ʱ�м����
    printf("The matrix is:\n");
    for(i = 1;i <= M.mu;i++){//��������
        for(j = 1;j <= M.nu;j++){
            if(i == M.data[k].i && j == M.data[k].j){//������Ԫ��ƥ�䣬���
                printf("%d\t",M.data[k].e);
                k++;
            }
            else
                printf("0\t");
        }
        printf("\n");
    }
    printf("The matrix has %d rows, %d cols ,and %d nonzero elements.\n",M.mu ,M.nu, M.tu);
    return OK;
}
