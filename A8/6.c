#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    int data;
    struct node* right;
    struct node* left;
}node;
node* newNode(int data){
    node* n = (node*)malloc(sizeof(node));
    n->data = data;
    n->right = NULL;
    n->left = NULL;
    return n;
}
void visit(node* h, int* prints, int n){
    if(h == NULL) return;
    if(*prints < n){
        visit(h->left,prints,n);
        visit(h->right,prints,n);
        printf("%d ",h->data);
        (*prints)++;
    }
    else{
        printf("Cycles, therfore not a tree\n");
        return;
    }
}
int checkBST(node* root){
    if(root == NULL || root->left == NULL || root->right == NULL) return 1;
    if(root->left->data < root->data && root->right->data > root->data && checkBST(root->left) && checkBST(root->right)){
        return 1;
    }
    else return 0;
}
int main(){
    node* root = newNode(10);
    root->left = newNode(8);
    root->right = newNode(11);
    root->left->left = newNode(12);
    root->left->right = newNode(6);
    root->right->left = newNode(1);
    root->right->right = root;

    node* root1 = newNode(4);
    root1->left = newNode(2);
    root1->right = newNode(6);
    root1->left->left = newNode(1);
    root1->left->right = newNode(3);
    root1->right->left = newNode(5);
    root1->right->right = newNode(5);

    node* root2 = newNode(4);
    root2->left = newNode(2);
    root2->right = newNode(6);
    root2->left->left = newNode(1);
    root2->left->right = newNode(3);
    root2->right->left = newNode(5);
    root2->right->right = newNode(7);
    int prints = 0, n = 7;
    visit(root1,&prints,n);
    if(prints > n) printf("Cycle detected, not a tree\n");
    else{
        printf("Its a binary tree\n");
        int flag = checkBST(root1);
        ((flag == 0)?printf("Its not a BST\n"):printf("Its a BST\n"));
    }
    return 0;
}
