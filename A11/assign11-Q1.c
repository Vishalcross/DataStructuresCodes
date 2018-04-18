#include <stdio.h>
#include <string.h>
#define MIN(a,b) ((a)<=(b)?(a):(b))
#define MAX(a,b) ((a)>=(b)?(a):(b))

int p[1005];
int dp[1005][1005];

int solve(int i,int j,int y)
{
	if(i>j)
		return 0;
	if(dp[i][j]!=-1)
		return dp[i][j];
	dp[i][j]=MAX(y*p[i]+solve(i+1,j,y+1),y*p[j]+solve(i,j-1,y+1));
	return dp[i][j];
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<=1000;i++)
		for(int j=0;j<=1000;j++)
			dp[i][j]=-1;

	for(int i=0;i<n;i++)
		scanf("%d",&p[i]);

	printf("%d",solve(0,n-1,1));
	return 0;
}
