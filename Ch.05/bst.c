#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
}Tree;

Tree *makenode(int data);
Tree *search_node(Tree *root, int key);
void insert_node(Tree **root, int key);
void preorder(Tree *root);

int main(void) {
    Tree *tree = NULL;
    Tree *n1 = malloc(sizeof(Tree));
    Tree *n2 = malloc(sizeof(Tree));
    Tree *n3 = malloc(sizeof(Tree));
    
    n1->data = 50;
    n1->left = n2;
    n1->right = n3;

    n2->data = 40;
    n2->left = NULL;
    n2->right = NULL;

    n3->data = 60;
    n3->left = NULL;
    n3->right = NULL;

    preorder(n1);
    printf("\n");
    insert_node(&n1, 10);
    insert_node(&n1,55);
    insert_node(&n1,61);
    preorder(n1);

}

void preorder(Tree *root) {
    if(root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}


Tree *makenode(int data){
    Tree *new = malloc(sizeof(Tree));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

Tree *search_node(Tree *root, int key) {
    if(root == NULL) return NULL;
    if(root->data == key) return root;
    else {
        if(key < root->data) search_node(root->left, key);
        else search_node(root->right, key);
    }
}

void insert_node(Tree **root, int key) {
    Tree *parent, *temp;
    Tree *newnode = makenode(key);
    temp = *root;
    while(temp != NULL) {
        if(temp->data == key) return;
        parent = temp;
        if(key < temp->data) temp = parent->left;
        else temp = parent->right;
    }
    
   if(parent != NULL) {
       if(key < parent->data) parent->left = newnode;
       else parent->right = newnode; 
   } 
   else *root = newnode;
}