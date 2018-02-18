#include<string.h>
#include<stdio.h>
#include<math.h>
long long int l,r,mid,ans,m,k;
long long int dp[70][70][2],x[70];
long long int find(long long int now){
    int len=0;
    while(now){
        len++;
        x[len]=now%2;
        now=now/2;
    }
    memset(dp,0,sizeof(dp));
    dp[len][1][1]=1;
    for (int i=len-1;i;i--){
        for (int j=1;j<=len;j++){
            dp[i][j][0] = dp[i+1][j-1][0] + dp[i+1][j][0];
            if (x[i]==1){
                dp[i][j][0] += dp[i+1][j][1];
                dp[i][j][1] = dp[i+1][j-1][1];
            }
            else dp[i][j][1] = dp[i+1][j][1];
        }
    }
    long long int ans = dp[1][k][0] + dp[1][k][1];// if (kk==5) cout<<ans<<endl;
    memset(dp,0,sizeof(dp));
    if (len==1) return ans;
    dp[1][1][0]=1;
    if (k==1) ans++;
    for (int i=2;i<len;i++){
        for (int j=1;j<=len;j++) dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j-1][0];
        ans+=dp[i][k][0];
    }
    return ans;
}
int main(){
    scanf("%lld %lld",&m,&k);
    l=1; r = ((long long int)pow(10,18)) + 1;
    while (l<r){
        mid = l+r>>1;
        long long int num = find(mid*2)-find(mid); //cout<<mid<<" "<<num<<endl;
        if (num<m) l=mid+1;
        else {
            r=mid;
            ans=mid;
        }
    }
    printf("Answer %lld\n",ans);
}
