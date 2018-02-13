#include<stdio.h>
#include<string.h>
int main(){
    int n;
    scanf("%d",&n);
    int a[n],b[n],left=0,right=n/2;
    for(int i=0;i<n;i++) {
        int x;
        scanf("%d",&x);
        if(x%2==0){
            a[left++] = x;
        }
        else{
            a[right++] = x;
        }
    }
    /*int k=0;
    for(int i=0;i<2;i++){
        if(i==0){
            for(int j=0;j<n;j++){
                if(a[j]%2==0){
                    b[k++] = a[j];
                }
            }
        }
        else{
            for(int j=0;j<n;j++){
                if(a[j]%2==1){
                    b[k++] = a[j];
                }
            }
        }
    }*/
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    return 0;
}
