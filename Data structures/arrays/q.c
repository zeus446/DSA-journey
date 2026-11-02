#include<stdio.h>
#include<stdlib.h>


int  sum1(int arr[],int n){
    int sum = 0;
    for(int i  =0;i<n;i++){
        sum+=arr[i];
    }
    return sum;
}

int sum2(int arr[],int n){
    int sum =0;
    for(int i=0;i<n;i++){
        if(arr[i]%2==0){
            sum+=arr[i];
        }
    }
    return sum;
}

void average(int arr[],int n){
    int avg;
    avg = sum1(arr,n)/n;
    printf("avergae = %d ",avg);
}


void armstrong(int arr[],int n){
    int temp;
    int rev;
    int count =0;
    for(int i=0;i<n;i++){
        int arm = 0;
        while(arr[i]>0){
            temp = arr[i];
            rev = arr[i]%10;
            arm += rev*rev*rev;
            arr[i] = arr[i]/10;

        }
        if(arm == temp){
            printf("%d",temp);
            count++;
        }
    }
    if(count == 0){
        printf("No armstronmg numbers in the given array");
    }
}


void search(int arr[],int n,int val){
    for(int i =0;i<n;i++){
        if(arr[i]==val){
            printf("value found at index %d",i);
            return;
        }
    }
    printf("no such value in the  array");
}


int main(){
    int choice,n,capacity = 100,val,head;
    int arr[100];
    printf("enter thhe number elements in the array: ");
    scanf("%d",&n);
    printf("enter the elements in the array : ");
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    do{
        printf("\n---Menu--\n");
        printf("1.sum\n2.average\n3.armstrong number\n4.search\n5.exit\n");
        printf("enter your choice :");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("sum = %d ",sum1(arr,n) );
            break;

            case 2:
            average(arr,n);
            break;

            case 4:
            printf("enter the value to be searched : ");
            scanf("%d",&val);
            search(arr,n,val);
            break;

            case 3:
            printf("armstrong numbers are : ");
            armstrong(arr,n);
            break;

            case 5:
            printf("even sum = %d ",sum2(arr,n));
            break;

            case 6:
            printf("Exiting...");
            break;

            default:
            printf("inalid choice please enter a valid choice");
        }
    }while(choice!=6);
}

