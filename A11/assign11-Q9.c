#include <stdio.h>
#include <string.h>
#define MIN(a,b) ((a)<=(b)?(a):(b))
#define MAX(a,b) ((a)>=(b)?(a):(b))

char x[1005];
char y[1005];

int dp[1005][1005];
int solve(int i,int j)
{
	if(i==0)
		return j;
	else if(j==0)
		return i;
	if(x[i-1]==y[j-1])
		dp[i][j]=solve(i-1,j-1);
	else
		dp[i][j]=1+MIN(solve(i,j-1),MIN(solve(i-1,j-1),solve(i-1,j)));
	return dp[i][j];
}

int main()
{
	for(int i=0;i<=1000;i++)
		for(int j=0;j<=1000;j++)
			dp[i][j]=-1;

	scanf("%s",x);
	scanf("%s",y);
	int l1=strlen(x);
	int l2=strlen(y);

	printf("%d ",solve(l1,l2));
	return 0;
}