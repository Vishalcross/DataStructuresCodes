#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    int data;
    struct node* next;
    struct node* previous;
}node;
node* head = NULL;
node* tail = NULL;
void printList(){
    node* temp = head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}
void addBack(int n){
    node* newNode;
    node* temp;
    newNode = (node*)malloc(sizeof(node));
    //memset(newNode,0,sizeof(newNode));
    newNode->data = n;
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
        head->previous = NULL;
        tail = newNode;
    }
    else{
        temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        tail = newNode;
        newNode->previous = temp;
    }
    //printList(head);
}
void addFront(int n){
    node* newNode = (node*)malloc(sizeof(node));
    memset(newNode,0,sizeof(newNode));
    newNode->data = n;
    newNode->previous = NULL;
    if(head != NULL) {
        newNode->next = head;
    }
    else {
        head = newNode;
        tail = newNode;
        newNode->next = NULL;
    }
    head = newNode;
}

void removeFront(){
    node* temp = head;
    head = head->next;
    printf("Removed %d\n",temp->data);
    free(temp);
}
void removeBack(){
    node* temp = tail;
    tail = tail->previous;
    printf("Removed %d\n",temp->data);
    free(temp);
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d", &x);
        addFront(x);
    }
    printList();
    removeBack();
    removeFront();
    printList();
    return 0;
}
