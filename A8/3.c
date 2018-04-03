#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define INFINTE 9999
int main(){
    int n;
    scanf("%d",&n);
    int a[n][n];
    //memset(a,INFINTE,sizeof(a));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            //int x, y, z;
            scanf("%d",&a[i][j]);
            //a[i][j] = -1*(a[i][j]);
            //a[x][y] = z;
            //a[y][x] = z;
        }
    }
    int start, end;
    scanf("%d %d",&start,&end);
    int visited[n];
    int length[n];
    memset(length,INFINTE,sizeof(length));
    memset(visited,0,sizeof(visited));
    //int i = 0;
    length[start] = 0;
    while(visited[end] == 0){
        int min = INFINTE, index;
        for(int i=0;i<n;i++){
            if(visited[i] == 0 && length[i] < min){
                index = i;
                min = length[i];
            }
        }
        visited[index] = 1;
        for(int i=0;i<n;i++){
            if(visited[i] == 0){
                if( (length[index] + a[index][i]) < length[i]){
                    length[i] = (length[index] + a[index][i]);
                }
            }
        }
    }
    printf("The set S is the visited matrix\n");
    for(int i=0;i<n;i++) printf("%d ",visited[i]);
    printf("\nThe length matrix is\n");
    for(int i=0;i<n;i++) printf("%d ",length[i]);
    printf("\n");
    return 0;
}
