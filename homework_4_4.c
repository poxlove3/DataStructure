#include <stdio.h>
#include <stdlib.h>
#define OK 1    //函数结果状态
#define ERROR 0
#define MAX 100
typedef int Status;//函数结果状态类型

typedef struct{
    int i,j;    //三元组的行号、列号；
    int e;      //三元组的值;
}Triple;

typedef struct{
    Triple data[MAX];//非零元三元组表示
    int rpos[MAX];  //稀疏矩阵三元组各行起始坐标
    int mu,nu,tu;   //矩阵的行数、列数和非零元个数
}Matrix;

void Input(Matrix *M,Matrix *N);
Status CreateMatrix(Matrix *M);
Status PrintMatrix(Matrix M);
Status PlusMatrix(Matrix M, Matrix N, Matrix *D);
Status MultMatrix(Matrix M, Matrix N, Matrix *Q);

int main(){
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

void Input(Matrix *M,Matrix *N){
    printf("Please input the rows and cols and number of the nonzero element:");
    if(!CreateMatrix(M))
        printf("Error Create M!\n");
    PrintMatrix(*M);

    printf("Please input the rows and cols and number of the nonzero element:");
    if(!CreateMatrix(N))
        printf("Error Create N!\n");
    PrintMatrix(*N);
}

Status CreateMatrix(Matrix *M){//创建稀疏矩阵，采取三元组存储
    int num[MAX]={0}; //对应行非零元个数
    int flag[MAX][MAX]={0};//标记对应位置是否已有非零元
    int i,j,e;  //非零元三元组的临时存储变量
    scanf(" %d%d%d",&M->mu,&M->nu,&M->tu);
    while(M->mu < 0 || M->nu < 0 || M->tu > M->mu * M->nu){//判断矩阵行数、列数和非零元个数是否合法
        printf("The rows,cols and number of nonzero element is out of normal range!!\n");
        printf("Please input again:");
        scanf(" %d%d%d",&M->mu,&M->nu,&M->tu);
    }

    if(!M->tu) return OK;//全部为零元素，直接返回

    for(int k = 1;k <= M->tu;k++){//输入非零元
        printf("Please input the row,col,and data of element:");
        scanf(" %d%d%d",&i,&j,&e);
        while(i <= 0 || i > M->mu || j <= 0 || j > M->nu){//判断输入非零元行号、列号合法
            printf("The row,col and data of element is out of normal range!!\n");
            printf("Please input again:");
            scanf(" %d%d%d",&i,&j,&e);
        }
        while(!e){//判断是否非零元
            printf("Zero element occurs!\n");
            scanf(" %d",&e);
        }
        if(!flag[i][j]){//判断该位置是否已有非零元
            flag[i][j] = 1;
        }
        else{
            printf("Here exists!\n");
            continue;
        }
        int l,m;
        //寻找该三元组的位置
        if(k==1){
            M->data[k].i = i;
            M->data[k].j = j;
            M->data[k].e = e;
            continue;
        }
        for(l = 1;l < k && (i > M->data[l].i || (i == M->data[l].i && j > M->data[l].j));l++);
        for(m = k-1;m >= l;m--){//依次向后移动
            M->data[m+1] = M->data[m];
            //printf("%d\n",M->data[m+1].i);
        }
        //保存数据
        M->data[l].i = i;
        M->data[l].j = j;
        M->data[l].e = e;
        //printf("%d\t%d\t%d",M->data[k].i,M->data[k].j,M->data[k].e);
        //printf("%d\n",k);
    }
    //求各行非零元起始位置
    if(M->tu){//判断非零元个数是否为0
        for(int m = 1;m <= M->tu;m++)
            ++num[M->data[m].i];//求M中每行非零元素个数
        M->rpos[1] = 1;//起始位置赋值
        for(int m = 2;m <= M->tu;m++)
            M->rpos[m] = M->rpos[m-1] + num[m-1];
    }
    return OK;
}

Status PlusMatrix(Matrix M, Matrix N, Matrix *D){//求稀疏矩阵的和Q=M+N
    if(M.mu != N.mu || M.nu != N.nu)//检查稀疏矩阵M和N的行数和列数是否对应相等
        return ERROR;
    int i = 1,j = 1,k = 1;//各矩阵三元组移动临时变量
    D->mu = M.mu;
    D->nu = M.nu;
    D->tu = 0;
    if(M.tu*N.tu == 0)//零矩阵，直接返回
        return OK;
    while(i <= M.tu && j <= N.tu){//M和N均不为空
        if(M.data[i].i < N.data[j].i || (M.data[i].i == N.data[j].i && M.data[i].j < N.data[j].j)){//以行为主序，M中的节点在N前
            D->tu++;
            D->data[k++] = M.data[i++];//结构体赋值
        }
        else if(M.data[i].i == N.data[j].i && M.data[i].j == N.data[j].j){//M和N节点对应
            if(M.data[i].e+N.data[j].e){//M和N相加之和不为0
                D->data[k].i=M.data[i].i;
                D->data[k].j=M.data[i].j;
                D->data[k++].e=M.data[i].e+N.data[j].e;
                D->tu++;
                //printf("%d\n",D->data[k-1].e);
            }
            i++;
            j++;
        }
        else if(M.data[i].i > N.data[j].i ||(M.data[i].i == N.data[j].i && M.data[i].j > N.data[j].j)){//N节点在M前
            D->tu++;
            D->data[k++] = N.data[j++];
        }
    }
    while(i <= M.tu){//将矩阵N的剩余元素插入矩阵
        D->tu++;
        D->data[k++] = M.data[i++];
    }
    while(j <= N.tu){//将矩阵M的剩余元素插入矩阵
        D->tu++;
        D->data[k++] = N.data[j++];
    }
    //printf("%d\n",k);
    printf("Matrix A plus Matrix B is D:\n");
    PrintMatrix(*D);
    return OK;
}

Status MultMatrix(Matrix M, Matrix N, Matrix *Q){//进行矩阵M和N相乘
    int arow,brow,ccol,ctemp[MAX];
    int p,q,tp,i,t;//p,q,i为中间变量；tp,t分别为M的各行位置上限
    if(M.nu != N.mu)//判断M的列数和N的行数是否相等
        return ERROR;
    Q->mu = M.mu;
    Q->nu = N.nu;
    Q->tu = 0;
    if(M.tu*N.tu == 0)//判断矩阵是否为非零矩阵
        return OK;
    for(arow = 1;arow <= M.mu;arow++){//处理M的每一行
        for(i = 1;i <= N.nu;i++)//元素累加清零
            ctemp[i] = 0;
        Q->rpos[arow] = Q->tu+1;//起始坐标赋值
        if(arow < M.mu)//找到该行移动次数上限
            tp = M.rpos[arow+1];
        else
            tp = M.tu+1;
        for(p = M.rpos[arow];p < tp;p++){//求Q中第arow行的非零元
            brow = M.data[p].j;
            if(brow < N.mu)//找到N中该行移动次数上限
                t = N.rpos[brow+1];
            else
                t = N.tu+1;
            for(q = N.rpos[brow];q < t;q++){
                ccol = N.data[q].j;//成绩元素在N中列号
                ctemp[ccol] += M.data[p].e * N.data[q].e;
            }
        }
        for(ccol = 1;ccol <= Q->nu;ccol++){//存储非零元
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

Status PrintMatrix(Matrix M){//打印矩阵
    int i,j,k = 1;//临时中间变量
    printf("The matrix is:\n");
    for(i = 1;i <= M.mu;i++){//遍历矩阵
        for(j = 1;j <= M.nu;j++){
            if(i == M.data[k].i && j == M.data[k].j){//存在三元组匹配，输出
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
