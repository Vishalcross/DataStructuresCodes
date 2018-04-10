#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAXBITS 32

void convertToBinary(int size,int* array,int binRep[][MAXBITS]){
	int temp,index;
	for(int i=0;i<size;i++){
		temp=array[i];
		index=0;
		while(temp>0){
			binRep[i][index++]=temp&1;
			temp>>=1;
		}
	}
}
int convertToInt(int* array){
	int val=0;
	for(int i=0;i<MAXBITS;i++){
		val+=array[i]*(int)pow(2,i);
	}
	return val;
}
int main(){
	int length,count;
	printf("Enter the number of elements\n");
	scanf("%d",&length);
	int array[length],binRep[length][MAXBITS],answer[MAXBITS];
	memset(array,0,sizeof(array));
	memset(binRep,0,sizeof(binRep));
	memset(answer,0,sizeof(answer));

	printf("Enter the data within the array\n");
	for(int i=0;i<length;i++){
		scanf("%d",&array[i]);
	}

	convertToBinary(length,array,binRep);

	for(int i=0;i<MAXBITS-1;i++){
		count=0;
		for(int j=0;j<length;j++){
			if(binRep[j][i]==1){
				count++;
			}
		}
		if(count<=length/2){
			answer[i]=1;
		}
	}

	printf("The binary representation contains\n");
	for(int i=0;i<MAXBITS;i++){
		printf("%d",answer[i]);
	}
	printf("\n");
	printf("The answer is %d",convertToInt(answer));
	return 0;
}
