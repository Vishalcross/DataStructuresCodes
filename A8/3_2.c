#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

void DepthFirstSearch(long long int cur,long long int length,long long int adjMat[][length],int visited[],long long int* max,long long int val){
	visited[cur]=1;
	if(*max<val){
		*max=val;
	}
	for(long long int i=0;i<length;i++){
		if(adjMat[cur][i]!=0 && visited[i]==0){
			val+=adjMat[cur][i];
			DepthFirstSearch(i,length,adjMat,visited,max,val);
			val-=adjMat[cur][i];
		}
	}
	visited[cur]=0;
}
int main(){
	long long int numOfCities,max=-1,val=0;
	printf("Enter the number of cities\n");
	scanf("%lld",&numOfCities);
	char buffer[20];
	long long int adjMat[numOfCities][numOfCities];
	memset(adjMat,0,sizeof(adjMat));

	printf("Enter the data\n");
	for(long long int i=0;i<numOfCities;i++){
		for(long long int j=0;j<numOfCities;j++){
			scanf("%s",buffer);
			if(toupper(buffer[0])=='N'){
				adjMat[i][j]=0;
			}
			else{
				adjMat[i][j]=atoi(buffer);
			}
		}
	}
	printf("The adjecency matrix contains\n");
	for(long long int i=0;i<numOfCities;i++){
		for(long long int j=0;j<numOfCities;j++){
			printf("%lld ",adjMat[i][j]);
		}
		printf("\n");
	}
	int visited[numOfCities];
	memset(visited,0,sizeof(visited));

	for(long long int i=0;i<numOfCities;i++){
		DepthFirstSearch(i,numOfCities,adjMat,visited,&max,val);
	}
	printf("The answer is %lld\n",max);
}
