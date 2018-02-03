#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
    char name[20];
    int code;
    int available;
    float price;
    struct node* next;
}node;

int main(){
    node* head = NULL;
    char *welcome = "Welcome to the store, press the prompts to proceed";
    char *menu[] = {"'a' for add item","'b' to update item price","'c' to update item quantity","'d' to sell items","'e' for printing the item list","'f' to exit"};
    char inputString='a';
    printf("%s\n",welcome);
    for(int i=0;i<6;i++) printf("%s\n",menu[i]);
    while(inputString != 'f'){

        scanf("%c",&inputString);
        if(inputString != 'f'){
            switch(inputString){
                case 'a':{
                    node* newNode = (node*)malloc(sizeof(node));
                    memset(newNode,0,sizeof(newNode));
                    node* temp;
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
                    //memset(newNode,0,sizeof(newNode));
                    newNode->next = NULL;
                    printf("Enter the name: ");
                    scanf("%s",newNode->name);
                    printf("Enter the code: ");
                    scanf("%d",&newNode->code);
                    printf("Enter the quantity: ");
                    scanf("%d",&newNode->available);
                    printf("Enter the price: ");
                    scanf("%f",&newNode->price);
                    printf("%s added to the inventory\n\n",newNode->name);
                    printf("%s\n",welcome);
                    for(int i=0;i<6;i++) printf("%s\n",menu[i]);
                    break;
                }
                case 'b':{
                    int change,flag=0;
                    printf("Enter the item code to update: ");
                    scanf("%d",&change);
                    node* temp = head;
                    while(temp != NULL){
                        if(temp->code == change) {
                            flag = 1;
                            break;
                        }
                        else
                            temp = temp->next;
                    }
                    if(flag){
                        float newPrice;
                        printf("Enter the new price of the item %s: ",temp->name);
                        scanf("%f",&newPrice);
                        printf("The value of price is changed from %f to ",temp->price);
                        temp->price = newPrice;
                        printf("%f\n\n",temp->price);
                        printf("%s\n",welcome);
                        for(int i=0;i<6;i++) printf("%s\n",menu[i]);
                        break;
                    }
                    else{
                        printf("Not found\n");
                    }
                }
                case 'c':{
                    int change,flag=0;
                    printf("Enter the item code to update: ");
                    scanf("%d",&change);
                    node* temp = head;
                    while(temp != NULL){
                        if(temp->code == change) {
                            flag = 1;
                            break;
                        }
                        else
                            temp = temp->next;
                    }
                    if(flag){
                        int newPrice;
                        printf("Enter the new stock of the item %s: ",temp->name);
                        scanf("%d",&newPrice);
                        printf("The value of stock is changed from %d to ",temp->available);
                        temp->available = newPrice;
                        printf("%d\n\n",temp->available);
                        printf("%s\n",welcome);
                        for(int i=0;i<6;i++) printf("%s\n",menu[i]);
                        break;
                    }
                    else{
                        printf("Not found\n");
                    }
                }
                case 'd':{
                    char str[20];
                    memset(str,0,sizeof(str));
                    printf("Enter the item name to sell: ");
                    scanf("%s",str);
                    node* temp = head;
                    int flag=0;
                    while(temp != NULL){
                        if(strcmp(str,temp->name) == 0) {
                            flag = 1;
                            break;
                        }
                        else
                            temp = temp->next;
                    }
                    if(flag){
                        printf("Enter the quantity to sell: ");
                        int q;
                        scanf("%d",&q);
                        if(temp->available >= q){
                            temp->available = temp->available - q;
                            printf("Sold %d to customer, %d remaining\n\n",q,temp->available);
                        }
                        else{
                            printf("Not enough items, please update stock\n\n");
                        }
                    }
                    else{
                        printf("Not found\n\n");
                    }
                    printf("%s\n",welcome);
                    for(int i=0;i<6;i++) printf("%s\n",menu[i]);
                    break;
                }
                case 'e':{
                    printf("\nThe item list is\n");
                    node* temp = head;
                    while(temp != NULL){
                        printf("Name: %s\nItem Code: %d\nPrice: %f\nQuantity Available: %d\n\n",temp->name,temp->code,temp->price,temp->available);
                        temp = temp->next;
                    }
                    printf("%s\n",welcome);
                    for(int i=0;i<6;i++) printf("%s\n",menu[i]);
                    break;
                }
                case 'f':{
                    break;
                }
                default:{
                        if(inputString != '\n'){
                        printf("Wrong input\n");
                        printf("%s\n",welcome);
                        for(int i=0;i<6;i++) printf("%s\n",menu[i]);
                    }
                }
            }
        }
    }


    return 0;
}
