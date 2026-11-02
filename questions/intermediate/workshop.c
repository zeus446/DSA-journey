/*A workshop registration system accidentally inserts the same registration number multiple times. The administrator must remove duplicates without changing the order of the first occurrence of each registration number.

Implement any TWO operations:
1. Remove duplicate registration numbers while retaining the first occurrence.
2. Find the k-th node from the end in a single traversal, without calculating the list length first.
3. Delete the node immediately before a specified registration number.
Tricky test case

Input list: 101 → 104 → 101 → 105 → 104 → 108

For operation 1, expected output:

101 → 104 → 105 → 108

For operation 2, use k = 2. Expected result: 104.

Constraint: Do not convert the list into an array. Handle an empty list, a single node, and invalid values of k.*/

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node * insert(struct Node *head,int val){
    struct Node * new_node = (struct Node *)malloc(sizeof(struct Node));
    if(new_node == NULL){
        printf("Allocation failed");
        exit(1);
    }
    new_node->data = val;
    new_node->next = head;
    head = new_node;
    return head;
}


struct Node * removedupl(struct Node *head){
    if(head == NULL){
        printf("List is empty no duplicates to delete !!!");
        exit(1);
    }
    struct Node * current = head;
    while(current!=NULL){
        struct Node* prev = current;
        struct Node* runner = current->next;
        while(runner!=NULL){
            if(runner->data == current->data){
                prev->next = runner->next;
                free(runner);
                runner = prev->next;
            }
            else{
                prev = runner;
                runner = runner->next;
            }
        }
        current = current->next;
    }
    return head;
}

void display(struct Node * head){
    if(head == NULL){
        printf("List is empty");
        return;
    }
    struct Node* temp = head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("Null\n");
}


int main(){
    struct Node * head = NULL;

    head = insert(head,10);
    head = insert(head,20);
    head = insert(head,30);
    head = insert(head,10);
    display(head);
    removedupl(head);
    display(head);

}