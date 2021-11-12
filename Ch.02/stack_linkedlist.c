#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    struct stack *link;
    int data; 
} stack;
stack *top;

void push(int n);
int pop();
int peek();
int isEmpty();
void displayStack();


int main(void) {
    pop();
    push(10);
    displayStack();
    push(20);
    displayStack();
    printf("%d\n",peek());
    push(30);
    displayStack();
    push(40);
    displayStack();
    pop();
    displayStack();
    push(50);
    displayStack();
}


void push(int n) {
    stack *newNode = malloc(sizeof(stack));
    newNode->link = top;
    top = newNode;
    newNode->data = n;
}

int pop() {
    if(!isEmpty()) {
        stack *temp = top;
        int num = temp->data;
        top = top->link;
        free(temp);
        return num;
    }
}

int peek() {
    if(!isEmpty()) return top->data;
}

int isEmpty() {
    if(top == NULL) {
        printf("ERROR MESSAGE : stack is empty!!\n");
        return 1;
    }
    else return 0;

}

void displayStack() {
    stack *temp = top;
    while(temp) {
        printf("%d ",temp->data);
        temp = temp->link;
    }
    printf("\n");
}


