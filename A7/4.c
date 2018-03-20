#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;
void treeToList(node* root, node** head){
    if(root == NULL) return;
    static node* prev = NULL;
    treeToList(root->left,head);
    if(prev == NULL){
        *head = root;
    }
    else{
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    treeToList(root->right,head);
}
node* newNode(int data){
    node* n = (node*)malloc(sizeof(node));
    n->data= data;
    n->right = NULL;
    n->left = NULL;
    return n;
}
void printList(node* head){
    node* temp = head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->right;
    }
    printf("\n");
}
int main(){
    node* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    node* head = NULL;
    treeToList(root,&head);
    node* temp = head;
    while(temp->right != NULL){
        temp = temp->right;
    }
    temp->right = head;
    head->left = temp;
    //printList(head);
}
