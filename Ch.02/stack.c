#include <stdio.h>
#define MAX_STACK_SIZE 100

int stack[MAX_STACK_SIZE] = {};
int top = -1;

int is_empty() {
    if(top == -1) return 1;
    else return 0;
}

int is_full() {
    if(top == MAX_STACK_SIZE-1) return 1;
    else return 0;
}

void push(int x) {
    top++;
    stack[top] = x;
}

int pop() {
    int element = stack[top];
    stack[top] = 0; //보기편하기 위해서 작성
    top--;
    return element;
}

int peek() {
    return stack[top];
}

int main(void) {
    push(10);
    push(90);
    push(80);
    push(70);
    push(60);
    push(50);
    for(int i=0; i<MAX_STACK_SIZE;i++) printf("%d|",stack[i]);
    printf("\n");
    printf("peek : %d\n", peek());
    printf("pop : %d\n", pop());
    printf("pop : %d\n", pop());
    printf("pop : %d\n", pop());
    for(int i=0; i<MAX_STACK_SIZE;i++) printf("%d|",stack[i]);
}