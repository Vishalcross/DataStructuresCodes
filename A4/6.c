#include<stdio.h>
#include<string.h>
int main(){
    int size=1000;
    char a[size];
    for(int i=0;i<size;i++){
        a[i] = ' ';
    }
    char c = 'a';
    int k = 0;
    while(c != '\n'){
        scanf("%c",&c);
        if(c != '\n') a[k++] = c;
    }
    //char temp[100];
    //memset(temp,0,sizeof(temp));
    int end = size-1,last=0;
    for(int i=0;i<=k;i++){
        if(a[i] == ' '){
            for(int j=i-1;j>=last;j--){
                a[end--] = a[j];
            }
            a[end--] = ' ';
            last=i+1;
        }
    }
    for(int i=end+2;i<size;i++){
        printf("%c",a[i]);
    }
    return 0;
}
