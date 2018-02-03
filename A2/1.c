#include<stdio.h>
#include<string.h>
int count=0;
int ctoi(char c){
    int temp;
    switch(c){
        case '1': temp=1;
        break;
        case '2': temp=2;
        break;
        case '3': temp=3;
        break;
        case '4': temp=4;
        break;
        case '5': temp=5;
        break;
        case '6': temp=6;
        break;
        case '7': temp=7;
        break;
        case '8': temp=8;
        break;
        case '9': temp=9;
        break;
        default: temp=0;
    }
    return temp;
}
void comboReader(char* data){
    //printf("combo\n");
    int sum=0,b=1,temp=0;
    for(int i=15;i>=1;i-=2){
        if(data[i] == '+'){
            if(temp != 0){
                sum = sum + temp;
                temp=0;
            }
            else{
                int x = ctoi(data[i+1]);
                sum = sum + x;
            }
            b=1;
        }
        else if(data[i] == '-'){
            if(temp != 0){
                sum = sum - temp;
                temp=0;
            }
            else {
                int x = ctoi(data[i+1]);
                sum = sum - x;
            }
            b=1;
        }
        else{
            if(temp == 0){
                int x = ctoi(data[i+1]);
                temp = temp + (b*x);
                b*=10;
                x = ctoi(data[i-1]);
                temp = temp + (b*x);
                b*=10;
            }
            else{
                int x = ctoi(data[i-1]);
                temp = temp + (b*x);
                b*=10;
            }
        }
    }
   // printf("%d\n",sum);
    if(temp != 0)
        sum = sum+temp;
    else sum++;

    if(sum == 100) {
        printf("temp %d\n",temp);
        count++;
        for(int i=0;i<strlen(data);i++) if(data[i] != '~') printf("%c",data[i]);
        printf("\n");
    }
}
void makeCombination(char* data, int* index,int maxIndex, char* symbols){
   // printf("making combo\n");
    if(*index > maxIndex){
       // printf("%s\n",data);
        comboReader(data);
        return;
    }
    for(int i=0;i<3;i++){
     //   printf("for loop");
        data[*index] = symbols[i];
        *index += 2;
        makeCombination(data,index,maxIndex,symbols);
        *index-=2;
    }
}

int main(){
    char *data1 = "1 2 3 4 5 6 7 8 9";
    char *symbol = "+-~";
    char symbols[strlen(symbol)];
    char data[strlen(data1)];
    strcpy(data,data1);
    strcpy(symbols,symbol);
    int index = 1;
    //printf("%d",data[2]-'0');
    makeCombination(data,&index,15,symbols);
    printf("%d",count);
    return 0;
}
