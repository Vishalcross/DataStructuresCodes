#include<stdio.h>
int main(){
    long long int n;
    long long int count=0;
    scanf("%lld",&n);
    while(n>0){
        printf("%d ",n%2);
        count += (n%2);
        n /= 2;
    }
    printf("\n%lld",count);
}
