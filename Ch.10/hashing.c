#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int address;
    int data;
} NODE;


typedef struct hashtable {
    NODE *node;
    int hashsize;
} HashTable;


int makehash(int value, int hashsize) {
    return value % hashsize;
}

HashTable *createhash(int hashsize) {
    HashTable *hashtable = malloc(sizeof(HashTable));
    hashtable->node = malloc(sizeof(NODE)*hashsize);
    hashtable->hashsize = hashsize;
    for(int i=0;i<hashsize;i++) hashtable->node[i].data = '\0';
    return hashtable;
}

void sethash(HashTable * hashtable, int data) { 
    int address = makehash(data, hashtable->hashsize);
    int i=0;
    while(1) {  //Linear Probing(선형조사법)
        if(hashtable->node[address].data == '\0') break;
        i++;
        address = makehash(data+i, hashtable->hashsize);
    }
    hashtable->node[address].address = address;
    hashtable->node[address].data = data;
}

int gethash(HashTable *hashtable, int data) {
    int address = makehash(data, hashtable->hashsize);
    int i=1;
    while(hashtable->node[address].data != data) { //Linear Probing(선형조사법)
        address = makehash(data+i, hashtable->hashsize);
        i++;
    }
    return hashtable->node[address].address;
}

void deletehash(HashTable *hashtable) {
    free(hashtable->node);
    free(hashtable);
}

int main() {
    HashTable *hash = createhash(201);

    sethash(hash, 1000);
    sethash(hash, 196);
    sethash(hash, 23);

    int address = gethash(hash, 1000);
    printf("Address : %d / Data : %d\n",address, hash->node[address].data);
    address = gethash(hash, 196); //Collision 발생 그래서 197주소에 데이터 저장
    printf("Address : %d / Data : %d\n",address, hash->node[address].data);
    

}

