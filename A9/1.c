#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LIM 10000
void insertIntoTable(int* hashTable, int data, int* empty){
    for(int i=0;i<LIM;i++){
        long long int temp = (data + i*i);
        temp%=10;
        long long int index = temp;
        if(!empty[index]){
            empty[index] = 1;
            hashTable[index] = data;
            return;
        }
    }
    printf("Tatti\n");
}

void printTable(int* hashTable){
    for(int i=0;i<10;i++){
        printf("%d\n",hashTable[i]);
    }
}

int main(){
    int hashTable[10];
    int empty[10];
    memset(empty,0,sizeof(empty));
    int input[] = {71, 23, 73, 99, 44, 19, 49, 93, 81, 39};
    for(int i=0;i<10;i++){
        insertIntoTable(hashTable,input[i],empty);
    }
    printTable(hashTable);
    return 0;
}
