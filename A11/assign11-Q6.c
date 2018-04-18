#include <stdio.h>
#include <string.h>
#define MIN(a,b) ((a)<=(b)?(a):(b))
#define MAX(a,b) ((a)>=(b)?(a):(b))

char x[1005];
char y[1005];
char z[1005];
char ans[1005];
int dp[105][105][105];

int solve(int i,int j,int k)
{
	if(i<=0 || j<=0 || k<=0)
		return 0;
	if(dp[i][j][k]!=-1)
		return dp[i][j][k];
	if(x[i-1]==y[j-1] && y[j-1]==z[k-1])
		dp[i][j][k]=1+solve(i-1,j-1,k-1);
	else 
		dp[i][j][k]=MAX(solve(i-1,j,k),MAX(solve(i,j-1,k),solve(i,j,k-1)));
	return dp[i][j][k];
}

int main()
{
	for(int i=0;i<=100;i++)
		for(int j=0;j<=100;j++)
			for(int k=0;k<=100;k++)
				dp[i][j][k]=-1;

	scanf("%s",x);
	scanf("%s",y);
	scanf("%s",z);
	int l1=strlen(x);
	int l2=strlen(y);
	int l3=strlen(z);
	int p=solve(l1,l2,l3);
	ans[p]='\0';
	int i=l1,j=l2,k=l3;

	while(i>0 && j>0 && k>0)
	{
		if(x[i-1]==y[j-1] && y[j-1]==z[k-1])
			ans[--p]=x[i-1],i--,j--,k--;
		else if(dp[i-1][j][k]>=dp[i][j-1][k] && dp[i-1][j][k]>=dp[i][j][k-1])
			i--;
		else if(dp[i][j-1][k]>=dp[i-1][j][k] && dp[i][j-1][k]>=dp[i][j][k-1])
			j--;
		else k--;
	}
	printf("%d %s \n",dp[l1][l2][l3],ans);	
	return 0;
}
