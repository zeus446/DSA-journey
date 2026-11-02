#include<stdio.h>
#include<stdlib.h>

void insert(int arr[],int *n,int pos,int val){
    for(int i = *n ; i>pos;i--){
        arr[i] = arr[i-1];
    }
    arr[pos] = val;
    (*n)++;

}

int removedupl(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i] == arr[j]){
                int k = i;
                while(k < n-1){
                    arr[k] = arr[k+1];
                    k++;
                }

                n--;
                i--;
                break;
            }
        
        }
    }
    return n;
}

int secondlargest(int arr[], int n){
    int largest = arr[0];
    int second = 0;
    for(int i = 0;i<n;i++){
        if(arr[i]>largest){
            second = largest;
            largest = arr[i];
        }

        else if(arr[i]<largest && arr[i]>second){
            second = arr[i];
        }

    }

    return second;
}

void display(int arr[],int * n){
    for(int i=0;i<*n;i++){
        printf("%d ",arr[i]);
    }
}



int main(){
    int arr[10] = {10,12,13,13};
    int n = 4;
    insert(arr,&n,0,5);
    n = removedupl(arr,n);
    display(arr,&n);
    printf("\n%d",secondlargest(arr,n));
}