#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int flag=0;
void DepthFirstSearch(long long int cur,long long int length,int adjMat[][length],int visited[],long long int count,long long int countStore[]){
	visited[cur]=1;

	for(long long int i=0;i<length;i++){
		if(adjMat[cur][i]!=0){
			if(visited[i]==1 && ((adjMat[cur][i]==-1 && count+1-countStore[i]%2==0) || (adjMat[cur][i]==1 && count-countStore[i]%2==1)) ){
				flag=1;
			}
			else if(visited[i]==0){
				if(adjMat[cur][i]==-1){
					count++;
				}
				countStore[i]=count;
				DepthFirstSearch(i,length,adjMat,visited,count,countStore);
			}
		}
	}
	visited[cur]=0;
}
int main(){
	long long int numOfTestCases,numOfStatements,count=0;
	printf("Enter the number of test cases\n");
	scanf("%lld",&numOfTestCases);

	for(long long int i=0;i<numOfTestCases;i++){
		printf("Enter the number of statements\n");
		scanf("%lld",&numOfStatements);

		int adjMat[numOfStatements][numOfStatements];
		memset(adjMat,0,sizeof(adjMat));

		long long int data;
		char buffer[10];
		for(long long int j=0;j<numOfStatements;j++){
			scanf("%lld",&data);
			if(data<1 || data>numOfStatements){
				printf("Invalid data\n");
				j--;
				continue;
			}
			scanf("%s",buffer);

			if(toupper(buffer[0])=='F'){
				adjMat[j][data-1]=-1;
			}
			else{
				adjMat[j][data-1]=1;
			}
		}
		printf("The adjecency matrix has\n");
		for(long long int m=0;m<numOfStatements;m++){
			for(long long int n=0;n<numOfStatements;n++){
				printf("%d ",adjMat[m][n]);
			}
			printf("\n");
		}
		int visited[numOfStatements];
		long long int countStore[numOfStatements];
		memset(countStore,0,sizeof(countStore));
		memset(visited,0,sizeof(visited));
		for(long long int i=0;i<numOfStatements;i++){
			flag=0;
			DepthFirstSearch(i,numOfStatements,adjMat,visited,count,countStore);
			if(flag==1){
				printf("Paradox\n");
				break;
			}
		}
		if(flag==0){
			printf("No paradox bruv\n");
		}
	}
	return 0;
}
