#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
    long long int maxSize = 100000,a,b,factors,size=0;
    long long int arr[maxSize],primes[maxSize];
    memset(arr,-1,sizeof(arr));
    for(long long int i=2;i<maxSize;i++){
        for(long long int j=i;j<maxSize;j+=i){
            arr[j]++;
        }
    }
    for(long long int i=2;i<maxSize;i++){
        if(arr[i] == 0){
            primes[size++]= i;
        }
    }
    //for(long long int i=0;i<size;i++) printf("%lld\n",primes[i]);
    scanf("%lld %lld %lld",&a,&b,&factors);
    long long int count,temp,product,valid=0;
    for(long long int i=a;i<=b;i++){
        temp = i;
        product = 1;
        for(long long int j=0;j<size && temp!=1;j++){
            count=0;
            while(temp%primes[j]==0 && temp!=1){
                temp/=primes[j];
                count++;
            }
            product *= (count+1);
        }
        if(product == factors) valid++;
    }
    printf("%lld\n",valid);
    return 0;
}
