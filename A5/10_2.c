#include<stdio.h>
#include<math.h>
long long int findFactors(long long int n){
    long long int count,temp = n,product=1,i;
    for(i=2;i<=sqrt(temp);i++){
        count = 0;
        while(temp%i == 0){
            temp/=i;
            count++;
        }
        product *= (count+1);
    }
    if(temp != 1){
        product *= 2;
    }
    return product;
}
int main(){
    long long int a,b,n,count=0;
    scanf("%lld %lld %lld",&a,&b,&n);
    for(long long int i=a;i<=b;i++){
        long long int value = findFactors(i);
        if(value == n) count++;
    }
    printf("%lld\n",count);
    return 0;
}
