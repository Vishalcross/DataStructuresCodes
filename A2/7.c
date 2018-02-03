#include<stdio.h>
#include<string.h>
int main(){
    char c='a',plain[10000];
    memset(plain,0,sizeof(plain));
    int k=0;
    while(c != '\n'){
        scanf("%c",&c);
        if(c != ' '){
            plain[k++] = c;
        }
    }
    int key;
    scanf("%d",&key);
    printf("%s",plain);
    k=0;
    int coloumn = strlen(plain)/key;
    char cipher[key][coloumn];
    for(int i=0;i<coloumn;i++){
        for(int j=0;j<key;j++){
            cipher[j][i] = plain[k++];
        }
    }
    for(int i=0;i<key;i++){
        for(int j=0;j<coloumn;j++){
            printf("%c",cipher[i][j]);
        }
        //printf("\n");
    }
    return 0;
}
