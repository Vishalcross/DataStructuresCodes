#include<stdio.h>
void selection(int n, int a[n]){
    int count=0;
    for(int i=0;i<n-1;i++){
        int index=i,min = a[i];
        for(int j=i+1;j<n;j++){
            if(a[j]<min){
                index = j;
                min = a[j];
            }
        }
        if(index != i) {
            count++;
            a[index] = a[i];
            a[i] = min;
        }
    }
    //return count;
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    selection(n,a);
    for(int i=0;i<n;i++) printf("%d",a[i]);
    return 0;
}
