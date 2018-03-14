#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    //int position;
    int data;
    int visited;
    struct node* next;
}node;
node* head = NULL;
void add(int n){
    node* newNode;
    node* temp;
    newNode = (node*)malloc(sizeof(node));
    //memset(newNode,0,sizeof(newNode));
    newNode->data = n;
    newNode->next = NULL;
    newNode->visited = 0;
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
int sit(int m, int n){
    node* temp = head;
    int total=0;

    while(1){
        printf("at %d\n",temp->data);
        temp->visited = 1;
        total++;
        if(total == n) return temp->data;
        int skip=0;
        while(skip < m){
            temp = temp->next;
            if(temp->visited == 0){
                skip++;
            }
        }
    }
    return temp->data;
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        add(i+1);
    }
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = head;
    printf("He sits at %d\n",sit(m,n));
    detectCycle();
    return 0;
}
