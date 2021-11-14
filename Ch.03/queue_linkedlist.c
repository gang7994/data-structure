#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    struct NODE *link;
    int data;
} NODE;

NODE *front,*rear;

void init_queue();
void enqueue(int n);
int dequeue();
int is_empty();
int peek();
void display_queue();


int main(void) {
    init_queue();
    // 데이터 넣기 //
    enqueue(1);
    display_queue();
    enqueue(2);
    display_queue();
    enqueue(3);
    display_queue();
    enqueue(4);
    display_queue();
    enqueue(5);
    display_queue();
    printf("%d\n", dequeue());   
    display_queue();

}

void init_queue() {
    front = NULL;
    rear = NULL;
}

int is_empty() {
    if(front == NULL) return 1;
    else return 0;
}

void enqueue(int n) {
    NODE *new = (NODE*)malloc(sizeof(NODE));
    new->data = n;
    new->link = NULL;
    if(is_empty()) {
        front = new;
        rear = new;
        
    }
    else {
        rear->link = new;
        rear = new;
        
    }
}

int dequeue() {
    NODE *remove;
    int temp;
    if(is_empty()) printf("Error Queue is Empty!!\n");
    else {
        remove = front;
        temp = remove->data;
        front = front->link;
        if(front == NULL) rear = NULL;
        free(remove);
        return temp;
    }
}

int peek() {
    if(is_empty()) printf("Error Queue is Empty!!\n");
    else {
        int temp;
        temp = front->data;
        return temp;
    }
}

void display_queue() {
    NODE *tempnode = front;
    printf("[ ");
    while(tempnode != NULL) {
        printf("%d ", tempnode->data);
        tempnode = tempnode->link;
    }
    printf("]\n");
}
