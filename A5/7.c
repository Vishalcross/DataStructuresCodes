#include<stdio.h>
#include<string.h>
int main(){
    int n;
    scanf("%d",&n);
    int entryTime[n],exitTime[n];
    int max = -999,min = 9999;
    for(int i=0;i<n;i++){
        scanf("%d %d",&entryTime[i],&exitTime[i]);
        if(exitTime[i] > max){
            max = exitTime[i];
        }
        if(entryTime[i] < min){
            min = entryTime[i];
        }
    }
    int visited[n];
    memset(visited,0,sizeof(visited));
    for(int t=min;t<=max;t++){
        for(int i=0;i<n;i++){
            if(entryTime[i] <= t && exitTime[i] >= t && visited[i] == 0){
                visited[i] = t;
                break;
            }
        }
    }
    for(int i=0;i<n;i++) printf("%d ",visited[i]);
    return 0;
}
