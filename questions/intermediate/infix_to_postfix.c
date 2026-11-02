
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack {
    char data;
    int size;
    int top;
    char *arr;
};

void push(struct stack *sp, int val) {
    if (sp->top == sp->size - 1) {
        printf("Overflow");
        exit(1);
    }
    sp->top++;
    sp->arr[sp->top] = val;
}

char pop(struct stack *sp) {
    if (sp->top == -1) {
        printf("Underflow");
        exit(1);
    }
    int temp = sp->top;
    sp->top--;
    return sp->arr[temp];
}

int isOperator(char ch) {
    if (ch == '+' || ch == '-' || ch == '/' || ch == '*') {
        return 1;
    }
    else {
        return 0;
    }
}

int precedence(char ch) {
    if (ch == '*' || ch == '/') {
        return 3;
    }
    else if (ch == '+' || ch == '-') {
        return 2;
    }
    else {
        return 1;
    }
}

int isEmpty(struct stack *sp) {
    if (sp->top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

char *infix_to_postfix(char *infix) {
    struct stack *sp = malloc(sizeof(struct stack));
    sp->top = -1;
    sp->size = 50;
    sp->arr = malloc(sp->size * sizeof(char));

    char *postfix = malloc((strlen(infix) + 1) * sizeof(char));

    int i = 0;
    int j = 0;

    while (infix[i] != '\0') {
        if (!isOperator(infix[i])) {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else {
            if (isEmpty(sp) ||
                precedence(infix[i]) > precedence(sp->arr[sp->top])) {
                push(sp, infix[i]);
                i++;
            }
            else {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }

    while (!isEmpty(sp)) {
        postfix[j] = pop(sp);
        j++;
    }

    postfix[j] = '\0';

    free(sp->arr);
    free(sp);

    return postfix;
}

int main() {
    char *exp = "a+b/c";
    char *result = infix_to_postfix(exp);

    printf("Postfix is: %s\n", result);

    free(result);
    return 0;
}
