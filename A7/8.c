#include<stdio.h>
#include<string.h>
void heapifyUp(int index, int n, int* minHeap){
    int parent = index/2;
    int current = index;
    while(current > 0 && minHeap[parent] > minHeap[current]){
        int temp = minHeap[parent];
        minHeap[parent] = minHeap[current];
        minHeap[current] = temp;
        current = parent;
        parent = parent/2;
    }
}
void insert(int data, int* n, int* minHeap, int index){
    (*n)++;
    minHeap[index] = data;
    heapifyUp(index,*n,minHeap);
}
void minHeapify(int *size, int n, int a[n], int minHeap[n]){
    for(int i=0;i<n;i++){
        insert(a[i],size,minHeap,i);
    }
}
void heapifyDown(int index, int n, int minHeap[n]){
    int smallest = index;
    int left = 2*index;
    int right = 2*index + 1;
    if(left < n && minHeap[smallest] > minHeap[left]){
        smallest = left;
    }
    if(right < n && minHeap[smallest] > minHeap[right]){
        smallest = right;
    }
    if(smallest != index){
        int temp = minHeap[smallest];
        minHeap[smallest] = minHeap[index];
        minHeap[index] = temp;
        heapifyDown(smallest,n,minHeap);
    }
}
int extractMin(int *n, int minHeap[*n]){
    int ans = minHeap[0];
    minHeap[0] = minHeap[(*n)-1];
    minHeap[(*n)-1] = 9999;
    heapifyDown(0,*n,minHeap);
    (*n)--;
    return ans;
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n], sum = 0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        sum += a[i];
    }
    int heapSize = 0;
    int minHeap[n];
    memset(minHeap,9999,sizeof(minHeap));
    minHeapify(&heapSize,n,a,minHeap);
    for(int i=0;i<heapSize;i++) printf("%d ",minHeap[i]);
    int length = 0, cost = 0;
    while(heapSize > 1){
        int x = extractMin(&heapSize,minHeap);
        int y = extractMin(&heapSize,minHeap);
        printf("now adding %d %d, the cost currently is %d and length added is %d\n",x,y,cost,x+y);
        length = (x + y);
        cost = cost + length;
        insert(length,&heapSize,minHeap,heapSize);
    }
    printf("Final cost is %d\n",cost);
    return 0;
}
