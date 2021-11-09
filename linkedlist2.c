#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *next;
    int data;
} NODE;

void insert_node(NODE **phead, NODE *prev, NODE *new_node) {
    if(*phead ==NULL) {
        new_node->next = *phead;
        *phead = new_node;
        
    }
    else if(prev ==NULL) {
        new_node->next = *phead;
        *phead = new_node;
    }
    else {
        new_node->next = prev->next;
        prev->next = new_node;  
    }

}

void display(NODE *phead) {
    NODE *p = phead;
    while(p!=NULL) {
        printf("%d->",p->data);
        p = p->next;
    }
    printf("NULL\n");

}

int main(void) {
    NODE *head = malloc(sizeof(NODE));
    head->next = NULL;
    head->data = 0;
    display(head);
    NODE *node1 = malloc(sizeof(NODE));
    node1->data = 100;
    insert_node(&head,head,node1);
    display(head);
    NODE *node2 = malloc(sizeof(NODE));
    node2->data = 200;
    insert_node(&head,node1,node2);
    display(head);
    
    
}