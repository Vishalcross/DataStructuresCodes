//stack using queues
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;
void enqueue(node*** head, int data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->next = NULL;
    newNode->data = data;
    if(**head == NULL){
        **head = newNode;
    }
    else{
        node* temp = **head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
int dequeue(node*** head){
    if(**head != NULL){
        node* temp = **head;
        int x = temp->data;
        **head = temp->next;
        free(temp);
        return x;
    }
    else{
        printf("No values inserted\n");
        return -100;
    }
}
void printQueue(node** head){
    node* temp = *head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void printStack(node* head){
    int count=0;
    if(head != NULL){
        node* temp = head;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        int a[count];
        temp = head;
        int y = count;
        while(count > 0){
            count--;
            a[count] = temp->data;
            //printf("%d ",a[count-1]);
            temp = temp->next;
        }
        for(int i=0;i<y;i++) printf("%d ",a[i]);
        printf("\n");
    }
    else{
        printf("Stack is empty\n");
        return;
    }
}
void push(node** head, int data){
    enqueue(&head,data);
}

int pop(node** head1, node** head2){
    if(*head1 != NULL){
        while((*head1)->next != NULL){
            enqueue(&head2,dequeue(&head1));
            printQueue(head1);
            printQueue(head2);
        }
        int x = (*head1)->data;
        node* temp1 = *head1;
        free(temp1);
        *head1 = NULL;
        while((*head2) != NULL){
            enqueue(&head1,dequeue(&head2));
        }
        return x;
    }
    else{
        printf("Stack is empty\n");
        return -100;
    }
}
int peekTop(node** head1){
    if(*head != NULL){
        while((*head1)->next != NULL){
            (*head1) = (*head1)->next;
        }
        return (*head1)->data;
    }
    else{
        printf("Stack is empty\n");
        return -100;
    }
}
int main(){
    node* qHead1 = NULL;
    node* qHead2 = NULL;
    push(&qHead1,1);
    push(&qHead1,2);
    push(&qHead1,3);
    printf("Initial Stack is \n");
    printStack(qHead1);
    printf("%d %d\n",pop(&qHead1,&qHead2));
    printStack(qHead1);
    return 0;
}
