#include<stdio.h>
#include<string.h>

int majority(int n, int* a){
    if(n <= 2){
        if(n==1) return a[0];
        else{
            if(a[0] == a[1]) return a[0];
            else return -1;
        }
    }

    int mid = n/2;
    int left = majority(mid,a);
    int right = majority(n-mid,a+mid);
    if(left == right){
        return left;
    }
    else if( (left == -1 && right != -1)){
        int count = 0;
        for(int i=0;i<n;i++){
            if(a[i] == right) count++;
        }
        if(count > mid) return right;
        else return -1;
    }
    else if((left != -1 && right == -1)){
        int count = 0;
        for(int i=0;i<n;i++){
            if(a[i] == left) count++;
        }
        if(count > mid) return left;
        else return -1;
    }
    else{
        return -1;
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    printf("%d ",majority(n,a));
    return 0;
}
