#include<stdio.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#define length 100000
#define MODULUS 1000000007

long long int modMultiply(long long int a, long long int b){
    return ((a%MODULUS)*(b%MODULUS))%MODULUS;
}

void extendedEuclidean(long long int a, long long int b, long long int* x, long long int* y){
    //ax + by = 1
    if(b==0){//we know that the starting numbers are coprime so we needn't worry about gcd
        *x = 1;
        *y = 0;
        return;
    }
    long long int x1, y1;
    extendedEuclidean(b,a%b,&x1,&y1);
    *x = y1;
    *y = x1 - (a/b)*y1;
    //return gcd;
}

long long int findInverse(long long int a){
    long long int x, y;
    extendedEuclidean(a,MODULUS,&x,&y);
    if(x<0){
        x = (x%MODULUS + MODULUS)%MODULUS;
    }
    return x;
}

long long int solveForX(long long int a, long long int b){
    long long int inverse = findInverse(b);
    printf("Find inverse returns %lld product is %lld\n",inverse,a*inverse);
    return modMultiply(a,inverse);
}
int main(){
    srand(time(0));
	int numOfCases,lb,ub,alpha[26],alphaMod[26],sum;
	char buffer[length];
	memset(buffer,0,sizeof(buffer));
	printf("Enter the number of test cases\n");
	scanf("%d",&numOfCases);
	printf("Enter the string\n");
    for(int i=0;i<100;i++){
    //    buffer[i] = rand()%26 + 97;
    }
    //printf("The string is: %s\n",buffer);
	scanf("%s",buffer);
	for(int i=0;i<numOfCases;i++){
		printf("Enter the lower and the upper bound\n");
		scanf("%d%d",&lb,&ub);

		memset(alpha,0,sizeof(alpha));
		sum=0;

		for(int i=lb-1;i<ub;i++){
			alpha[buffer[i]-97]++;
		}
		for(int i=0;i<26;i++){
			alphaMod[i]=alpha[i]%2;
			alpha[i]/=2;
			sum+=alpha[i];
		}
        for(int i=0;i<26;i++) printf("%c %d ",i+97,alpha[i]);
        printf("\n");
        for(int i=0;i<26;i++) printf("%c %d ",i+97,alphaMod[i]);
        printf("\n");

		printf("\nThe sum is:%d\n",sum);

        long long int numerator = 1, denominator = 1;
        while(sum > 0){
            numerator = modMultiply(numerator,sum);
            sum--;
        }
        for(int i=0;i<26;i++){
            while(alpha[i] > 0){
                denominator = modMultiply(denominator,alpha[i]);
                alpha[i]--;
            }
        }
        int count = 0;
        long long int answer = 0;
        for(int i=0;i<26;i++){
            if(alphaMod[i] == 1) count++;
        }
        answer = solveForX(numerator,denominator);
        printf("Answer before considering odd terms %lld, numerator is %lld, denominator is %lld, count is %d\n", answer,numerator,denominator,count);
        printf("The answer is %lld\n", modMultiply(answer,count));
	}
	return 0;
}
