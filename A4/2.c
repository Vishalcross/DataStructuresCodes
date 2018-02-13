#include<stdio.h>
#include<string.h>
int binarysearch(int index, int n, int num, int x, int a[n]){
    int high = n-1,low = 0,mid,flag=0;
    while(low<high){
        mid = (low+high)/2;
        printf("%d %d %d\n",low,mid,high);
        if(a[mid] + num == x && mid != index){
            printf("%d has %d and %d has %d, so they add up to %d\n",index,num,mid,a[mid],x);
            flag = 1;
            break;
        }
        else if((a[mid] + num) < x){
            high = mid;
        }
        else{
            low = mid;
        }
    }
    return flag;
}
int main(){
    int n,x;
    scanf("%d %d",&n,&x);
    int a[n],flag=0;
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i] > a[j]){
                int x = a[i];
                a[i] = a[j];
                a[j] = x;
            }
        }
    }
    //for(int i=0;i<n;i++) printf("%d ",a[i]);
    for(int i=0;i<n;i++){
        int temp = a[i];
        int b[n-1];
        memset(b,0,sizeof(b));
        int k = 0;
        for(int j=0;j<n;j++){
            if(j!=i) b[k++] = a[j];
        }
    //    printf("Passing\n");
        //for(int i=0;i<n-1;i++) printf("%d ",b[i]);
        //printf("\n");
        flag = binarysearch(i,n-1,temp,x,b);
        if(flag) break;
    }
    flag==0?printf("No\n"):printf("Yes\n");
    return 0;
}
