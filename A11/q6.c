#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>
int max(int i, int j, int k)
{
	int max=i;
	if( j>max )
		max=j;
	if( k>max)
		max=k;
	return max;
}

void findmaxseq(char a[], char b[],char c[] ,int m, int n,int o )
{
	int dp[m+1][n+1][o+1];
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			for(int k=0;k<=o;k++)
			{
				if( i==0 || j==0 || k==0 )
					dp[i][j][k]=0;
				else if( a[i-1]==b[j-1] && b[j-1]==c[k-1] )
					dp[i][j][k]=dp[i-1][j-1][k-1]+1;
				else
					dp[i][j][k]=max(dp[i-1][j][k],dp[i][j-1][k],dp[i][j][k-1]);
			}
		}
	}

	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			for(int k=0;k<=o;k++)
			{
				printf("%d ",dp[i][j][k]);
			}
			printf("\n");
		}
		printf("\n\n");
	}

	int len=dp[m][n][o];
	printf("len=%d\n",len);
	char final[len+1];
	final[len]='\0';
	int i=m;
	int j=n;
	int k=o;
	while(i>0 && j>0 && k>0)
	{
		if( a[i-1]==b[j-1] && b[j-1]==c[k-1] )
		{
			final[len-1]=b[j-1];
			len--;
			i--;
			j--;
			k--;
		}
		else if( dp[i-1][j][k]>=dp[i][j-1][k] && dp[i-1][j][k]>=dp[i][j][k-1] )
			i--;
		else if( dp[i][j-1][k]>=dp[i-1][j][k] && dp[i][j-1][k]>=dp[i][j][k-1]  )
			j--;
		else
			k--;

	}
	printf("subsequence=%s\n",final);

}


int main()
{
	char a[1000],b[10000],c[10000];
	scanf("%s\n",a);
	scanf("%s\n",b);
	scanf("%s",c);
	int m=strlen(a);
	int n=strlen(b);
	int o=strlen(c);
	findmaxseq(a,b,c,m,n,o);
	return 0;
}