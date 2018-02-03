#include<stdio.h>
int main(){
    int n,x;
    printf("Enter the number of ranges and xth minimum: ");
    scanf("%d %d",&n,&x);
    int ub[n],lb[n],max=0;
    printf("Enter the lower and upper bounds in succession:\n");
    for(int i=0;i<n;i++){
        scanf("%d %d",&lb[i],&ub[i]);
        if(ub[i] > max) max = ub[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(lb[i] > lb[j]){
                int temp = lb[j];
                lb[j] = lb[i];
                lb[i] = temp;
                temp = ub[j];
                ub[j] = ub[i];
                ub[i] = temp;
            }
        }
    }
    int access=0,count=0,currentLb=lb[0],currentUb=ub[0],currNum=lb[0];
    int i=0;
    while(count<x && currNum<max){
        //printf("%d\n",count);
        if(count>x){

            break;
        }

        access=0;
        for(int j=0;j<n;j++){
            if(currNum>=lb[j] && currNum<= ub[j]){
                access++;
            }
        }
        printf("%d is accessed %d times\n",currNum,access);
        count += access;

        if(access == 0){
            int j=0;
            for(j=0;j<n;j++){
                if(currNum < lb[j]){
                    printf("lb of j %d\n",lb[j]);
                    break;
                }
            }
            currNum = lb[j];
        }
        else{
                    currNum++;
        }
    }

    printf("%d",currNum-1);
    return 0;
}
