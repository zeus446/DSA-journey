#include<stdio.h>
#include<stdlib.h>

int main(){
    int row_a,col_a,row_b,col_b;
    printf("Enter the number of rows and columns of matrix A: ");
    scanf("%d %d",&row_a,&col_a);
    printf("\n");
    printf("Enter the number of rows and columns of the matrix B: ");
    scanf("%d %d",&row_b,&col_b);

    if(col_a!=row_b){
        printf("Matrix multiplication not possible");
        return -1;
    }

    int **a = (int **)malloc(row_a * sizeof(int *));
    int **b = (int **)malloc(row_b * sizeof(int *));
    int **c = (int **)malloc(row_a * sizeof(int *));

    for(int i =0;i<row_a;i++){
        a[i] = (int *)malloc(col_a * sizeof(int));
    }

    for(int i=0;i<row_b;i++){
        b[i] = (int *)malloc(col_b * sizeof(int));
    }

    for(int i=0;i<row_a;i++){
        c[i] = (int *)malloc(col_b * sizeof(int));
    }

    printf("Enter the elements of matrix A: \n");
    for(int i=0;i<row_a;i++){
        for(int j=0;j<col_a;j++){
            scanf("%d",&a[i][j]);
        }
    }

    printf("Enter the elements of matrix B : \n");
    for(int i=0;i<row_b;i++){
        for(int j=0;j<col_b;j++){
            scanf("%d",&b[i][j]);
        }
    }

    printf("Matrix A:\n");
    for(int i=0;i<row_a;i++){
        for(int j=0;j<col_a;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

    printf("Matrix B:\n");
    for(int i=0;i<row_b;i++){
        for(int j=0;j<col_b;j++){
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }

    printf("a times B :\n");
    for(int i=0;i<row_a;i++){
        for(int j=0;j<col_b;j++){
            c[i][j] = 0;
            for(int k=0;k<col_a;k++){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    for(int i=0;i<row_a;i++){
        for(int j=0;j<col_b;j++){
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }

    for(int i=0;i<row_a;i++){
        free(a[i]);
    }free(a);

    for(int i=0;i<row_b;i++){
        free(b[i]);
    }
    free(b);

    for(int i=0;i<row_a;i++){
        free(c[i]);
    }
    free(c);
}