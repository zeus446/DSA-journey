#include<stdio.h>


struct Date{
    int joining_year;
};

struct Emp{
    char emp_name[20];
    int salary;
    struct Date d;
};

int main(){
    struct Emp e;
    printf("eneter name : ");
    scanf("%19s",e.emp_name);
    printf("enter salary : ");
    scanf("%d",&e.salary);
    printf("enter joining year : ");
    scanf("%d",&e.d.joining_year);

    printf("%19s",e.emp_name);
    printf("%d",e.salary);
    printf("%d",e.d.joining_year);


}

