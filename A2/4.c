#include<stdio.h>
#include<string.h>
int main(){
    int n;
    scanf("%d",&n);
    int temp=n;
    int a[4],i=0;
    memset(a,0,sizeof(a));
    while(temp){
        a[i++] = temp%10;
        temp /= 10;
    }
    char res[1000];
    memset(res,0,sizeof(res));

    char *ones[] = {"","one","two","three","four","five","six","seven","eight","nine"};
    char *tens[] = {"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
    char *twenties[] = {"twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninety"};

    if(a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0){
        strcat(res,"zero");
    }
    else{
        //
        strcat(res,ones[a[3]]);
        if(a[3] != 0){
            strcat(res," thousand ");
            if(a[2] == 0 && (a[1] != 0 || a[0] != 0)) strcat(res,"and ");
        }
        //hundreds
        strcat(res,ones[a[2]]);
        if(a[2] != 0){
            strcat(res," hundred ");
            if( a[1] != 0 || a[0] != 0){
                strcat(res,"and ");
            }
        }
        if(n%100 < 20){
            int x = n%100;
            if(x<10){
                strcat(res,ones[a[0]]);
            }
            else{
                strcat(res,tens[a[0]]);
            }
        }
        else{
            strcat(res,twenties[a[1] - 2]);
            strcat(res," ");
            strcat(res,ones[a[0]]);
        }
    }
    printf("%s",res);
    return 0;
}
