#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>

int big(int a[],int n)
{
	int i,j;
	if(n<2)
		return n;
	if(n==2)
		return (a[1]%a[0]==0);
	int dp[100][100];
	int llgp=1;
	for(i=0;i<n;i++)
	{
		if(a[n-i]%a[i]==0)
			dp[i][n-1]=2;
		else dp[i][n-1]=1;
	}
	for(j=n-2;j>=1;j--)
	{
		i=j-1;
		int k=j+1;
		while(i>=0 && k<=n-1)
		{
			if(a[k]*a[i]>a[j]*a[j])
			{
				if(a[j]%a[i]==0)
					dp[i][j]=2;
				else dp[i][j]=1;
				i--;
			}
			else if(a[k]*a[i]<a[j]*a[j])
			{
				k++;
			}
			else
			{
				dp[i][j]=dp[j][k]+1;
				if(dp[i][j]>llgp)
					llgp=dp[i][j];
				i--;
				k++;
			}
		}
		while(i>=0)
		{
			if(a[j]%a[i]==0)
				dp[i][j]=2;
			else
				dp[i][j]=1;
			i--;
		}

	}
	return llgp;
}

int main()
{
	int n,i;
	int a[101];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int max=big(a,n);
	printf("%d\n",max);
	return 0;
}
