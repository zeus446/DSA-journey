#include<stdio.h>
#include<stdlib.h>

struct tree{
    int data;
    struct tree * left;
    struct tree * right;
};

struct tree * createnode(int val){
    struct tree * new_node = (struct tree *)malloc(sizeof(struct tree));
    if(new_node ==  NULL){
        printf("Allocation failed");
        exit(1);
    }
    new_node->data = val;
    new_node->left = NULL;
    new_node->right = NULL;
}

struct tree * insert(struct tree * root, int val){
    if(root == NULL){
        return createnode(val);
    }

    if(root->data>val){
        root->left = insert(root->left,val);
    }

    else if(root->data<val){
        root->right = insert(root->right,val);
    }

    return root;
}

void inorder(struct tree * root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

struct tree * search(struct tree * root,int val){
    if(root == NULL){
        return 0;
    }

    if(val == root->data){
        return root;
    }

    else if(root->data>val){
        return search(root->left,val);
    }

    else{
        return search(root->right,val);
    }
}

int main(void) {
    struct tree *root = NULL;
    struct tree *result = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder traversal: ");
    inorder(root);

    result = search(root, 40);
    if (result != NULL)
        printf("\n40 found in the tree");
    else
        printf("\n40 not found in the tree");

    result = search(root, 90);
    if (result != NULL)
        printf("\n90 found in the tree");
    else
        printf("\n90 not found in the tree");

    return 0;
}