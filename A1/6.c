#include<stdio.h>
#include<math.h>
int main(){
    int c,n,p,i;
    scanf("%d %d %d",&c,&n,&p);
    int answer=1;
    for(i=0;i<n;i++){
        answer = ((answer%p)*(c%p))%p;
    }
    printf("%d",answer);
    return 0;
}
