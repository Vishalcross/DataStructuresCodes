#include<stdio.h>
#include<math.h>
int main(){
    int n,i;
    scanf("%d",&n);
    if(n<=33){
        long long int temp = (long long int)pow(2,n);
        printf("%lld",temp);
    }
    else{
        long long int temp = (long long int)pow(2,34);
        temp = temp%10000000000;
        for(i=0;i<n-34;i++){
            temp *= 2;
            temp = temp%10000000000;
        }
        printf("%lld",temp);
    }
    return 0;
}
