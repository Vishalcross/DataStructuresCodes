#include<stdio.h>
#include<string.h>
void mergeSort(int n, int* a, int mode){
    if(n<=1){
        return;
    }
    int mid = n/2;
    mergeSort(n/2,a,mode);
    mergeSort(n - n/2,a+mid,mode);
    int* l=a;
    int *r = a+mid;
    int temp[n],index=0;
    memset(temp,0,sizeof(temp));
    while(l< a+mid && r<a+n){
        if(mode==1){
            if(*l < *r){
                temp[index++] = *l;
                l++;
            }
            else{
                temp[index++] = *r;
                r++;
            }
        }
        else{
            if(*l > *r){
                temp[index++] = *l;
                l++;
            }
            else{
                temp[index++] = *r;
                r++;
            }
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
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int even[n/2],x=n/2;
    if(n%2!=0){
        x++;
    }

    int odd[x];
    for(int i=0;i<n;i++){
        if(i%2==0){
            odd[i/2] = a[i];
        }
        else{
            even[i/2] = a[i];
        }
    }
    //for(int i=0;i<x;i++) printf("%d ",even[i]);
    /*for(int i=0;i<n;i++){
        if(i%2==0){
            printf("%d ",even[i/2]);
        }
        else{
            printf("%d ",odd[i/2]);
        }
    }*/
    mergeSort(x,even,1);
    mergeSort(n/2,odd,0);
    for(int i=0;i<x;i++){
        printf("%d ",even[i]);
    }
    for(int i=0;i<n/2;i++) printf("%d ",odd[i]);

    return 0;
}
