#include<stdio.h>
int checkParent(int i, int n, int* parent){
    while(parent[i] != i){
        i = parent[i];
    }
    return i;
}
void mergeSort(int n, int* a){
    if(n<=1) return;
    int mid = n/2;
    mergeSort(mid,a);
    mergeSort(n-mid,a+mid);
    int* l = a;
    int* r = a + mid;
    int temp[n], index = 0;
    while(l < a + mid && r < a + n){
        if(*l <= *r){
            temp[index++] = *l;
            l++;
        }
        else{
            temp[index++] = *r;
            r++;
        }
    }
    while(l < a+mid){
        temp[index++] = *l;
        l++;
    }
    while(r < a + n){
        temp[index++] = *r;
        r++;
    }
    for(int i=0;i<n;i++) a[i] = temp[i];
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int parent[n];
    for(int i=0;i<n;i++) parent[i] = i;
    for(int i=0;i<m;i++){
        int x, y;
        scanf("%d %d",&x,&y);
        x--;
        y--;
        if(parent[y] == y) parent[y] = checkParent(x,n,parent);
        else{
            parent[x] = checkParent(y,n,parent);
        }
    }
    //for(int i=0;i<n;i++) printf("%d ",parent[i]);
//    mergeSort(n,parent);
    for(int i=0;i<n;i++) printf("%d ",parent[i]);
    printf("\n");
    int count = 0;
    for(int i=0;i<n;i++){
        while( i<n-1 && parent[i] == parent[i+1]) i++;
        count++;
    }
    printf("Connected components are %d\n",count);
    return 0;
}
