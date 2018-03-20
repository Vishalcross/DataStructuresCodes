#include<stdio.h>
#include<string.h>
int main(){
    int n;
    scanf("%d",&n);
    int queue[n][2];
    for(int i=0;i<n;i++){
        scanf("%d %d",&queue[i][0],&queue[i][1]);
    }
    //generalise the time by subtratcting the minimum
    int min = 99999;
    for(int i=0;i<n;i++){
        if(queue[i][0] < min) min = queue[i][0];
    }
    for(int i=0;i<n;i++) queue[i][0] -= min;
    printf("minimum arrival time is %d\n",min);
    int timePassed = 0;
    int solved = 0;
    int visited[n];
    memset(visited,0,sizeof(visited));
    int avTime = 0;
    //jo sabse pehle aaye hai use chalu kardo?
    while(solved < n){
        int minPriority = 9999;
        int index = 0;
        for(int i=0;i<n;i++){
            if(queue[i][0] <= timePassed && queue[i][1] < minPriority && visited[i] == 0){
                min = queue[i][1];
                index = i;
            }
        }
        printf("serving customer who arrived at %d, takes %d time. Time passed is %d\n",queue[index][0],queue[index][1],timePassed);
        visited[index] = 1;
        timePassed += queue[index][1];
        avTime += (timePassed - queue[index][0]);
        solved++;
    }
    printf("The time taken is %d\n", avTime/n);
    return 0;
}
