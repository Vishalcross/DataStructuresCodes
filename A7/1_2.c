#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define LENGTH 100000

void insertToMinHeap(long long int* array,long long int length,long long int elem){
	array[length]=elem;
	long long int pos=length,temp;
	while(pos>0){
		if(array[(pos-1)/2]>array[pos]){
			temp=array[pos];
			array[pos]=array[(pos-1)/2];
			array[(pos-1)/2]=temp;
			pos=(pos-1)/2;
		}
		else{
			break;
		}
	}
}
void insertToMaxHeap(long long int* array,long long int length,long long int elem){
	array[length]=elem;
	long long int pos=length,temp;
	while(pos>0){
		if(array[(pos-1)/2]<array[pos]){
			temp=array[pos];
			array[pos]=array[(pos-1)/2];
			array[(pos-1)/2]=temp;
			pos=(pos-1)/2;
		}
		else{
			break;
		}
	}
}
long long int deleteFromMinHeap(long long int* array,long long int length){
	long long int data,temp;
	data=array[0];
	array[0]=array[length-1];
	long long int pos=0;
	length--;
	while(pos<length){
		if(array[2*pos+1]<array[2*pos]+2){
			if(array[pos]<array[2*pos+1]){
				break;
			}
			temp=array[pos];
			array[pos]=array[2*pos+1];
			array[2*pos+1]=temp;
			pos=2*pos+1;
		}
		else{
			if(array[pos]<array[2*pos+2]){
				break;
			}
			temp=array[pos];
			array[pos]=array[2*pos+2];
			array[2*pos+2]=temp;
			pos=2*pos+2;
		}
	}
	return data;
}
long long int deleteFromMaxHeap(long long int* array,long long int length){
	long long int data,temp;
	data=array[0];
	array[0]=array[length-1];
	long long int pos=0;
	length--;
	while(pos<length){
		if(array[2*pos+1]>array[2*pos]+2){
			if(array[pos]>array[2*pos+1]){
				break;
			}
			temp=array[pos];
			array[pos]=array[2*pos+1];
			array[2*pos+1]=temp;
			pos=2*pos+1;
		}
		else{
			if(array[pos]>array[2*pos+2]){
				break;
			}
			temp=array[pos];
			array[pos]=array[2*pos+2];
			array[2*pos+2]=temp;
			pos=2*pos+2;
		}
	}
	return data;
}
int main(){
	long long int numOfElems,data,median;
	int flag=0;
	printf("Enter the number of elements\n");
	scanf("%lld",&numOfElems);
	long long int maxHeap[LENGTH],minHeap[LENGTH],lengthOfMaxHeap=0,lengthOfMinHeap=0;
	memset(maxHeap,0,sizeof(maxHeap));
	memset(minHeap,0,sizeof(minHeap));
	
	printf("Enter the data\n");
	scanf("%lld",&data);
	printf("%.1f\n",(double)data);
	median=data;
	for(long long int i=1;i<numOfElems;i++){
		printf("Enter input:");
		scanf("%lld",&data);
		if(i%2==1){//making an odd number of elements even
			if(data>median){
				insertToMinHeap(minHeap,lengthOfMinHeap,data);
				lengthOfMinHeap++;
				printf("%.1f\n",((double)minHeap[0]+median)/2);
			}
			else{
				insertToMaxHeap(maxHeap,lengthOfMaxHeap,data);
				lengthOfMaxHeap++;
				printf("%.1f\n",((double)maxHeap[0]+median)/2);
			}
		}
		else{//making an even number of elements odd
			if(lengthOfMaxHeap>lengthOfMinHeap){
				flag=0;
			}
			else{
				flag=1;
			}
			if(data>median){
				if(flag==0){//left has more elements
					insertToMinHeap(minHeap,lengthOfMinHeap,data);
					lengthOfMinHeap++;
				}
				else{//right has more elements
					insertToMaxHeap(maxHeap,lengthOfMaxHeap,median);
					lengthOfMaxHeap++;
					insertToMinHeap(minHeap,lengthOfMinHeap,data);
					lengthOfMinHeap++;
					median=deleteFromMinHeap(minHeap,lengthOfMinHeap);
					lengthOfMinHeap--;
				}
			}
			else{//data is less than equal to median
				if(flag==0){//left has more elements
					insertToMinHeap(minHeap,lengthOfMinHeap,median);
					lengthOfMinHeap++;
					insertToMaxHeap(maxHeap,lengthOfMaxHeap,data);
					lengthOfMaxHeap++;
					median=deleteFromMaxHeap(maxHeap,lengthOfMaxHeap);
					lengthOfMaxHeap--;
				}
				else{//right has more elements
					insertToMaxHeap(maxHeap,lengthOfMaxHeap,data);
					lengthOfMaxHeap++;
				}
			}
			printf("%.1f\n",(double)median);
		}
		printf("The minHeap contains\n");
		for(long long int m=0;m<lengthOfMinHeap;m++){
			printf("%lld ",minHeap[m]);
		}
		printf("\n");
		printf("The maxHeap contains\n");
		for(long long int m=0;m<lengthOfMaxHeap;m++){
			printf("%lld ",maxHeap[m]);
		}
		printf("\n");
	}
	return 0;
}