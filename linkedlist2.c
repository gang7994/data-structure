#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *next;
    int data;
} NODE;

void insert_node(NODE **phead, NODE *prev, NODE *new_node, int n) {
    if(*phead ==NULL) {
        new_node->next = *phead;
        new_node->data = n;
        *phead = new_node;
        
    }
    else if(prev ==NULL) {
        new_node->next = *phead;
        new_node->data = n;
        *phead = new_node;
    }
    else {
        new_node->next = prev->next;
        new_node->data = n;
        prev->next = new_node;  
    }

}

void remove_node(NODE **phead, NODE *prev, NODE *removenode) {
    if(prev == NULL ) {
        *phead = removenode->next;
        free(removenode);
    }
    else {
        prev->next = removenode->next;
        free(removenode);
    }
}

void display(NODE *phead) {
    NODE *p = phead;
    printf("[ ");
    while(p!=NULL) {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("]\n");

}

int main(void) {
    NODE *head = malloc(sizeof(NODE));
    head = NULL;
    
    display(head);
    
    NODE *node1 = malloc(sizeof(NODE));
    insert_node(&head,head,node1,100);
    display(head);

    NODE *node2 = malloc(sizeof(NODE));
    insert_node(&head,node1,node2,200);
    display(head);

    NODE *node3 = malloc(sizeof(NODE));
    insert_node(&head,node2,node3,300);
    NODE *node4 = malloc(sizeof(NODE));
    insert_node(&head,node3,node4,400);
    NODE *node5 = malloc(sizeof(NODE));
    insert_node(&head,node4,node5,500);
    display(head);

    remove_node(&head, node2, node3);
    display(head);


    
    
    
}