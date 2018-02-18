#include<stdio.h>
long long int res[1000010];
long long int phi[1000010];
void precal(long long int n){
    for(long long int i=1;i<=n;i++) phi[i] = i;
    for(long long int i=2;i<=n;i++){
        if(phi[i] == i){
            for(long long int j=i;j<=n;j+=i){
                phi[j] /= i;
                phi[j] *= (i-1);
            }
        }
    }
    for(long long int i=1;i<=n;i++){
        for(long long int j=i;j<=n;j+=i){
            res[j] += (i*phi[i]);
        }
    }
}
int main(){
    precal(1000000);
    long long int t,n;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        long long int ans = res[n] + 1;
        ans *= n;
        ans /= 2;
        printf("Answer is %lld\n",ans);
    }
    return 0;
}
