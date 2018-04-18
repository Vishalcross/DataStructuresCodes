#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>
//aas
int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	int waste=0;
	while(1)
	{
		printf("enter\n");
		printf("waste=%d\n",waste);
		for(int i=0;i<n;i++)
			printf("a%d\t",a[i]);
		printf("\n");


		int count=0;
		for(int i=0;i<n;i++)
			if( a[i]==INT_MIN )
				count++;

		printf("count=%d\n",count);
		if(count==1)
			break;
		int sum[n];
		for(int i=0;i<n;i++)
			sum[i]=INT_MIN;
		for(int i=0;i<n;i++)
		{
			if( a[i]!=INT_MIN )
			{
				int j;
				for(j=i+1;j<n;j++)
				{
					if( a[j]!=INT_MIN )
					{
						sum[i]=a[j]+a[i];
						break;
					}
				}
			}
		}

		for(int i=0;i<n;i++)
			printf("s%d\t",sum[i]);
		printf("\n");
		int p=1;
		int max=INT_MAX;
		int maxind;

		printf("finding min sum >100\n");
		for(int i=0;i<n;i++)
			if( sum[i]>=100 && sum[i]<max )
			{
				p=0;
				max=sum[i];
				maxind=i;
			}
		if(p)
		{
			for(int i=0;i<n;i++)
			if( sum[i]<max && sum[i]>=0 )
			{
				p=1;
				max=sum[i];
				maxind=i;
			}
		}
		int j=maxind+1;
		printf("max=%d maxind=%d\n",max, maxind);
		while(j<n)
		{
			if( a[j]!=INT_MIN )
			{
				waste+=(a[maxind]*a[j]);
				a[maxind]=(a[maxind]+a[j])%100;
				a[j]=INT_MIN;
				break;
			}
			j++;
		}


	}
	printf("waste=%d\n",waste);
	return 0;

}
