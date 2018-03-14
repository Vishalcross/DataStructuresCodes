#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    int data;
    struct node* next;
    struct node* previous;
}node;

void printStack(node* tail){
    if(tail != NULL){
        node* temp = tail;
        while(temp != NULL){
            printf("%d ",temp->data);
            temp = temp->previous;
        }
        printf("\n");
    }
    else{
        printf("Stack is empty\n");
        return;
    }
}
void push(node** head, node** tail, int n){
    node* newNode = (node*)malloc(sizeof(node));
    node* temp = *head;
    newNode->data = n;
    newNode->next = NULL;
    if(*head == NULL){
        *head = newNode;
        newNode->previous = NULL;
        *tail = newNode;
    }
    else{
        temp = *tail;
        temp->next = newNode;
        *tail = newNode;
        newNode->previous = temp;
    }
    //printList(head);
}

int pop(node** head, node** tail){
    if(*tail != NULL){
        node* temp = *tail;
        if(*tail == *head){
            *tail = NULL;
            *head = NULL;
        }
        else{
            *tail = temp->previous;
            temp->previous->next = NULL;
        }
        int x = temp->data;
        free(temp);
        return x;
    }
    else{
        printf("Stack is empty\n");
        return -100;
    }
}
int main(){
    node* head = NULL;
    node* tail = NULL;
    push(&head, &tail, 5);
    push(&head, &tail, 2);
    push(&head, &tail, 3);
    printStack(tail);
    printf("%d\n",pop(&head,&tail));
    printStack(tail);
    printf("%d\n",pop(&head,&tail));
    printStack(tail);
    printf("%d\n",pop(&head,&tail));
    printStack(tail);
    return 0;
}
