#include<stdio.h>
#include<string.h>

void mergeSort(int n, int* a){
    if(n<=1){
        return;
    }
    int mid = n/2;
    mergeSort(n/2,a);
    mergeSort(n - n/2,a+mid);
    int* l=a;
    int *r = a+mid;
    int temp[n],index=0;
    memset(temp,0,sizeof(temp));
    while(l< a+mid && r<a+n){
        if(*l < *r){
            temp[index++] = *l;
            l++;
        }
        else{
            temp[index++] = *r;
            r++;
        }
    }
    while(l<a+mid && index<n){
        temp[index++] = *l;
        l++;
    }
    while(r<a+n && index<n){
        temp[index++] = *r;
        r++;
    }
    for(int i=0;i<n;i++) a[i] = temp[i];
}
void splitter(int n, int a[n]){
    if(n<=1){
        return;
    }
    int mid = n/2;
    int l[n/2],r[n-n/2];
    memset(l,0,sizeof(l));
    memset(r,0,sizeof(r));
    int index=0;
    for(int i=0;i<n;i+=2){
        l[index++] = a[i];
    }
    index=0;
    for(int i=1;i<n;i+=2){
        r[index++] = a[i];
    }
    for(int i=0;i<mid;i++){
        a[i] = l[i];
    }
    for(int i=mid;i<n;i++){
        a[i] = r[i-mid];
    }
    splitter(mid,l);
    splitter(n-mid,r);
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    mergeSort(n,a);
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    printf("\nafter splitter\n");
    splitter(n,a);
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    return 0;
}
