#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
    int count;
    char c;
    struct node* next;
}Node;

int searchList(Node* head, char ch);
int main(){
    Node* head = NULL;
    char c;
    int flag=0,i=0;
    scanf("%c",&c);
    while(c != '\n'){
        printf("%d\n",i);
        if(head == NULL){
            printf("Head created\n");
            head = (Node*)malloc(sizeof(Node));
            head->c = c;
            head->next = NULL;
            head->count = 1;
        }
        else{
            int flag = searchList(head,c);
            if(flag) printf("match found");
            else{
                printf("creating new node");
                Node* newNode = (Node*)malloc(sizeof(Node));
                newNode->next = NULL;
                newNode->c = c;
                newNode->count = 1;
                Node* temp = head;
                while(temp->next != NULL){
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }
        i++;
        scanf("%c",&c);
    }
    Node* temp = head;
    printf("\n");
    while(temp != NULL){
        printf("%c %d\n",temp->c,temp->count);
        temp = temp->next;
    }
    return 0;
}
int searchList(Node* head, char ch){
    Node* temp;
    temp = head;
    int flag = 0;
    while(temp != NULL){
        if(temp->c == ch){
            temp->count++;
            flag = 1;
            break;
        }
        temp = temp->next;
    }
    if(flag) return 1;
    else return 0;
}
