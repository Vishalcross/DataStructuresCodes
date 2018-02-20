#include<stdio.h>
#include<string.h>
#include<math.h>
#define numOfBits 66

void generateCombinations(int numberOfBits,long long int pascalsTriangle[][numberOfBits]){
	for(int i=0;i<numberOfBits;i++){
		pascalsTriangle[i][0]=1;
	}
	for(int i=1;i<numberOfBits;i++){
		for(int j=1;j<i;j++){
			pascalsTriangle[i][j]=pascalsTriangle[i-1][j-1]+pascalsTriangle[i-1][j];
		}
		pascalsTriangle[i][i]=1;
	}
	/*printf("The generated Pascals Triangle\n");
	for(int i=0;i<numberOfBits;i++){
		for(int j=0;j<numberOfBits;j++){
			printf("%lld ",pascalsTriangle[i][j]);
		}
		printf("\n");
	}*/
}
long long int findNumbers(int numberOfBits,long long int pascalsTriangle[][numberOfBits],long long int val,long long int k){
	int binRep[numberOfBits],index=0;
	long long int sum=1,temp1=k,temp2=val;
	memset(binRep,0,sizeof(binRep));

	while(val>0){
		binRep[index]=val%2;
		val/=2;
		index++;
	}
	for(int i=index-1;i>=0;i--){
		if(binRep[i]==1 && k<=i && k>=0){
			sum+=pascalsTriangle[i][k];
			k--;
		}
	}
	/*if(__builtin_popcount(temp2)==temp1){
		sum++;
	}*/
	return sum;
}
int main(){
	long long int m,k;
	long long int pascalsTriangle[numOfBits][numOfBits],mid;
	memset(pascalsTriangle,0,sizeof(pascalsTriangle));
	generateCombinations(numOfBits,pascalsTriangle);

	//printf("Enter the number of values to be found\n");
	scanf("%lld",&m);
	//printf("Enter the number of set bits\n");
	scanf("%lld",&k);
	if(k==1 && m>1){
		//printf("No solution\n");
	}
	else{
		long long int lowerBound=1,upperBound=(long long int)(pow(10,18)),temp;
		while(lowerBound<=upperBound){
			mid=(lowerBound+upperBound)/2;
			temp=findNumbers(numOfBits,pascalsTriangle,2*mid,k)-findNumbers(numOfBits,pascalsTriangle,mid,k);
			if(temp==m){
				break;
			}
			else if(temp>m){
				upperBound=mid-1;
			}
			else{
				lowerBound=mid+1;
			}
		}
	}
	//printf("The answer is:\n");
	printf("%lld\n",mid);
	//printf("%lld contained %lld such numbers\n",mid,findNumbers(numOfBits,pascalsTriangle,mid,k));
	//printf("%lld contained %lld such numbers\n",2*mid,findNumbers(numOfBits,pascalsTriangle,2*mid,k));
	return 0;
}
