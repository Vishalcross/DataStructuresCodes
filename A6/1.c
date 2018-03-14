// C++ program to find maximum rectangular area in linear time
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

void printStack(node* head){
    if(head != NULL){
        node* temp = head;
        while(temp != NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
    else{
        printf("Stack is empty\n");
        return;
    }
}
void push(node** head, int n){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = n;
    if(*head == NULL){
        *head = newNode;
        newNode->next = NULL;
    }
    else{
        newNode->next = *head;
        *head = newNode;
    }
    //printList(head);
}

int pop(node** head){
    if(*head != NULL){
        int x = (*head)->data;
        node* temp = *head;
        (*head) = (*head)->next;
        free(temp);
        return x;
    }
    else{
        printf("Stack is empty\n");
        return -100;
    }
}
int peek(node** head){
    if(*head != NULL){
        return (*head)->data;
    }
    else{
        printf("Stack is empty\n");
        return -100;
    }
}

// The main function to find the maximum rectangular area under given
// histogram with n bars
int getMaxArea(int hist[], int n){
    // Create an empty stack. The stack holds indexes of hist[] array
    // The bars stored in stack are always in increasing order of their
    // heights.
    node* head = NULL;

    int max_area = 0; // Initalize max area
    int tp;  // To store top of stack
    int area_with_top; // To store area with top bar as the smallest bar

    // Run through all bars of given histogram
    int i = 0;
    while (i < n){
        // If this bar is higher than the bar on top stack, push it to stack
        if ((peek(&head) == -100) || hist[peek(&head)] <= hist[i])
            push(&head,i++);

        // If this bar is lower than top of stack, then calculate area of rectangle
        // with stack top as the smallest (or minimum height) bar. 'i' is
        // 'right index' for the top and element before top in stack is 'left index'
        else{
            tp = peek(&head);  // store the top index
            pop(&head);  // pop the top

            // Calculate the area with hist[tp] stack as smallest bar
            area_with_top = hist[tp] * ( (peek(&head) == -100) ? i : i - peek(&head) - 1);

            // update max area, if needed
            if (max_area < area_with_top)
                max_area = area_with_top;
        }
    }

    // Now pop the remaining bars from stack and calculate area with every
    // popped bar as the smallest bar
    while (peek(&head) != -100){
        tp = peek(&head);
        pop(&head);
        area_with_top = hist[tp] * ((peek(&head) == -100) ? i : i - peek(&head) - 1);

        if (max_area < area_with_top)
            max_area = area_with_top;
    }

    return max_area;
}

// Driver program to test above function
int main(){
    int hist[] = {6, 6, 6,6, 6, 6, 6};
    int n = sizeof(hist)/sizeof(hist[0]);
    printf("The max area is %d\n",getMaxArea(hist,n));
    return 0;
}
