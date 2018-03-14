#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    int position;
    int data;
    struct node* next;
}node;
node* head = NULL;
void printList(){
    node* temp = head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}
void add(int n){
    node* newNode;
    node* temp;
    newNode = (node*)malloc(sizeof(node));
    //memset(newNode,0,sizeof(newNode));
    newNode->data = n;
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
    }
    else{
        temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    //printList(head);
}
void swapper(){
    node* temp = head;
    while(temp != NULL && temp->next != NULL){
        int t = temp->data;
        temp->data = temp->next->data;
        temp->next->data = t;
        temp = temp->next->next;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d", &x);
        add(x);
    }
    printList();
    printf("\n");
    swapper();
    printList();
    printf("\n");
    return 0;
}
