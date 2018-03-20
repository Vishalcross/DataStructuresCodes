#include<stdio.h>
#include<string.h>
int main(){
    int n,rootVal;
    scanf("%d %d",&n,&rootVal);
    int adj[n+1][n+1];
    memset(adj,0,sizeof(adj));
    for(int i=0;i<n;i++){
        int x, y;
        char c;
        scanf("%d %d %c",&x,&y,&c);
        adj[y][x] = (c == 'L'?1:2);
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++) printf("%d ",adj[i][j]);
        printf("\n");
    }
    int heap[n+1];
    heap[0] = rootVal;
    int size = 1;
    for(int i=0;i<n;i++){
        
    }
    return 0;
}
