#include<stdio.h>
int main(){
    int n,prev = -9999,flag=0,curr,x;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&curr);
        printf("%d %d\n",prev,curr);
        if(prev > curr){
            if(flag == 1){
                printf("%d %d are wrongly sorted",x,curr);
            }
            else {
                flag = 1;
                x = prev;
                printf("Anomaly");
            }
        }
        prev = curr;
    }
    return 0;
}
