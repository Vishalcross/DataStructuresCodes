#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAX 1000000
#define LIM 10000
int primes[MAX];
long long int segSieve[LIM][LIM];
long long int score[LIM];
long long int divCeil(long long int a, long long int b){
    return (a+b-1)/b;
}
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
void sieve(int size, long long int lower, long long int upper,int lengths[size]){
    printf("Bye\n");
    printf("Tatti\n");
    memset(primes,0,sizeof(primes));
    for(int i=2;i<MAX;i++){
        if(primes[i]==0){
            for(int j=2*i;j<MAX;j+=i){
                 primes[j]++;
            }
            for(long long int x=divCeil(lower,i)*i;x<=upper;x+=i){
                //if(x < lower) continue;

                segSieve[x-lower][lengths[x-lower]]=i;
                lengths[x-lower]++;
                //printf("x %lld x-lower %lld length[x-lower] %d\n",x,x-lower,lengths[x-lower]);
            }
        }
    }
    /*for(int i=0;i<size;i++){
        for(int j=0;j<lengths[i];j++) printf("%lld ",segSieve[i][j]);
        printf("\n");
    }*/
}

void insertToHeap(int maxHeap[],int* size,int data){
    maxHeap[*size]=data;
    (*size)++;
    int pos=*size,temp;
    while(pos>=0){
        if(maxHeap[pos] > maxHeap[(pos-1)/2]){
            temp=maxHeap[pos];
            maxHeap[pos] = maxHeap[(pos-1)/2];
            maxHeap[(pos-1)/2] = temp;
            pos = (pos-1)/2;
        }
        else{
            break;
        }
    }
    //printf("Insertion is successful\n");
}


int extractMax(int maxHeap[], int* heapSize){
    int ans = maxHeap[0];
    maxHeap[0] = maxHeap[(*heapSize)-1];
    (*heapSize)--;
    int pos = 0;
    while(pos<*heapSize){
        if(2*pos + 2 < *heapSize){
            if(maxHeap[2*pos + 2] > maxHeap[2*pos + 1]){
                if(maxHeap[2*pos + 2] > maxHeap[pos]){
                    int temp = maxHeap[2*pos + 2];
                    maxHeap[2*pos + 2] = maxHeap[pos];
                    maxHeap[pos] = temp;
                    pos=2*pos+2;
                }
                else{
                    break;
                }
            }
            else{
                if(maxHeap[2*pos + 1] > maxHeap[pos]){
                    int temp = maxHeap[2*pos + 1];
                    maxHeap[2*pos + 1] = maxHeap[pos];
                    maxHeap[pos] = temp;
                    pos=2*pos+1;
                }
                else{
                    break;
                }
            }
        }
        else if(2*pos + 1 < *heapSize){
            if(maxHeap[2*pos + 1] > maxHeap[pos]){
                int temp = maxHeap[2*pos + 1];
                maxHeap[2*pos + 1] = maxHeap[pos];
                maxHeap[pos] = temp;
                break;
            }
            else{
                break;
            }
        }
        else{
            break;
        }
    }
    return ans;
}
int main(){
    long long int lower,upper,totalCount=0;
    printf("Enter the lower and the upper bound\n");
    scanf("%lld %lld",&lower,&upper);
    int size = upper - lower + 1;

    int lengths[size];
    memset(lengths,0,sizeof(lengths));
    sieve(size,lower,upper,lengths);
    printf("Hela\n");

    //printf("The lengths are:\n");
    //for(long long int i=lower;i<=upper;i++){
        //printf("%d\n",lengths[i-lower]);
    //}
    //printf("Hi\n");
     long long int temp;
    for(long long int i=lower;i<=upper;i++){
        score[i-lower] = 0;
        int maxHeap[LIM];
        memset(maxHeap,0,sizeof(maxHeap));
        int heapSize=0;
        //printf("The length is %d\n",lengths[i-lower]);
        temp = i;
        for(long long int j = 0;j<lengths[i-lower];j++){
            int count = 0;
            while(temp%segSieve[i-lower][j] == 0){
                temp /= segSieve[i-lower][j];
                count++;
            }
            //insertToHeap(maxHeap,&heapSize,count);
            maxHeap[heapSize++] = count;
            //printf("Printing after insertion\n");
            //for(int m=0;m<heapSize;m++) printf("%d ",maxHeap[m]);
            //printf("\n");
        }

        //if(temp != 1) insertToHeap(maxHeap,&heapSize,1);
        if(temp != 1) maxHeap[heapSize++] = 1;
        qsort(maxHeap,heapSize,sizeof(int),cmpfunc);
        while(heapSize>0){
            //printf("The max heap now contains\n");
            long long int gandu=1;
            for(int j=0;j<heapSize;j++){
                //printf("Heap Value:%d ",maxHeap[j]);
                gandu *= (maxHeap[j] + 1);
            }
            if(gandu!=1)
                score[i-lower]+=gandu;
            //printf("The score is:%lld\n",score[i-lower]);
            int temp = maxHeap[heapSize-1];
            //int temp = extractMax(maxHeap,&heapSize);
            if(temp == 0) heapSize--;
            //printf("The max value is%d\n",temp);
            if(temp != 0){
                temp--;
                maxHeap[heapSize-1] = temp;
                //insertToHeap(maxHeap,&heapSize,temp);
            }
            qsort(maxHeap,heapSize,sizeof(int),cmpfunc);
        }

    }
    for(int i=0;i<size;i++) totalCount+=score[i];

    printf("The fucking val is %lld",totalCount);
    return 0;
}
