#include<stdio.h>
#include<string.h>
int main(){
    int n;
    scanf("%d",&n);
    char num[n][100];
    memset(num,0,sizeof(num));
    for(int i=0;i<n;i++) scanf("%s",num[i]);
    //for(int i=0;i<n;i++) printf("%s\n",num[i]);
    char correct[n][100];
    memset(correct,0,sizeof(correct));
    for(int i=0;i<n;i++){
        int j=0;
        for(j=0;j<strlen(num[i]);j++){
            if(num[i][j] != '0'){
                break;
            }
        }
        int l=0;
        for(int k=j;k<strlen(num[i]);k++) correct[i][l++] = num[i][k];
    }
    //for(int i=0;i<n;i++) printf("%s\n",correct[i]);
    memset(num,0,sizeof(num));
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(strlen(correct[i]) > strlen(correct[j]) ){
                printf("Size difference %s is bigger than %s\n",correct[i],correct[j]);
                char temp[100];
                strcpy(temp,correct[i]);
                strcpy(correct[i],correct[j]);
                strcpy(correct[j],temp);
            }
            else if(strlen(correct[i]) == strlen(correct[j]) ){
                if(strcmp(correct[i],correct[j]) > 0){
                    printf("%s is bigger than %s\n",correct[i],correct[j]);
                    char temp[100];
                    strcpy(temp,correct[i]);
                    strcpy(correct[i],correct[j]);
                    strcpy(correct[j],temp);
                }
            }
        }
    }
    for(int i=0;i<n;i++) printf("%s\n",correct[i]);
    return 0;
}
