#include<stdio.h>
int min(int a,int b)
{
   if(a>b)return b;
   return a;
}
int main()
{
   int n;
   while(scanf("%d",&n)!=EOF)
    {
       int s[105]={0},dp[105][105],i,j,a,k,l;
       for(i=1;i<=n;i++)
          scanf("%d",&a),s[i]=s[i-1]+a;
       for(i=1;i<=n;i++) dp[i][i]=0;
       for(l=2;l<=n;l++){
          for(i=1;i<n-l+2;i++){
             j=i+l-1;
             dp[i][j]=100000009;
            for(k=i;k<j;k++){
                 int a=(s[k]-s[i-1])%100;
                int b= (s[j]-s[k])%100;
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+a*b);
             }

         }
        }
       printf("%d\n",dp[1][n]);
    }

}
