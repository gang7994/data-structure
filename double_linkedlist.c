#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *llink;
    struct Node *rlink;
    int data;
} NODE;

NODE *makenode(int n);
void append_node(NODE **head, int n);
void insert_node(NODE **head, int index, int data);
void remove_node(NODE **phead, int index);
void display(NODE **head);
//NODE *search(NODE *head,int n);
int size(NODE *head);


int main(void) {
    NODE *dll = NULL;
    
    display(&dll);
    
    append_node(&dll,1);
    
    append_node(&dll,2);
    
    append_node(&dll,3);
    
    
    display(&dll);
    
    
    remove_node(&dll,2);
    display(&dll);
}


NODE *makenode(int n) {
    NODE *newnode = malloc(sizeof(NODE));
    newnode->data = n;
    newnode->llink = NULL;
    newnode->rlink = NULL;
}

void append_node(NODE **head, int data) {
    NODE *newnode = makenode(data);
    if(*head ==NULL) {
        *head = newnode;
    }
    else {
        NODE *tail = *head;
        while(tail->rlink != NULL) {
            tail = tail->rlink;
        }
        newnode->llink = tail;
        tail->rlink = newnode;
    }
}

void insert_node(NODE **head, int index, int data) {
    NODE *newnode = makenode(data);
    if(index < 0 || index > size(*head)) printf("Out of bound\n");
    else {
        NODE *temp = *head;
        if(index == 0) {
            newnode->llink = NULL;
            newnode->rlink = temp;
            temp->llink = newnode;
            *head = newnode;
        }
        else {
            for(int i=0; i<index-1;i++) temp = temp->rlink;
            newnode->llink = temp;
            newnode->rlink = temp->rlink;
            temp->rlink = newnode;
            newnode->rlink->llink = newnode;
        }
    }
}

void remove_node(NODE **head, int index) {
    if(index < 0 || index > size(*head)) printf("Out of bound\n");
    else {
        NODE *temp = *head;
        if(index ==0) *head = temp->rlink;
        else {
            int i=0;
            for(i;i<index;i++) temp = temp->rlink;
            if(i == index) {
                temp->llink->rlink = NULL;
            }
            else {
                temp->llink->rlink = temp->rlink;
                temp->rlink->llink = temp->llink;
            }
        }
        free(temp);
    }
}

void display(NODE **head) {
    NODE *tail = *head;
    printf("[ ");
    while(tail != NULL) {
        printf("<-%d-> ",tail->data);
        tail = tail->rlink;
    }
    printf("]\n");
}

int size(NODE *head) {
    int size = 0;
    NODE *tail = head;
    while(tail != NULL) {
        size++;
        tail = tail->rlink;
    }
   
    return size;
}

