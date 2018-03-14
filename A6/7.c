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
void reverseIterative(){
    node* temp1 = head;
    node* temp2 = head->next;
    temp1->next = NULL;
    while(temp2 != NULL){
        node* t = temp2->next;
        temp2->next = temp1;
        temp1 = temp2;
        temp2 = t;
    }
    head = temp1;
}
void reverseRecursive(node* n, node* start){
    if(n->next->next == NULL){
        head = n->next;
        n->next->next = n;
        return;
    }
    else{
        reverseRecursive(n->next,start);
        n->next->next = n;
        if(n==start) n->next = NULL;
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
    //reverseIterative();
    node* temp = head;
    node* start = head;
    reverseRecursive(temp,start);
    printList();
    printf("\n");
    return 0;
}
