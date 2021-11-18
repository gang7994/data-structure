#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *llink;
    struct Node *rlink;
    int data;
} NODE;

NODE *makenode(int n);
void add_front(NODE **dq, int n);
void add_rear(NODE **dq, int n);
int delete_front(NODE **dq);
int delete_rear(NODE **dq);
int get_front(NODE **dq);
int get_rear(NODE **dq);
int is_empty(NODE **dq);
void display(NODE **head);


int main(void) {
    NODE *dq = NULL;
    display(&dq);

    add_front(&dq, 10);
    add_front(&dq, 20);
    add_front(&dq, 30);
    display(&dq);
    add_rear(&dq, 1);
    display(&dq);
    delete_front(&dq);
    display(&dq);
    delete_rear(&dq);
    display(&dq);
    
    
}


NODE *makenode(int n) {
    NODE *newnode = malloc(sizeof(NODE));
    newnode->data = n;
    newnode->llink = NULL;
    newnode->rlink = NULL;
}

void add_front(NODE **dq, int data) {
    NODE *newnode = makenode(data);
    if(*dq == NULL) *dq = newnode;
    else {
        newnode->rlink = *dq;
        (*dq)->llink = newnode;
        *dq = newnode;
    }
}

void add_rear(NODE **dq, int data) {
    NODE *newnode = makenode(data);
    if(*dq ==NULL) *dq = newnode;
    else {
        NODE *tail = *dq;
        while(tail->rlink != NULL) tail = tail->rlink;
        newnode->llink = tail;
        tail->rlink = newnode;
    }
}

int delete_front(NODE **dq) {
    if(is_empty(dq)) {
        printf("Out of bound\n");
        return -1;
    }
    else {
        NODE *temp = *dq;
        *dq = temp->rlink;
        int data = temp->data;
        free(temp);
        return data;
    }
}

int delete_rear(NODE **dq) {
    if(is_empty(dq)) {
        printf("Out of bound\n");
        return -1;
    }
    else {
        NODE *temp = *dq;
        while(temp->rlink != NULL) temp = temp->rlink;
        int data = temp->data;
        if(temp->llink ==NULL && temp->rlink ==NULL) *dq = NULL;
        else temp->llink->rlink = NULL;
        free(temp);
        return data;
    }
}

int get_front(NODE **dq) {
    if(is_empty(dq)) {
        printf("Out of bound\n");
        return -1;
    }
    else {
        return (*dq)->data;
    }
}
int get_rear(NODE **dq) {
    if(is_empty(dq)) {
        printf("Out of bound\n");
        return -1;
    }
    else {
        NODE *temp = *dq;
        while(temp->rlink != NULL) temp = temp->rlink;
        return temp->data;
    }
}

int is_empty(NODE **dq) {
    if(*dq == NULL) return 1;
    else return 0;
}

void display(NODE **dq) {
    NODE *tail = *dq;
    printf("[ ");
    while(tail != NULL) {
        printf("<-%d-> ",tail->data);
        tail = tail->rlink;
    }
    printf("]\n");
}