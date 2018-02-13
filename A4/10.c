#include<stdio.h>
void reverse(int n, int a[]){
    int start=0;
    while(start<n){
        int temp = a[start];
        a[start++] = a[n];
        a[n--] = temp;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int size=n;size>1;size--){
        int max=0,index=0;
        for(int i=0;i<size;i++){
            if(a[i] > max){
                index = i;
                max = a[i];
            }
        }
        //rprintf("index %d\n",a[index]);
        //printf("Reversing 1\n");
        reverse(index,a);
        for(int i=0;i<n;i++) printf("%d ",a[i]);
        //printf("Reversing 2\n");
        reverse(size-1,a);
        //for(int i=0;i<n;i++) printf("%d ",a[i]);
        //printf("\n");
    }
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    return 0;
}
