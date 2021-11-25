#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int heap[100];
    int heap_size;
} HeapType;

HeapType *createHeap() {
    HeapType *h = malloc(sizeof(HeapType));
    h->heap_size = 0;
    return h;
}

void insert(HeapType *h, int key) {
    h->heap[++(h->heap_size)] = key;
    int i = h->heap_size;
    while((i!=1)&&(h->heap[i/2] < key)) {
        h->heap[i] = h->heap[i/2];
        i /= 2;
    }
    h->heap[i] = key;
}

int delete(HeapType *h) {
    int parent, child;
    int item, temp; 

    item = h->heap[1];
    temp = h->heap[h->heap_size];
    h->heap_size--;
    parent = 1;
    child = 2;
    while(child <= h->heap_size) {
        if((child < h->heap_size) && h->heap[child] < h->heap[child+1]) {
            child++;
        }
        if(temp >= h->heap[child]) break;
        else {
            h->heap[parent] = h->heap[child];
            parent = child;
            child *= 2;
        }
    }
    h->heap[parent] = temp;
    printf("return : %d\n",item);
    return item;

}

void preorder(HeapType *h, int index) {
    if(index > h->heap_size) return;
    printf("%d ",h->heap[index]);
    preorder(h,index*2);
    preorder(h,index*2+1);
}


int main() {
    HeapType *h = createHeap();
    
    insert(h, 1);
    insert(h, 2);
    insert(h, 3);
    insert(h, 4);
    preorder(h,1);
    printf("\n");
    insert(h, 5);
    preorder(h,1);
    printf("\n");
    delete(h);
    preorder(h,1);
}