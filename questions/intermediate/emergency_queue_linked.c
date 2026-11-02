#include<stdio.h>
#include<stdlib.h>

struct Node {
    int id;
    int priority;
    struct Node * next;
};

struct Node * middle(struct Node * head){
    if(head == NULL){
        printf("List is empty");
        return head;
    }
    struct Node * slow = head;
    struct Node * fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("middle emelent id : %d",slow->id);
    printf("\nmiddle element priority : %d",slow->priority);
}

struct Node * insert(struct Node * head,int i,int val){
    struct Node * new_node = (struct Node *)malloc(sizeof(struct Node));
    if(new_node == NULL){
        printf("Allocation failed");
        exit(1);
    }
    new_node->id = i;
    new_node->priority = val;
    new_node->next = head;
    head = new_node;
    return head;
}

void display(struct Node * head){
    if(head == NULL){
        printf("Liat is empty");
        return;
    }
    struct Node * temp = head;
    while(temp!=NULL){
        printf("%d->",temp->id);
        printf("%d->",temp->priority);
        temp = temp->next;
    }
    printf("NULL\n");

}

int main(){
    struct Node * head = NULL;
    head = insert(head,1,10);
    head = insert(head,2,20);
    head = insert(head,3,80);
    head = insert(head,4,45);
    middle(head);
    printf("\n");
    display(head);


}