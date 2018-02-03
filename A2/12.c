#include<string.h>
#include<stdio.h>
int main(){
    int n,x;
    scanf("%d %d",&n,&x);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    int high = n-1,low = 0,mid=0,count=0,min=99999,max=0,index=0,flag=0;
    /*
    while(low <= high){
        mid = (low+high)/2;
        if(x == a[mid]){
            index = mid;
            break;
        }
        else if(x>a[mid]){
            low = mid+1;
           // mid = (low+high)/2;
        }
        else{
            high = mid-1;
          //  mid = (low+high)/2;
        }
    }
    */
  //  printf("%d ",index);
    low = 0;
    high = n-1;
    //high = index-1;
    while(low<=high){
        mid = (low+high)/2;
        if(x == a[mid]){
                flag=1;
                //printf("JJ\n");
            if(mid < min){
                min = mid;
                high = mid-1;
                //printf("%d %d\n",min,mid);
            }
            else break;
        }
        else if(x>a[mid]){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    low = min+1;
    high = n-1;

    while(low<=high){
        mid = (low+high)/2;
        if(x == a[mid]){
            flag = 1;
            if(mid>max) {max = mid; low = mid+1; }
            else break;
        }
        else if(x>a[mid]){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    if(!flag) printf("no");
    else printf("%d %d %d",min,max,max-min+1);
    return 0;
}
