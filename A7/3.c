#include<stdio.h>
#include<string.h>
#include<stdlib.h>
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
    int lanes, cars;
    scanf("%d %d",&lanes,&cars);
    int traffic[lanes][cars];
    for(int i=0;i<lanes;i++){
        for(int j=0;j<cars;j++){
            scanf("%d",&traffic[i][j]);
        }
    }
    int a[lanes];
    for(int i=0;i<lanes;i++){
        a[i] = traffic[i][0];
    }
    int minHeap[lanes];
    memset(minHeap,9999,sizeof(minHeap));
    int heapSize = 0;
    minHeapify(&heapSize,lanes,a,minHeap);
    int answer[lanes*cars];
    memset(answer,0,sizeof(answer));
    int k = 0;
    for(int i=0;i<(cars)*(lanes);i++){
        answer[k] = extractMin(&heapSize,minHeap);
        int x = answer[k];
        k++;
        int index;
        for(int i=0;i<lanes;i++){
            if(traffic[i][0] == x){
                index = i;
                break;
            }
        }
        for(int i=0;i<cars-1;i++){
            traffic[index][i] = traffic[index][i+1];
        }
        traffic[index][cars-1] = 9999;
        if(traffic[index][0] != 9999)
            insert(traffic[index][0],&heapSize,minHeap,heapSize);
        
    }
    for(int i=0;i<cars*lanes;i++) printf("%d ",answer[i]);
    return 0;
}
