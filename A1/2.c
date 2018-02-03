#include<stdio.h>
#include<string.h>

int main(){
    int i,j,k,count=0;
    char word[100];
    char sentence[100];
    scanf("%s",word);
    //    memset(sentence,'{',sizeof(sentence));
    //fgets(sentence,100,stdin);
    k=0;
    char dump;
    scanf("%c",&dump);
    char temp[100],x='a';
    memset(temp,0,sizeof(temp));
    while(x != '\n'){
        scanf("%c",&x);
        if(x == ' ' || x == '\n'){
            k=0;
            //printf("%s",temp);
            if((int)temp[0]!=0){
                if(strcmp(temp,word) == 0) count++;
            }
                            memset(temp,0,sizeof(temp));
        }
        else{
            temp[k] = x;
            k++;
        }
    }
    printf("%d",count);
    return 0;
}
