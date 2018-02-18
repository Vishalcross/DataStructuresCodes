#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
    printf("Enter number of random numbers needed\n");
    long long int n;
    scanf("%lld",&n);
    srand(time(0));
    for(long long int i=0;i<n;i++){
        printf("%d ",rand()%1000000);
    }
    return 0;
}
