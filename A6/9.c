#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
typedef struct node{
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
}
void detectCycle(){
    node* temp1 = head;
    node* temp2 = head;
    while(temp1 != NULL && temp2 != NULL && temp2->next != NULL){
        temp1 = temp1->next;
        temp2 = temp2->next->next;
        if(temp1 == temp2){
            printf("Cycle\n");
            return;
        }
    }
    printf("No Cycle\n");
}
int main(){
    int n,c;
    srand(time(0));
    scanf("%d %d",&n,&c);
    for(int i=0;i<n;i++){
        int x = rand();
        add(x%100);
    }
    printList();
    if(c == 1){
        node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = head;
    }
    detectCycle();
    return 0;
}
