#include<stdio.h>
void mergesort(int n, int* a, int* count){
    if(n <= 1) return;
    int mid = n/2;
    mergesort(mid,a,count);
    mergesort(n - mid,a + mid,count);
    int temp[n];
    int* l = a;
    int* r = a +mid;
    int index=0;
    while(l < a + mid && r < a + n){
        if(*l < *r){
            temp[index++] = *l;
            l++;
        }
        else{
            (*count) = (*count) + (a + mid - l);
            temp[index++] = *r;
            r++;
        }
    }
    while(l < a+mid){
        temp[index++] = *l;
        l++;
    }
    while(r < a+n){
        temp[index++] = *r;
        r++;
    }
    for(int i=0;i<n;i++) a[i] = temp[i];
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int count = 0;
    mergesort(n,a,&count);
    printf("Count is %d\n",count);
    return 0;
}
