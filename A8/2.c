#include<stdio.h>
#include<string.h>
int main(){
    int n,length;
    scanf("%d %d",&n,&length);
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) scanf("%d",&a[i][j]);
    }
    int start, end;
    scanf("%d %d",&start,&end);
    int mult[n][n], res[n][n];
    memset(mult,0,sizeof(mult));
    memset(res,0,sizeof(res));
    for(int i=0;i<n;i++) res[i][i] = 1;
    for(int l=0;l<length;l++){
        memset(mult,0,sizeof(mult));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    mult[i][j] += ((res[i][k]) * (a[k][j]) );
                }
            }
        }
        /*for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) printf("%d ",mult[i][j]);
            printf("\n");
        }*/
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) res[i][j] = mult[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) printf("%d ",res[i][j]);
        printf("\n");
    }
    printf("The number of paths between %d %d is %d\n",start,end,res[start][end]);
    return 0;
}
