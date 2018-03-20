#include<stdio.h>
#include<string.h>
int main(){
    int n,m,cost=0;
    scanf("%d %d",&n,&m);
    int i,j,k;
    int a[n][n];//connections
    int data[3][m],odata[3][m];
    memset(a,0,sizeof(a));
    for(i=0;i<m;i++){
        int x,y,temp;
        scanf("%d %d %d",&x,&y,&temp);
        a[x][y] = 1;
        data[0][i] = x;
        odata[0][i] = x;
        data[1][i] = y;
        odata[1][i] = y;
        data[2][i] = temp;
        odata[2][i] = temp;
    }
    int r;
    scanf("%d",&r);
    int necessary[r];
    for(i=0;i<r;i++){
        scanf("%d",&necessary[i]);
    }
    //sorting
    for(i=0;i<m-1;i++){
        for(j=i+1;j<m;j++){
            if(data[2][i] > data[2][j]){
                for(k=0;k<3;k++){
                    int temp= data[k][j];
                    data[k][j] = data[k][i];
                    data[k][i] = temp;
                }
            }
        }
    }
    for(i=0;i<3;i++){
        for(j=0;j<m;j++){
            printf("%d ",data[i][j]);
        }
        printf("\n");
    }
    //add the necessary
    int visited[n],connection[n];
    for(i=0;i<n;i++){
        visited[i] = i;
    }
    for(i=0;i<r;i++){
        int w = necessary[i];
        int x = odata[0][w];
        int y = odata[1][w];
        cost += odata[2][w];
        int t1 = checkParent(x,n,visited);
        int t2 = checkParent(y,n,visited);
        visited[t2] = t1;
    }
    for(i=0;i<n;i++)
    printf("%d ",visited[i]);
    printf("\n");
    for(i=0;i<m;i++){
        int x = data[0][i], y = data[1][i];
        int parentx = checkParent(x,n,visited);
        int parenty = checkParent(y,n,visited);
        printf("%d parentx of %d and %d parenty of %d\n",parentx,x,parenty,y);
        if(parentx != parenty){
            visited[parenty] = parentx;
            cost+= data[2][i];
        }
    }
    for(i=0;i<n;i++) printf("%d ",visited[i]);
    printf("\n%d",cost);
}
int checkParent(int index, int n, int visited[n]){
    while(index != visited[index]){
        index = visited[index];
    }
    return index;
}
