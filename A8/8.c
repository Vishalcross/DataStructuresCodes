#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    int data;
    struct node* next;
}node;
void insert(node** head, int data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    if(*head == NULL){
        *head = newNode;
    }
    else{
        newNode->next = *head;
        *head = newNode;
    }
}
void printList(node* head){
    node* temp = head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void printHashTable(node* table[10]){
    for(int i=0;i<10;i++){
        printList(table[i]);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    node* table[10];
    for(int i=0;i<10;i++) table[i] = NULL;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        if(table[(a[i])%10] == NULL){
            insert(&table[(a[i])%10],a[i]);
        }
        else{
            if(table[7 - (a[i])%7] == NULL){
                insert(&table[7 - (a[i])%7],a[i]);
            }
            else{
                insert(&table[(a[i])%10],a[i]);
            }
        }
    }
    printHashTable(table);
    return 0;
}
