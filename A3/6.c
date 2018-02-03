#include<stdio.h>
#include<string.h>
void binarySearch(int x, int n, int a[n], int visited[n]){
    int low = 0;
    int high = n;
    int flag=0,mid,min=99999,max=-99999;
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
    low = 0;
    high = n;

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
    //printf("%d %d\n",min,max);
    if(flag)
    {
        for(int i=min;i<max+1;i++)
        {
            printf("%d ",x);
            visited[i] = 1;
        }
    }
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int x[n],y[m],visited[n];
    memset(visited,0,sizeof(visited));
    for(int i=0;i<n;i++) scanf("%d",&x[i]);
    for(int i=0;i<m;i++) scanf("%d",&y[i]);
    //sorting x
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(x[i] > x[j]){
                int temp = x[j];
                x[j] = x[i];
                x[i] = temp;
            }
        }
    }

    for(int i=0;i<m;i++){
        binarySearch(y[i],n,x,visited);
    }
    for(int i=0;i<n;i++){
        if(!visited[i]) printf("%d ",x[i]);
    }
    return 0;
}
