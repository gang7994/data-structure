#include <stdio.h>
#include <stdlib.h>

typedef enum {
    UNDIRECTED = 0, DIRECTED = 1
} GraphType;

typedef struct Node {
    int data;
    struct Node *next;
} NODE;

typedef struct HeadNodes {
    NODE *head;
} HeadNodes;

typedef struct Graph {
    GraphType mode;
    int size;
    HeadNodes *list;
} Graph;

Graph *create(int size, GraphType mode) {
    Graph *g = malloc(sizeof(Graph));
    g->mode = mode;
    g->size  = size;
    g->list = malloc(size * sizeof(HeadNodes));
    for(int i=0;i<size;i++) {
        g->list[i].head = NULL;
    }
    return g;
}

NODE *newnode(int data) {
    NODE *new = malloc(sizeof(NODE));
    new->data = data;
    new->next = NULL;
    return new;
}

void insert(Graph *g, int from, int to) {
    NODE *new = newnode(to);
    new->next = g->list[from].head;
    g->list[from].head = new;
    if(g->mode == UNDIRECTED) {
        NODE *new = newnode(from);
        new->next = g->list[to].head;
        g->list[to].head = new;
    }
}

void delete(Graph *g, int from, int to) {
 //구현예정
}

void destroy(Graph *g) {
    for(int i=0;i < g->size;i++) {
        free(g->list[i].head);
    }
    g->size = 0;
    free(g->list);
}

void print(Graph *g) {
    for(int i=0;i<g->size;i++) {
        NODE *temp = g->list[i].head;
        printf("vertex %d : ",i);
        while(temp != NULL) {
            printf(" -> %d",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void DFS(Graph *g, int visited[],int start) {
    visited[start] = 1;
    printf("%d ",start);
    for(NODE *tmp = g->list[start].head; tmp != NULL; tmp = tmp->next) {
        if(!visited[tmp->data]) DFS(g, visited, tmp->data);
    }
    

}

int main(void) {
    
    Graph *g = create(5, UNDIRECTED);
    insert(g,0,1);
    insert(g,0,2);
    insert(g,0,3);
    insert(g,0,4);
    insert(g,1,3);
    insert(g,2,3);
    insert(g,2,4);
    insert(g,3,4);
    print(g);
    int visited_0[5] = {0,};
    printf("Depth-First Search : ");
    DFS(g,visited_0,0);
    destroy(g);
    printf("\n\n");

    g = create(5, DIRECTED);
    insert(g,0,1);
    insert(g,0,2);
    insert(g,0,3);
    insert(g,0,4);
    insert(g,1,3);
    insert(g,2,3);
    insert(g,2,4);
    insert(g,3,4);
    print(g);
    int visited_1[5] = {0,};
    printf("Depth-First Search : ");
    DFS(g,visited_1,1);
    destroy(g);
    
}