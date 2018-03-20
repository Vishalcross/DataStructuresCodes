#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;
void add(node** head, int data){
    node* newNode = (node*)malloc(sizeof(newNode));
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
void printLists(node* head1, node* head2){
    while(head1 != NULL){
        printf("%d ",head1->data);
        head1 = head1->next;
    }
    printf("\n");
    while(head2 != NULL){
        printf("%d ",head2->data);
        head2 = head2->next;
    }
    printf("\n");
}
int main(){
    node* list1 = NULL;
    node* list2 = NULL;
    int size1 = 0, size2 = 0;
    printf("Enter the sizes of the lists\n");
    scanf("%d %d", &size1,&size2);
    printf("Enter the data of the list 1\n");
    for(int i=0;i<size1;i++){
        int x;
        scanf("%d",&x);
        add(&list1,x);
    }
    printf("Enter the data of the list 2\n");
    for(int i=0;i<size2;i++){
        int x;
        scanf("%d",&x);
        add(&list2,x);
    }
    printLists(list1,list2);
    /*node* temp = list1;
    while(temp != NULL){
        temp = temp->next;
        size1++;
    }
    temp = list2;
    while(temp != NULL){
        temp = temp->next;
        size2++;
    }*/
    node* temp;
    if(size1 > size2){
        temp = list1;
        int offset = size1- size2;
        while(offset){
            temp = temp->next;
            offset--;
        }
        list1 = temp;
    }
    else{
        temp = list2;
        int offset = size2 - size1;
        while(offset){
            temp = temp->next;
            offset--;
        }
        list2 = temp;
    }
    while(list1->data != list2->data && list1->next != NULL){
        list1 = list1->next;
        list2 = list2->next;
    }
    printf("The intersection is at %d\n",list1->data);
    return 0;
}
