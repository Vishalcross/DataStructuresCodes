#include <stdio.h>
#include <string.h>
#define MIN(a,b) ((a)<=(b)?(a):(b))
#define MAX(a,b) ((a)>=(b)?(a):(b))

int dp[1005][1005];
int max=1e9;

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)
	{
		dp[i][1]=1;
		dp[i][0]=0;
	}
	for(int i=1;i<=n;i++)
		dp[1][i]=i;

	for(int i=2;i<=k;i++)
	{
		for(int j=2;j<=n;j++)
		{
			dp[i][j]=max;
			for(int x=1;x<=j;x++)
			{
				int a=1+MAX(dp[i-1][x-1],dp[i][j-x]);
				dp[i][j]=MIN(dp[i][j],a);
			}
		}

	}
	printf("%d ",dp[k][n]);
	return 0;
}