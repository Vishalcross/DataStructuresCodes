#include<stdio.h>
#include<string.h>
int main(){
    int rows,cols;
    scanf("%d %d",&rows,&cols);
    int a[rows][cols];
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int mid = cols/2,max=0,index=0;
    while(mid>=0 || mid<cols){
        max=0;
        index=0;
        for(int i=0;i<rows;i++){
            if(a[i][mid] > max) {
                max = a[i][mid];
                index = i;
            }
        }
        if(mid == 0 || mid == cols - 1){
            printf("Peak is %d\n",max);
            break;
        }
        if(a[index][mid] >= a[index][mid+1] && a[index][mid] >= a[index][mid-1]){
            printf("Peak is %d\n",max);
            break;
        }
        if(a[index][mid+1] >= a[index][mid]){
            mid = mid + mid/2;
        }
        else{
            mid = mid - mid/2;
        }
    }
    return 0;
}
