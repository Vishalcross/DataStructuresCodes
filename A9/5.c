#include<stdio.h>
#include<string.h>
int maxPath(int n){
    if(n == 1){
        return 0;
    }
    int count = 0;
    int divisors[10000];
    for(int i=1;i<=n/2;i++){
        if(n%i == 0){
            divisors[count++] = i;
        }
    }
    int theirDivisors[count];
    for(int i=0;i<count;i++){
        theirDivisors[i] = maxPath(divisors[i]);
    }
    int max = 0;
    for(int i=0;i<count;i++){
        if(theirDivisors[i] > max) max = theirDivisors[i];
    }
    return max + count + 1;
}
int main(){
    int u,v;
    scanf("%d %d",&u,&v);
    long long int sum = 0;
    for(int i=u;i<=v;i++) sum += maxPath(i);
    printf("%lld\n",sum);
    return 0;
}
