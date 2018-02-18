#include<stdio.h>
#include<string.h>
#include<math.h>

long long int findCount(long long int val,long long int seed){
	long long int temp,count=0;
	long long int c,r;
	while(seed<=val){
		temp=seed;
		c=(seed & -seed);
		r=c+seed;
		seed=((((r^seed)/c)>>2) | r);
		count++;
	}
	return count;
}

int main(){

	long long int upperLimit=(long long int)pow(10,18);
	long long int lowerLimit=1;
	long long int mid,countTillN,countTill2N,m,k,seed2;
	printf("Enter the number of k set digit numbers to be found\n");
	scanf("%lld",&m);
	printf("Enter the number of set digits\n");
	scanf("%lld",&k);
	long long int temp=(long long int)pow(2,k)-1;
	if(k==1 && m>1){
		printf("No solution exists\n");
	}
	else{
		while(lowerLimit<=upperLimit){
			mid=(upperLimit+lowerLimit)/2;
			seed2=temp;
			while(seed2<=mid){
				seed2<<=1;
			}
			seed2>>=1;
			printf("lowerLimit:%lld upperLimit:%lld mid:%lld\n",lowerLimit,upperLimit,mid);
			countTillN=findCount(mid,temp);
			countTill2N=findCount(2*mid,temp);
			if(m==(countTill2N-countTillN)){
				break;
			}
			else if(m<(countTill2N-countTillN)){
				upperLimit=mid-1;
			}
			else{
				lowerLimit=mid+1;
			}
		}
	}

	printf("The answer is:%lld\n",mid);
	return 0;
}
