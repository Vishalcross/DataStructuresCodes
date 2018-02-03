#include<stdio.h>
#include<string.h>

int main(){
    long long int n;
    int sum=0;
    scanf("%lld",&n);
    int control =  n%10;
    n/=10;

    long long int temp = n;
    int digits=0;
    while(temp){
        digits++;
        temp/=10;
    }
    printf("%d\n",digits);
    int a[digits];
    temp=0;
    memset(a,0,sizeof(a));
    while(n){
        a[temp++] = n%10;
        n/=10;
    }
    for(int i=0;i<digits;i++) {
       if(i%2==0) printf("%d ",a[i]);
    }
    for(int i=0;i<digits;i++){
        temp = a[i];
        if(i%2 == 0){
            temp *=2;
            if( temp < 9){
                sum += temp;
            }
            else{
                sum += (temp%10);
                temp/=10;
                sum += (temp%10);
            }
        }
        else{
            sum+=temp;
        }
    }
    printf("\n%d\n",sum);
    if((sum+control)%10 == 0) printf("Yes");
    else printf("No");
    return 0;
}

