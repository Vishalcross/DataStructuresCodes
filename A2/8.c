#include<stdio.h>
#include<math.h>
int main(){
    long long int n;
    int count=0;
    scanf("%lld",&n);
    int temp = (int) sqrt(n);
    for(long long int i=2;i<=n;i++){
        if(n%i == 0 && n!= 0){
            while(n%i == 0) {
                printf("%d*",i);
                n/=i;
                count++;
            }
        }
    }
   /* if(temp*temp != n)
        printf("%d",count+1);*/
     printf("\n%d",count);
    return 0;
}
