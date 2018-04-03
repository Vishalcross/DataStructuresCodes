#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int flag=0;
void DepthFirstSearch(long long int cur, long long int length,long long int adjMat[][length],long long int val,long long int cost[],int visited[]){
	visited[cur]=1;
	cost[cur]=val;

	for(long long int i=0;i<length;i++){
		if(adjMat[cur][i]!=0){
			if(visited[i]==1 && (adjMat[cur][i]+cost[cur]-cost[i])<0){
				flag=1;
			}
			else if(visited[i]==0){
				val+=adjMat[cur][i];
				DepthFirstSearch(i,length,adjMat,val,cost,visited);
				val-=adjMat[cur][i];
			}
		}
	}

	visited[cur]=0;
	cost[cur]=0;
}
int main(){
	long long int numOfStates,val=0;
	printf("Enter the number of states\n");
	scanf("%lld",&numOfStates);
	char buffer[20];
	long long int adjMat[numOfStates][numOfStates];
	memset(adjMat,0,sizeof(adjMat));

	printf("Enter the data\n");
	for(long long int i=0;i<numOfStates;i++){
		for(long long int j=0;j<numOfStates;j++){
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
	for(long long int i=0;i<numOfStates;i++){
		for(long long int j=0;j<numOfStates;j++){
			printf("%lld ",adjMat[i][j]);
		}
		printf("\n");
	}
	int visited[numOfStates];
	long long int cost[numOfStates];
	memset(visited,0,sizeof(visited));
	memset(cost,0,sizeof(cost));
	DepthFirstSearch(0,numOfStates,adjMat,val,cost,visited);

	if(flag==1){
		printf("Yes, Doops got duped\n");
	}
	else{
		printf("No negative loops, bro\n");
	}
}
