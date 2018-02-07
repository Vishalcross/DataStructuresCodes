#include<stdio.h>
void mergeSort(int n, int *a, int* count){
    if(n<=1) return;
    int mid = n/2;
    //splitting
    mergeSort(mid,a,count);
    mergeSort(n-mid,a+mid,count);
    //merging
    int* l = a;
    int* r = a+mid;
    int temp[n],index=0;
    while(l<a+mid && r<a+n){
        if(*l < *r){
            temp[index++] = *l;
            l++;
        }
        else{
            int* x = l;
            while(x<a+mid){
                printf("%d %d is inversion\n",*x,*r);
                (*count)++;
                x++;
            }
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
    printf("Enter the array size: ");
    int n;
    scanf("%d",&n);
    int a[n],count=0;
    printf("Enter the data of the array: ");
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    mergeSort(n,a,&count);
    printf("The sorted array is: ");
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    printf("\ncount = %d",count);
    return 0;
}
