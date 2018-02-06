#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
long long int cop(int n,long long int* c,long long int * a,long long int val){
	long long int sum=0;
	int p;
	for(p=0;p<n;p++){
		sum=sum+abs(a[p]-val)*c[p];
	}
	return sum;


}


void main(){

	int n,i,j;
	long long high,low=0;
	high=LLONG_MIN;
	scanf("%d",&n);

	long long int a[n],c[n];

	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
		if(a[i]>high){
			high=a[i];
		}
	}
	for(i=0;i<n;i++){
		scanf("%lld",&c[i]);
	}

	high = high+1;
	long long int mid,ans;
	ans=LLONG_MAX;
	long long int bm=0,mm=0,am=0;
	while(high>low){
		mid = (high+low)>>1;

		if(mid>0){
			bm=cop(n,c,a,mid-1);

		}
		else{
			bm=LLONG_MAX;
		}
		mm=cop(n,c,a,mid);
		am=cop(n,c,a,mid+1);

		printf("mid is --%lld and bm is %lld and mm is %lld and am is %lld\n",mid,bm,mm,am );
		printf("high is %lld and low is  %lld\n",high,low );
		if(ans==mm||am==bm){
            ans=mm;
			break;
		}

		if(ans>mm){
			ans=mm;
		}

		if(bm<=mm){
			high = mid;
		}
		else if(am<=mm){
			low = mid;
		}




	}
	printf("%lld\n",ans );
	printf("%lld\n",mid );


}
