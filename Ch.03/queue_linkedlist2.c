#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    struct NODE *link;
    int data;
} NODE;

typedef struct Queue {
    NODE *front;
    NODE *rear;
} Queue;

void init_queue(Queue *q);
void enqueue(Queue *q, int n);
int dequeue(Queue *q);
int is_empty(Queue *q);
int peek(Queue *q);
void display_queue(Queue *q);


int main(void) {
    Queue *q = malloc(sizeof(Queue));
    init_queue(q);
    enqueue(q, 10);
    display_queue(q);
    enqueue(q, 20);
    display_queue(q);
    enqueue(q, 30);
    display_queue(q);
    enqueue(q, 40);
    display_queue(q);
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    display_queue(q);
    printf("%d\n", peek(q));
    display_queue(q);
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    display_queue(q);
    printf("%d\n", dequeue(q));
    
}

void init_queue(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

int is_empty(Queue *q) {
    if(q->front == NULL) return 1;
    else return 0;
}

void enqueue(Queue *q, int data) {
    NODE *new = (NODE*)malloc(sizeof(NODE));
    new->data = data;
    new->link = NULL;
    if(is_empty(q)) {
        q->front = new;
        q->rear = new;  
    }
    else {
        q->rear->link = new;
        q->rear = new;   
    }
}

int dequeue(Queue *q) {
    NODE *remove = q->front;;
    int temp;
    if(is_empty(q))  {
        printf("Error Queue is Empty!!\n");
        return -1;
    }
    else {
        temp = remove->data;
        
        q->front = q->front->link;
        if(q->front == NULL) q->rear = NULL;
        free(remove);
        return temp;
    }
}

int peek(Queue *q) {
    if(is_empty(q)) printf("Error Queue is Empty!!\n");
    else {
        int temp;
        temp = q->front->data;
        return temp;
    }
}

void display_queue(Queue *q) {
    NODE *tempnode = q->front;
    printf("[ ");
    while(tempnode != NULL) {
        printf("%d ", tempnode->data);
        tempnode = tempnode->link;
    }
    printf("]\n");
}