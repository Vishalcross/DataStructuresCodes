/*This question is a modification of the popular SPOJ AGGRCOWS, which makes use of the guess the answer approach. In this approach, we
try to guess the answer with the help of binary search. For instance, if the number of friends is too high, we need to have more racks,
on the other hand if the opposite occurs, we can find a better solution to the problem.
@author
Vishal Chokala
*/
#include<stdio.h>

int main(){
    int n,f;
    scanf("%d %d",&n,&f);
    int cabinet[n];
    for(int i=0;i<n;i++) scanf("%d",&cabinet[i]);
    int sum[n];
    sum[0] = cabinet[0];
    for(int i=1;i<n;i++){
        sum[i] = cabinet[i] + sum[i-1];
    }
    //for(int i=0;i<n;i++) printf("%d ",sum[i]);
    int low=sum[0],high=sum[n-1],mid,min=999999,i=0,lastval=0;
    while(low<=high){
        printf("%d %d %d\n",low,mid,high);
        mid = (low + high)/2;
        int temp = 0,count=0;
        for(int i=0;i<n;i++){
            if(sum[i] - temp > mid && f-1>count){
                temp = sum[i-1];
                i--;
                count++;
            }
            else if(f-1==count){
                if(sum[n-1]-temp>mid){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
            else if(i==n-1 && count<f-1){
                high=mid-1;
            }
        }
    }
    printf("%d",mid+1);
    return 0;
}
