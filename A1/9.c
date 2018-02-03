#include<stdio.h>
#include<string.h>
int main(){
    int m,p,n,i,j,k;
    scanf("%d %d",&m,&p);
    int a[m][p];
    for(i=0;i<m;i++){
        for(j=0;j<p;j++){
            scanf("%d",&a[i][j]);
        }
    }
    scanf("%d %d",&p,&n);
    int b[p][n];
    for(i=0;i<p;i++){
        for(j=0;j<n;j++){
            scanf("%d",&b[i][j]);
        }
    }
    int sum=0;
    //brute
    /*for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            for(k=0;k<p;k++){
                sum += a[i][k] * b[k][j];
            }
        }
    }*/
    //smart
    int mult[p];
    memset(mult,0,sizeof(mult));
    for(i=0;i<p;i++){
        for(j=0;j<n;j++) mult[i] += b[i][j];
    }
    for(i=0;i<m;i++){
        for(j=0;j<p;j++) sum += a[i][j] * mult[j];
    }
    printf("%d",sum);
}
