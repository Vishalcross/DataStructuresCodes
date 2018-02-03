#include<stdio.h>
int main(){
    int states,teamSize;
    scanf("%d %d",&states,&teamSize);
    int pop[states],sum=0;
    for(int i=0;i<states;i++){
        scanf("%d", &pop[i]);
        sum+=pop[i];
    }
    int ub = sum,lb=0,mid;
    while(lb<ub){
        int temp=0;
        mid = (ub+lb)/2;
        printf("%d %d %d\n",lb,mid,ub);
        for(int i=0;i<states;i++){
            if(pop[i]>mid){
                temp+=mid;
            }
            else{
                temp+=pop[i];
            }
        }
        if(temp>=mid*teamSize){
            lb = mid;
        }
        else{
            ub = mid-1;
        }
    }
    printf("%d",lb);
    return 0;
}
