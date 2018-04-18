#include <stdio.h>
#include <string.h>
#define MIN(a,b) ((a)<=(b)?(a):(b))
#define MAX(a,b) ((a)>=(b)?(a):(b))

int dp[1005][1005];
int v[1005];
int adj[1005][1005];
int n;

int solve(int r,int s)
{
	if(dp[r][s]!=-1)
		return dp[r][s];

	int ans=0;
	if(s) ans=v[r];

	for(int i=0;i<=n;i++)
	{
		if(adj[r][i]==1)
		{
			if(s) ans+=solve(i,0);
			else ans+=MAX(solve(i,0),solve(i,1));
		}
	}
	dp[r][s]=ans;
	return ans;
}

int main()
{
	for(int i=0;i<=1000;i++)
		for(int j=0;j<=1000;j++)
			dp[i][j]=-1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&v[i]);
	int x,y;
	for(int i=0;i<n-1;i++)
	{
		scanf("%d%d",&x,&y);
		adj[x][y]=1;
	}
	printf("%d ",MAX(solve(1,0),solve(1,1)));
	return 0;
}
