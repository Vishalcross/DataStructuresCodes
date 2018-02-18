#include<stdio.h>
#include<string.h>
long long int gcd(long long int a, long long int b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}
long long int lcm(long long int a, long long int b){
    long long int hcf = gcd(a,b);
    return ((a*b)/hcf);
}
int main(){
    long long int t,n,a,b,sum;
    scanf("%lld",&t);
    for(long long int i=0;i<t;i++){
        scanf("%lld",&n);
        sum = 0;
        for(long long int j=1;j<=n;j++){
            sum += lcm(j,n);
        }
        printf("%lld\n",sum);
    }
    //long long int l = lcm(a,b);
    //long long int g = gcd(a,b);
    //long long int p = a*b;
    //printf("%lld %lld %lld\n", g,l,p);
    return 0;
}
