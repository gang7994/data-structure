#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *next;
    int data;
} NODE;

void insertfirst(NODE *head, int data) {
    NODE *newnode = malloc(sizeof(NODE));
    newnode->next = head->next;
    head->next = newnode;
    newnode->data = data;
}

void deletefirst(NODE *head) {
    NODE *delete = head->next;
    head->next = delete->next;
    free(delete);
}
    
void display(NODE *head) {
    NODE *p = head;
    while(p!=NULL) {
        if(p == head) printf("head->");
        else printf("%d->",p->data);
        p = p->next;
    }
    printf("NULL\n");
}

int search(NODE *head, int n) {
    NODE *p = head;
    int cnt=0;
    while(p !=NULL){
        if(p->data == n) return cnt;
        p = p->next;
        cnt++;
    }
    return -1;
}


int main(void) {
    NODE *head = malloc(sizeof(NODE));
    head->next = NULL;
    insertfirst(head,10);
    insertfirst(head,20);
    insertfirst(head,30);
    insertfirst(head,40);
    display(head);
    printf("location : %d\n",search(head,30));
    
}