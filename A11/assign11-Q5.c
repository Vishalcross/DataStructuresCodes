#include <stdio.h>
#include <string.h>
#define MIN(a,b) ((a)<=(b)?(a):(b))
#define MAX(a,b) ((a)>=(b)?(a):(b))


char str1[1005];
char str2[1005];
char ans[10005];
int dp[1005][1005];

void solve(int l1,int l2)
{
	for(int i=0;i<=l1;i++)
	{
		for(int j=0;j<=l2;j++)
		{
			if(i==0 || j==0 )
				dp[i][j]=0;
			else if(str1[i-1]==str2[j-1])
				dp[i][j]=1+dp[i-1][j-1];
			else
				dp[i][j]=MAX(dp[i-1][j],dp[i][j-1]);
		}
	}
}

int main()
{
	for(int i=0;i<=1000;i++)
		for(int j=0;j<=1000;j++)
			dp[i][j]=-1;

	scanf("%s",str1);
	scanf("%s",str2);
	int l1=strlen(str1);
	int l2=strlen(str2);
	solve(l1,l2);
	int p=dp[l1][l2];
	ans[p]='\0';
	int i=l1,j=l2;
	while(i>0 && j>0)
	{
		if(str1[i-1]==str2[j-1])
			ans[--p]=str1[i-1],i--,j--;
		else if(dp[i-1][j]>dp[i][j-1])
			i--;
		else j--;
	}

	printf("%d %s",dp[l1][l2],ans);
	return 0;
}
