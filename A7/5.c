#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;
void printList(node* head){
    node* temp = head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void insert(node** head, int data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
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
void mergeSortLinkedList(node** head, int length){
    printf("Into mergeSortLinkedList length %d\n",length);
    if(length <= 1){
        return;
    }
    node* left = *head;
    int mid = length/2;
    node* temp2 = *head;
    for(int i=0;i<mid;i++){
        temp2 = temp2->next;
    }
    node* right = temp2;
    mergeSortLinkedList(&left,mid);
    mergeSortLinkedList(&right,length - mid);
    node* temp = NULL;
    int l = 0;
    int r = mid;
    while(l<mid && r<length){
        if(left->data <= right->data){
            l++;
            insert(&temp,left->data);
            left = left->next;
        }
        else{
            r++;
            insert(&temp,right->data);
            right = right->next;
        }
    }

    while(l<mid){
        l++;
        insert(&temp,left->data);
        left = left->next;
    }
    while(r<length){
        r++;
        insert(&temp,right->data);
        right = right->next;
    }
    printList(temp);
    *head = temp;
}


int main(){
    node* head = NULL;
    int length = 0;
    scanf("%d",&length);
    for(int i=0;i<length;i++){
        int x;
        scanf("%d",&x);
        insert(&head,x);
    }
    mergeSortLinkedList(&head,length);
    printList(head);
}
