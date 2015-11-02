#include<stdio.h>
#include<bits/stdc++.h>
void init(int *P,int n){
    int i;
    for(i=0;i<n;i++){
        P[i] = i;
    }
}
void LUP_SOLVE(double **A,int *P,double *B,double *X,int n){
    int i,j,k;
    double sum = 0;
    for(i=0;i<n;i++){
        X[i] = B[P[i]];
        for(j=0;j<i;j++)
        X[i] -= (A[i][j]*X[j]);
    }
    for(i = n - 1;i>=0;i--){
            sum = 0;
         for(j = i + 1;j<n;j++){
            sum += (A[i][j]*X[j]);
         }
        X[i] = (X[i] - sum)/A[i][i];
    }

}
void LUP_DECOMPOSITION(double **A,double * X,double *B,int n){
    int i,j,k,k1,P[n];
    init(P,n);
    for(k = 0;k<n;k++){
        double q = 0;
        for(i=k;i<n;i++){
            if(abs(A[i][k]) > q){
                q = abs(A[i][k]);
                k1 = i;
            }
        }
        if(q == (double)0){
            printf("Error : singular matrix \n");
            return ;
        }
        std::swap(P[k],P[k1]);
        for(i=0;i<n;i++){
            std::swap(A[k][i],A[k1][i]);
        }
        for(i = k + 1;i<n;i++){
            A[i][k] /= A[k][k];
            for(j = k + 1;j<n;j++){
                A[i][j] -= (A[i][k]*A[k][j]);
            }
        }

    }
    LUP_SOLVE(A,P,B,X,n);
    return ;

}

int main(){
    int n,i,j;
    printf("Enter n : number of linear equations\n");
    scanf("%d",&n);
    double **A,*B,*X;
    B = (double*)malloc(n*sizeof(double));
    X = (double*)malloc(n*sizeof(double));
     A = (double**)malloc(n*sizeof(double *));
    for(i=0;i<n;i++){
        A[i] = (double*)malloc(n*sizeof(double));

    }

    printf("Linear equations can be represented as matrix-vector equation : AX = B \nEnter A :(nxn)\n");
    for(i=0;i<n;i++){
            for(j=0;j<n;j++)
                scanf("%u",&A[i][j]);
                //std::cin>>A[i][j];
    }
    printf("Enter matrix B : (n)");
    for(i=0;i<n;i++){
        scanf("%u",&B[i]);
        //std::cin>>B[i];
    }
    for(i=0;i<n;i++){
            for(j=0;j<n;j++)
                //scanf("%f",&A[i][j]);
                std::cout<<A[i][j]<<" ";
                std::cout<<std::endl;
    }
    printf("Enter matrix B : (n)");
    for(i=0;i<n;i++){
        //scanf("%f",&B[i]);
        std::cout<<B[i];
        std::cout<<std::endl;
    }
    LUP_DECOMPOSITION(A,X,B,n);
    for(i=0;i<n;i++){
        printf("%f\n",X[i]);
    }
    return 0;
}
