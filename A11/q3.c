#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>

void merge(int a[], int b[], int left, int mid, int right)
{
	int temp1[right+1];
	int temp2[right+1];
	for(int i=left;i<=right;i++)
	{
		temp1[i]=a[i];
		temp2[i]=b[i];
	}
	int i=left;
	int j=mid+1;
	int k=left;
	while(i<=mid && j>=right)
	{
		if( temp1[i]<temp1[j])
		{
			a[k]=temp1[i];
			b[k++]=temp2[i++];		
		}
		else
		{
			a[k]=temp1[j];
			b[k++]=temp2[j++];

		}
	}
	while(i<=mid)
	{
		a[k]=temp1[i];
		b[k++]=temp2[i++];
	}
	while(j<=right)
	{
		a[k]=temp1[j];
		b[k++]=temp2[j++];
	}
}

void mergesort( int a[], int b[], int left, int right)
{
	if(left<right)
	{
		int mid=(left+right)/2;
		mergesort(a,b,left,mid);
		mergesort(a,b,mid+1,right);
		merge(a,b,left,mid,right);
	}
}


int main()
{
	int t;
	scanf("%d",&t);
	for(int xx=0;xx<t;xx++)
	{
		int x,m,n;
		int weight[102];
		int color[102];
		int stone[102][102];
		mergesort(weight, color, 0 , n-1);
		//i =color , ith row contains all weights of color i
		scanf("%d%d%d",&n,&m,&x);
		memset(stone,0,sizeof(stone));
		for(int i=1;i<=m;i++)
			stone[i][0]=1;
		//stone[i][0]=last index+1;
		for(int i=0;i<n;i++)
			scanf("%d",&weight[i]);
		for(int i=0;i<n;i++)
			scanf("%d",&color[i]);
		for(int i=0;i<n;i++)
			stone[color[i]][stone[color[i]][0]++]=weight[i];
		int p=0;
		for(int i=1;i<=m;i++)
		{
			if( stone[i][0]==1)
			{
				p=1;
				printf("-1\n");
				break;
			}
		}
		if(p)
			 continue;
		
		int sum=0;
		for(int i=1;i<=m;i++)
			sum+=stone[i][1];
		if(sum>x)
		{
			printf("-1\n");
			p=1;
		}
		if(p)
			 continue;
		int weightt=0;
		for(int i=1;i<=m;i++)
			weightt+=stone[i][stone[i][0]-1];
		while(1)
		{
			if( weightt<=x)
				break;
			int diff[n+1];
			for(int i=1;i<=m;i++)
				diff[i]=INT_MAX;
			for(int i=1;i<=m;i++)
				if( stone[i][0]>2 )
					diff[i]=stone[i][stone[i][0]-1]-stone[i][stone[i][0]-2];
			int minind=1;
			int min=INT_MAX;
			for(int i=1;i<=m;i++)
			{
				if( diff[i]<min )
				{
					minind=i;
					min=diff[minind];
				}
			}
			weightt-=diff[minind];
			stone[minind][0]--;
		}
		printf("unusedcapacity=%d\n",x-weightt);

	}
}