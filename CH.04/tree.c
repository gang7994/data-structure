//트리 순회 구현(Tree traversal)
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    char data;
    struct TreeNode *left, *right;
} TreeNode;

void preorder(TreeNode *node) {
    if(node != NULL) {
        printf("%c ", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

void inorder(TreeNode *node) {
    if(node != NULL) {
        inorder(node->left);
        printf("%c ", node->data);
        inorder(node->right);
    }
}

void postorder(TreeNode *node) {
    if(node != NULL) {
        postorder(node->left);
        postorder(node->right);
        printf("%c ", node->data);
    }
}

int main() {
    TreeNode *n1 = malloc(sizeof(TreeNode));
    TreeNode *n2 = malloc(sizeof(TreeNode));
    TreeNode *n3 = malloc(sizeof(TreeNode));
    TreeNode *n4 = malloc(sizeof(TreeNode));
    TreeNode *n5 = malloc(sizeof(TreeNode));
    TreeNode *n6 = malloc(sizeof(TreeNode));
    TreeNode *n7 = malloc(sizeof(TreeNode));
    TreeNode *n8 = malloc(sizeof(TreeNode));
    TreeNode *n9 = malloc(sizeof(TreeNode));
    n1->data = 'F';
    n1->left = n2;
    n1->right = n3;

    n2->data = 'B';
    n2->left = n4;
    n2->right = n5;

    n3->data = 'G';
    n3->left = NULL;
    n3->right = n6;

    n4->data = 'A';
    n4->left = NULL;
    n4->right = NULL;

    n5->data = 'D';
    n5->left = n7;
    n5->right = n8;

    n6->data = 'I';
    n6->left = n9;
    n6->right = NULL;

    n7->data = 'C';
    n7->left = NULL;
    n7->right = NULL;

    n8->data = 'E';
    n8->left = NULL;
    n8->right = NULL;

    n9->data = 'H';
    n9->left = NULL;
    n9->right = NULL;
    
    printf("Preorder : "); //전위 순회 구현
    preorder(n1);
    printf("\n");

    printf("Inorder : "); //중위 순회 구현
    inorder(n1);
    printf("\n");

    printf("Postorder : "); //후위 순회 구현
    postorder(n1);
    printf("\n");
    
}