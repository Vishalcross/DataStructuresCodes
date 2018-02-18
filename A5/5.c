#include<stdio.h>
#include<string.h>
#include<math.h>
#define limit 44
#define bucketDepth 5
void bubbleSort(int length,int* array){
	int temp;
	for(int i=0;i<length-1;i++){
		for(int j=0;j<length-1;j++){
			if(array[j]>array[j+1]){
				temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
			}
		}
	}
}
void fillBuckets(int* array,int length){
	if(length<=limit){
		bubbleSort(length,array);
		printf("The final array contains\n");
		for(int i=0;i<length;i++){
			printf("%d ",array[i]);
		}
		int temp=0;
		while(array[temp]==0){
			temp++;
		}
		int length2=length-temp+1;
		float median=(length%2==0)?((float)array[temp+length2/2-1]+array[temp+length2/2])/2:array[temp+length2/2];
		printf("\n%f\n",median);
	}
	else{
		int size=(int)ceil(length/bucketDepth),buckets[size][bucketDepth],bucketNum=0,index=0,temp[size];
		memset(buckets,0,sizeof(buckets));
		memset(temp,0,sizeof(temp));

		for(int i=0;i<length;i++){
			buckets[bucketNum][index]=array[i];
			i++;
			index++;
			bucketNum+=index/bucketDepth;
			index%=bucketDepth;
		}

		for(int i=0;i<bucketNum;i++){
			bubbleSort(bucketDepth,buckets[i]);
		}

		for(int i=0;i<size;i++){
			temp[i]=buckets[i][bucketDepth/2];
		}
		fillBuckets(temp,size);
	}
}
int main(){
	int length;
	printf("Enter the length of the array\n");
	scanf("%d",&length);
	int array[length];
	memset(array,0,sizeof(array));

	printf("Enter the data within the array\n");
	for(int i=0;i<length;i++){
		scanf("%d",&array[i]);
	}

	fillBuckets(array,length);
	return 0;
}
