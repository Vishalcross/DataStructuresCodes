#include<stdio.h>
#include<string.h>
int main(){
    int n;
    scanf("%d",&n);
    int x,i;
    int sum[100000];
    memset(sum,0,sizeof(sum));
    // Initialize sum
    sum[0] = 1;
    int sumsize = 1;

    // Multiplying sequentially
  /*  for (x=2; x<=n; x++){
        int carry = 0;  // Initialize carry

    // One by one multiply n with individual digits of sum[]
        for (i=0; i<sumsize; i++){
            int temp = sum[i] * x + carry;
            sum[i] = temp % 10;  // Store last digit of 'temp' in sum[]
            carry  = temp/10;    // Put rest in carry
        }
    // Put carry in sum and increase sumsize
       // printf("%d\n",carry);
        while (carry){
            sum[sumsize] = carry%10;
            carry = carry/10;
            sumsize++;
        }
    }*/

    for(x=2;x<=n;x++){
        int carry=0;
        for(i=0;i<sumsize;i++){
            int temp = (x*sum[i]) + carry;
            sum[i] = temp%10;
            carry = temp/10;
        }
        while(carry>0){
            sum[sumsize] = carry%10;
            carry /= 10;
            sumsize++;
        }
    }

    for (i=sumsize-1; i>=0; i--) printf("%d",sum[i]);
    return 0;
}
