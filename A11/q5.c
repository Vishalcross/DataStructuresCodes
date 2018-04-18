#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>
int max(int i, int j)
{
	if(i>j)
		return i;
	return j;
}

void findmaxseq(char a[], char b[], int m, int n)
{
	int dp[m+1][n+1];
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if( i==0 || j==0 )
				dp[i][j]=0;
			else if( a[i-1]==b[j-1] )
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	int len=dp[m][n];
	printf("len=%d\n",len);
	char final[len+1];
	final[len]='\0';
	int i=m;
	int j=n;
	while(i>0 && j>0)
	{
		if( a[i-1]==b[j-1] )
		{
			final[len-1]=b[j-1];
			len--;
			i--;
			j--;
		}
		else if( dp[i-1][j]>dp[i][j-1] )
			i--;
		else
			j--;
	}
	printf("subsequence=%s\n",final);

}


int main()
{
	char a[1000],b[10000];
	scanf("%s\n",a);
	scanf("%s",b);
	int m=strlen(a);
	int n=strlen(b);
	findmaxseq(a,b,m,n);
	return 0;
}