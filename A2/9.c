#include<stdio.h>
#include<math.h>

int main(){
    long long int n,count=0;
    scanf("%lld",&n);
    int temp,temp2,b=1;

    while(n>0){
        temp = n%10;
        if(temp == 0){
            count += 3*b;
            b*=3;
            n-=10;
        }
        else{
            temp2 = (n/10)%10;
            if(temp2 == 0 && n/10 != 0){
                n/=100;
                n*=100;
                n+=99;
                n-=100;
            }
            temp = n%10;
            if(temp < 7){
                count += b;
                b*=3;
            }
            else if(temp == 7 || temp == 8){
                count += 2*b;
                b*=3;
            }
            else if(temp == 9){
                count += 3*b;
                b*=3;
            }
        }
        n/=10;
    }

    printf("%lld",count);
    return 0;
}
