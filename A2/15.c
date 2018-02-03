#include<stdio.h>
#include<string.h>
int main(){
    int n,t;
    scanf("%d %d",&n,&t);
    int temp2=n,odigits=0;
    while(temp2){
        odigits++;
        temp2/=10;
    }
    while(t--){
        int digits=0;
        int temp = n;
        while(temp){
            digits++;
            temp/=10;
        }
        int size;
        n *= n;
        temp = n;
        int newDigit=0;
        while(temp){
            newDigit++;
            temp/=10;
        }
        size = newDigit;
        if(newDigit%2 != odigits%2){
            //printf("%d %d\n",newDigit,odigits);
            size++;
        }
        int a[size];
        for(int i=size-1;i>=0;i--){
            a[i] = n%10;
            n/=10;
        }

        for(int i=0;i<size;i++) printf("%d",a[i]);
        int index = digits/2;
       /* if(digits%2==0) index=digits/2;
        else index = digits/2 + 1;*/
        int b=1;
        int newNum=0;
        printf("\nsize %d\n",size);
        for(int i=0;i<odigits;i++){

            newNum += (b*a[size/2 + index - i]);
            b*=10;
        }
        int newNumDigit=0;
        temp = newNum;
        while(temp){
            newNumDigit++;
            temp/=10;
        }
        if(newNumDigit != odigits){

        }
        printf("\n%d\n",newNum);
        n = newNum;
    }
    return 0;
}
