#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
    int frequency;
    char c;
}Node;
int search(char x, int n, Node a[n]);
Node* add(char c, int* n, Node a[*n]);
int main(){
    char c;
    int n=0;
    Node *a;
    while(c != '\n'){
        scanf("%c",&c);
        if(c != '\n'){
            if(n==0){
                a = (Node*)malloc(sizeof(Node));
                a[0].c =c;
                a[0].frequency = 1;
                n++;
            }
            else{
                if(search(c,n,a) == 0){
                    a = add(c,&n,a);
                }
            }
        }
    }
    int i;
    for(i=0;i<n;i++){
        printf("\nCharacter is %c frequency is %d",a[i].c,a[i].frequency);
    }
    return 0;
}
int search(char x, int n, Node a[n]){
    int i,flag=0;
    for(i=0;i<n;i++){
        if(a[i].c == x){
            flag = 1;
            a[i].frequency++;
            printf("Found");
            break;
        }
    }
    return flag;
}
Node* add(char c, int* n, Node a[*n]){
    Node* newArr = (Node*)malloc((*n+1)*sizeof(Node));
    int i=0;
    for(i=0;i<*n;i++){
        newArr[i].c = a[i].c;
        newArr[i].frequency = a[i].frequency;
    }
    newArr[*n].c = c;
    newArr[*n].frequency = 1;
    (*n)++;
   /* for(i=0;i<*n;i++){
        printf("Character is %c frequency is %d",a[i].c,a[i].frequency);
    }*/
    free(a);
    return newArr;
}
