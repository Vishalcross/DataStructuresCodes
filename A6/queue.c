#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;
void enqueue(node** head, int data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->next = NULL;
    newNode->data = data;
    if(*head == NULL){
        *head = newNode;
    }
    else{
        node* temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
int dequeue(node** head){
    if(*head != NULL){
        node* temp = *head;
        int x = temp->data;
        *head = temp->next;
        free(temp);
        return x;
    }
    else{
        printf("No values inserted\n");
        return -100;
    }
}
void printQueue(node* head){
    node* temp = head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main(){
    node* head = NULL;
    enqueue(&head,2);
    enqueue(&head,4);
    enqueue(&head,3);
    printQueue(head);
}
