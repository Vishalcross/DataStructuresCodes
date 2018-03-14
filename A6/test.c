#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct stack{
    int operators[201];
    int top;
}stack;
struct stack s;
void initialiseStack(){
    memset(s.operators,0,sizeof(s.operators));
    s.top = -1;
}

void push(char c){
    if(s.top == 200){
        printf("Stack is full\n");
        return;
    }
    else{
        s.top++;
        s.operators[s.top] = c;
    }
}

char pop(){
    if(s.top == -1){
        printf("Stack is empty\n");
        return -1;
    }
    else{
        return s.operators[s.top--];
    }
}

char peek(){
    if(s.top == -1){
        printf("Stack is empty\n");
        return -1;
    }
    else{
        return s.operators[s.top];
    }
}

int comparePrecedence(char op1, char op2){
    char prec1, prec2;
    switch(op1){
        case '/': prec1 = 4;break;
        case '*': prec1 = 3;break;
        case '+': prec1 = 2;break;
        case '-': prec1 = 1;break;
        default: prec1 = 0;
    }
    switch(op2){
        case '/': prec2 = 4;break;
        case '*': prec2 = 3;break;
        case '+': prec2 = 2;break;
        case '-': prec2 = 1;break;
        default: prec2 = 0;
    }
    return ((prec1>prec2)?1:0);
}
void infixToPostfix(char* infix, char* postfix){
    int iterator = 0;
    for(int i=0;infix[i] != '\0';i++){
        if(infix[i] == '('){
            push(infix[i]);
        }
        else if(isalpha(infix[i]) || (infix[i] >= '0' && infix[i] <= '9') || infix[i] == ' '){
            postfix[iterator++] = infix[i];
        }
        else if(infix[i] == ')'){
            while(s.operators[s.top] != '('){
                postfix[iterator++] = pop();
            }
            char waste = pop();
        }
        else if(infix[i]=='-'||infix[i]=='+'||infix[i]=='/'||infix[i]=='*'){
            if(s.top == -1){
                push(infix[i]);
            }
            else{
                while(comparePrecedence(peek(),infix[i]) == 1){
                    postfix[iterator++] = pop();
                }
                push(infix[i]);
            }
        }
    }
    while(s.top >= 0){
        postfix[iterator++] = pop();
    }
    postfix[iterator] = '\0';
}
int main(){
    initialiseStack();
    char infix[201], postfix[201];
    memset(infix,0,sizeof(infix));
    memset(postfix,0,sizeof(postfix));
    char c;
    int i=0;
    while(c != '\n' || i>200){
        scanf("%c",&c);
        if(c != '\n') infix[i++] = c;
    }
    infix[i] = '\0';
    infixToPostfix(infix,postfix);
    printf("%s",postfix);
    return 0;
}
