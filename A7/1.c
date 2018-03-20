#include<stdio.h>
#include<string.h>
void heapifyUpMin(int index, int n, int* minHeap){
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
void insertMin(int data, int* n, int* minHeap, int index){
    (*n)++;
    minHeap[index] = data;
    heapifyUpMin(index,*n,minHeap);
}
void minHeapify(int *size, int n, int a[n], int minHeap[n]){
    for(int i=0;i<n;i++){
        insertMin(a[i],size,minHeap,i);
    }
}
void heapifyDownMin(int index, int n, int minHeap[n]){
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
        heapifyDownMin(smallest,n,minHeap);
    }
}
int extractMin(int *n, int minHeap[*n]){
    int ans = minHeap[0];
    minHeap[0] = minHeap[(*n)-1];
    minHeap[(*n)-1] = 9999;
    heapifyDownMin(0,*n,minHeap);
    (*n)--;
    return ans;
}
void heapifyUpMax(int index, int n, int* minHeap){
    int parent = index/2;
    int current = index;
    while(current > 0 && minHeap[parent] < minHeap[current]){
        int temp = minHeap[parent];
        minHeap[parent] = minHeap[current];
        minHeap[current] = temp;
        current = parent;
        parent = parent/2;
    }
}
void insertMax(int data, int* n, int* minHeap, int index){
    (*n)++;
    minHeap[index] = data;
    heapifyUpMax(index,*n,minHeap);
}
void maxHeapifyMax(int *size, int n, int a[n], int minHeap[n]){
    for(int i=0;i<n;i++){
        insertMax(a[i],size,minHeap,i);
    }
}
void heapifyDownMax(int index, int n, int minHeap[n]){
    int largest = index;
    int left = 2*index;
    int right = 2*index + 1;
    if(left < n && minHeap[largest] < minHeap[left]){
        largest = left;
    }
    if(right < n && minHeap[largest] < minHeap[right]){
        largest = right;
    }
    if(largest != index){
        int temp = minHeap[largest];
        minHeap[largest] = minHeap[index];
        minHeap[index] = temp;
        heapifyDownMax(largest,n,minHeap);
    }
}
int extractMax(int *n, int minHeap[*n]){
    int ans = minHeap[0];
    minHeap[0] = minHeap[(*n)-1];
    minHeap[(*n)-1] = 0;
    heapifyDownMax(0,*n,minHeap);
    (*n)--;
    return ans;
}
int main(){
    int length;
    scanf("%d",&length);
    int mid = 0;
    int a[3], x;
    int minHeapSize = 0, minHeap[length];
    int maxHeapSize = 0, maxHeap[length];
    memset(minHeap,9999,sizeof(minHeap));
    memset(maxHeap,0,sizeof(maxHeap));
    for(int i=0;i<length;i++){
        scanf("%d",&x);
        float median;
        if(i<3){
            if(i==0){
                a[0] = x;
                median = (float)a[0];
             }
            else if(i==1){
                a[1] = x;
                median = (float)(a[0] + a[1]);
                median /= 2;
            }
            else{
                a[2] = x;
                for(int i=0;i<2;i++){
                    for(int j=i+1;j<3;j++){
                        if(a[i] > a[j]){
                            int temp = a[i];
                            a[i] = a[j];
                            a[j] = temp;
                        }
                    }
                }
                median = (float)a[1];
                insertMax(a[0],&maxHeapSize,maxHeap,maxHeapSize);
                insertMin(a[2],&minHeapSize,minHeap,minHeapSize);
            }
        }
        else{
            if(i%2 == 0){
                a[0] = extractMax(&maxHeapSize,maxHeap);
                a[2] = extractMin(&minHeapSize,minHeap);
                for(int i=0;i<2;i++){
                    for(int j=i+1;j<3;j++){
                        if(a[i] > a[j]){
                            int temp = a[i];
                            a[i] = a[j];
                            a[j] = temp;
                        }
                    }
                }
                median = (float)a[1];
            }
            else{
                if(x < a[1]){
                    insertMax(x,&maxHeapSize,maxHeap,maxHeapSize);
                    insertMin(a[1],&minHeapSize,minHeap,minHeapSize);
                }
                else{
                    insertMin(x,&minHeapSize,minHeap,minHeapSize);
                    insertMax(a[1],&maxHeapSize,maxHeap,maxHeapSize);
                }
                int alpha = extractMax(&maxHeapSize,maxHeap);
                int beta = extractMin(&minHeapSize,minHeap);
                median = (float)(alpha + beta);
                median /= 2;
                a[1] = beta;
            }
        }
        printf("Day %d(%d) median is %.1f\n",i,i+1,median);
    }
}
