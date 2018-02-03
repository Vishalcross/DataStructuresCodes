#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main(){
    int n;
    scanf("%d",&n);
    int height[n],price[n],cost1=0,cost2=0;
    for(int i=0;i<n;i++) scanf("%d",&height[i]);
    for(int i=0;i<n;i++) scanf("%d",&price[i]);

    double avg=0,sum=0,sum2=0;
    for(int i=0;i<n;i++){
      sum += ((height[i])*(price[i]) );
      sum2 += price[i];
    }
    avg = (double)sum/sum2;
    printf("%lf\n", avg);
    for(int i=0;i<n;i++){
      cost1 += (int) (abs(height[i] - (floor)(avg)) * price[i]);
    }
    for(int i=0;i<n;i++){
      cost2 += (int) (abs(height[i] - (ceil)(avg)) * price[i]);
    }
    printf("%d %d\n",cost1,cost2);
    if(cost1<=cost2) printf("Min cost is %d",cost1);
    else printf("Min cost is %d",cost2);
    return 0;
}
