//queue using stacks
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
    struct node* previous;
}node;

void printStack(node*** tail){
    if(**tail != NULL){
        int count = 0, t;
        node* temp = **tail;
        while(temp != NULL){
            //printf("%d ",temp->data);
            temp = temp->previous;
            count++;
        }
        t = count;
        temp = **tail;
        int a[count];
        while(temp != NULL){
            a[count-1] = temp->data;
            temp = temp->previous;
            count--;
        }
        count = t;
        for(int i=0;i<count;i++) printf("%d ",a[i]);
        printf("\n");
    }
    else{
        printf("Stack is empty\n");
        return;
    }
}
void printQueue(node** head){
    node** tail;
    node* temp = *head;
    while( temp->next != NULL){
        temp = temp->next;
    }
    tail = &temp;
    printStack(&tail);
}
void push(node*** head, node*** tail, int n){
    node* newNode = (node*)malloc(sizeof(node));
    node* temp = **head;
    newNode->data = n;
    newNode->next = NULL;
    if(**head == NULL){
        **head = newNode;
        newNode->previous = NULL;
        **tail = newNode;
    }
    else{
        temp = **tail;
        temp->next = newNode;
        **tail = newNode;
        newNode->previous = temp;
    }
    //printList(head);
}

int pop(node*** head, node*** tail){
    if(**tail != NULL){
        node* temp = **tail;
        if(**tail == **head){
            **tail = NULL;
            **head = NULL;
        }
        else{
            **tail = temp->previous;
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
void enqueue(node** head, node** tail, int data){
    push(&head, &tail, data);
}
int dequeue(node** head1, node** head2, node** tail1, node** tail2){
    if(*head1 != NULL){
        while((*tail1)->previous != NULL){
            push(&head2,&tail2,pop(&head1,&tail1));
        }
        int x = pop(&head1,&tail1);
        *head1 = NULL;
        *tail1 = NULL;
        while((*tail2) != NULL){
            push(&head1,&tail1,pop(&head2,&tail2));
        }
        return x;
    }
    else{
        printf("No values inserted\n");
        return -100;
    }
}
int main(){
    node* sHead1 = NULL;
    node* sTail1 = NULL;
    node* sHead2 = NULL;
    node* sTail2 = NULL;
    //node** temp = *sTail1;
    enqueue(&sHead1,&sTail1,1);
    enqueue(&sHead1,&sTail1,2);
    enqueue(&sHead1,&sTail1,3);
    //printQueue(&sHead1);
    printQueue(&sHead1);
    printf("%d \n",dequeue(&sHead1,&sHead2,&sTail1,&sTail2));
    return 0;
}
