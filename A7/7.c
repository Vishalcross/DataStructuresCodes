#include<stdio.h>
#include<string.h>
int isMaxHeap(int i, int n, int heap[n]){
    if(2*i + 2 >= n){
        return 1;
    }
    if(heap[i] >= heap[2*i + 1] && heap[i] >= heap[2*i + 2] && isMaxHeap(2*i+1,n,heap) && isMaxHeap(2*i+2,n ,heap)){
        return 1;
    }
    printf("it fails at %d\n",i);
    return 0;
}
int main(){
    int n;
    int rootVal;
    scanf("%d %d",&n,&rootVal);
    int heap[n+1];
    memset(heap,0,sizeof(heap));
    heap[0] = rootVal;
    for(int i=0;i<n;i++){
        int x, y;
        char c;
        scanf("%d %d %c",&x,&y,&c);
        int location;
        for(int i=0;i<2*n;i++){
            if(heap[i] == x){
                location = i;
                break;
            }
        }
        if(c == 'L'){
            heap[2*location + 1] = y;
        }
        else{
            heap[2*location + 2] = y;
        }
    }
    /*int size = 0;
    while(heap[size] != 0){
        size++;
    }*/
    int flag = 0;
    for(int i=0;i<n+1;i++){
        if(heap[i] == 0){
            flag = 1;
            break;
        }
    }
    if(!flag){
        for(int i=0;i<n+1;i++) printf("%d ",heap[i]);
        printf("\n");
        (isMaxHeap(0,n+1,heap)?printf("Yes\n"):printf("No\n"));
    }
    else{
        printf("No\n");
    }
    return 0;
}
