#include<stdio.h>
#include<string.h>
int main(){
    char sentence[1000];
    fgets(sentence,1000,stdin);
    int i=0,j=0;
    char word[100];
    fgets(word,100,stdin);
    while(sentence[i] != '\0'){
        if(sentence[i] == word[j]){
            j++;
        }
        i++;
    }
    //printf("%s",word);
    if(j == strlen(word)){
        printf("Yes");
    }
    else printf("No");
    return 0;
}
