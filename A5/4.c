#include<stdio.h>
#include<string.h>
void fillMatrix(int * destination,int maxRow,int maxCol,int numOfColOrig,int source[][numOfColOrig],int start){
	int row=start,col=start,index=0;
	while(row<maxRow){
		destination[index]=source[row][col];
		row++;
		index++;
	}
	row--;
	col++;
	while(col<maxCol){
		destination[index]=source[row][col];
		col++;
		index++;
	}
	col--;
	row--;
	while(row>=start){
		destination[index]=source[row][col];
		row--;
		index++;
	}	
	row++;
	col--;
	while(col>start){
		destination[index]=source[row][col];
		col--;
		index++;
	}
}
void rotate(int length,int rotations,int* array){
	int temp[length];
	memset(temp,0,sizeof(temp));
	for(int i=0;i<length;i++){
		temp[(i+rotations)%length]=array[i];
	}
	for(int i=0;i<length;i++){
		array[i]=temp[i];
	}
}
void spitMatrix(int * source,int maxRow,int maxCol,int numOfColOrig,int destination[][numOfColOrig],int start){
	int row=start,col=start,index=0;
	while(row<maxRow){
		destination[row][col]=source[index];
		row++;
		index++;
	}
	row--;
	col++;
	while(col<maxCol){
		destination[row][col]=source[index];
		col++;
		index++;
	}
	col--;
	row--;
	while(row>=start){
		destination[row][col]=source[index];
		row--;
		index++;
	}	
	row++;
	col--;
	while(col>start){
		destination[row][col]=source[index];
		col--;
		index++;
	}
}
int main(){
	int maxRow,maxCol,iterLim,start,row,col,length;
	long long int rotations;
	printf("Enter the number of rows\n");
	scanf("%d",&maxRow);
	printf("Enter the number of columns\n");
	scanf("%d",&maxCol);
	printf("Enter the number of rotations\n");
	scanf("%lld",&rotations);
	int matrix[maxRow][maxCol];
	memset(matrix,0,sizeof(matrix));
	iterLim=(maxRow>maxCol?maxCol:maxRow);
	iterLim=(iterLim%2==0?iterLim/2:(iterLim+1)/2);
	printf("The iteration limit is:%d\n",iterLim);
	
	printf("Enter the data within the matrix\n");
	for(int i=0;i<maxRow;i++){
		for(int j=0;j<maxCol;j++){
			scanf("%d",&matrix[i][j]);
		}
	}
	start=0;
	row=maxRow;
	col=maxCol;
	for(int i=0;i<iterLim;i++){
		length=(row-start)*2+(col-start-2)*2;
		printf("The length of layer %d is:%d and offsetting to %d\n",i+1,length,start);
		int temp[length];
		memset(temp,0,sizeof(temp));
		fillMatrix(temp,row,col,maxCol,matrix,start);
		printf("The data within temp is:\n");
		for(int j=0;j<length;j++){
			printf("%d ",temp[j]);
		}
		printf("\n");
		rotate(length,rotations%length,temp);
		printf("The data within temp afer rotation\n");
		for(int j=0;j<length;j++){
			printf("%d ",temp[j]);
		}
		printf("\n");
		spitMatrix(temp,row,col,maxCol,matrix,start);
		printf("After finishing layer:%d\n",i+1);
		for(int m=0;m<maxRow;m++){
			for(int n=0;n<maxCol;n++){
				printf("%d ",matrix[m][n]);
			}
			printf("\n");
		}
		start++;
		row--;
		col--;
	}
	printf("The final answer is:\n");
	for(int i=0;i<maxRow;i++){
		for(int j=0;j<maxCol;j++){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}