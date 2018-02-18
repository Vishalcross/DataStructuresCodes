#include<stdio.h>
#include<string.h>
#include<math.h>

int main(){
	long long int max=(int)pow(10,5),index=0;
	long long int array[max],start,end,numOfFactors,count,product,temp,answer=0;
	long long int primes[max];
	printf("Filling the sieve\n");
	memset(array,-1,sizeof(array));
	for(long long int i=2;i<max;i++){
		for(long long int j=i;j<max;j+=i){
			array[j]++;
		}
	}
	printf("Filling the primes\n");
	for(long long int i=2;i<max;i++){
		if(array[i]==0){
			primes[index]=i;
			index++;
		}
	}

//	printf("The prime numbers are:\n");
//	for(int i=0;i<index;i++){
	//	printf("%lld\n",primes[i]);
	//}
	printf("Enter the start value\n");
	scanf("%lld",&start);
	printf("Enter the end value\n");
	scanf("%lld",&end);
	printf("Enter the number of factors\n");
	scanf("%lld",&numOfFactors);

	for(int i=start;i<=end;i++){
		product=1;
		temp=i;
		for(int j=0;temp!=1 && j<index;j++){
			count=0;
			while(temp%primes[j]==0 && temp!=1){
				temp/=primes[j];
				count++;
			}
			product*=count+1;
		}
		if(product==numOfFactors){
			answer++;
		}
	}
	printf("The answer is:%lld\n",answer);
	return 0;
}
