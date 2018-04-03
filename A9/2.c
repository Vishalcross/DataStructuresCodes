#include<stdio.h>
#include<string.h>
void printPermutations(int frequency[26], int* index, int size, char fill[size]){
    if(*index == size){
        for(int i=0;i<size;i++) printf("%c",fill[i]);
        printf("\n");
        return;
    }
    for(int i=0;i<26;i++){
        if(frequency[i] != 0){
            frequency[i]--;
            fill[(*index)++] = i + 'a';
            printPermutations(frequency,index,size,fill);
            (*index)--;
            frequency[i]++;
        }
    }
}
int main(){
    int frequency[26];
    memset(frequency,0,sizeof(frequency));
    char c = 'a';
    int size = 0, index = 0;
    while(c != '\n'){
        scanf("%c",&c);
        if(c != '\n'){
            frequency[c - 'a']++;
            size++;
        }
    }
    char fill[size];
    memset(fill,0,sizeof(fill));
    printPermutations(frequency,&index,size,fill);
    return 0;
}
