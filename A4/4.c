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
int main(){
    int n;
    scanf("%d",&n);
    int a[n],b[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n;i++) scanf("%d",&b[i]);
    mergeSort(n,a);
    mergeSort(n,b);
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    printf("\n");
    for(int i=0;i<n;i++) printf("%d ",b[i]);
    int count=0,j=0,max=0,index=0;
    for(int i=0;i<n;i++){
        count++;
        while(a[i]>b[j] && count>=0){
            count--;
            j++;
        }
        if(count>max){
            index = i;
            max = count;
        }
    }
    printf("people are %d at %d\n",max,a[index]);
}
