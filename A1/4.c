#include<stdio.h>
#include<string.h>
int main(){
    char original[1000],temp[100],result[1000];
    memset(result,0,sizeof(result));
    memset(temp,0,sizeof(temp));
    int i=0,j=0,k=0,verdict;
    scanf("%d",&verdict);
    char dump;
    scanf("%c",&dump);
    fgets(original,1000,stdin);
    while(original[i] != '\0'){
        if(original[i] == ' ' || original[i] == '\n'){
            for(j=strlen(temp) - 1;j>=0;j--){
                if(verdict){
                    if(temp[j] == 'x' || temp[j] == 'y' || temp[j] == 'z'){
                        temp[j] = (temp[j] + 3)%122 + 96;
                        result[k++] = temp[j];
                    }
                    else
                        result[k++] = temp[j] + 3;
                }
                else{
                    if(temp[j] == 'a' || temp[j] == 'b' || temp[j] == 'c'){
                        temp[j] = temp[j] + 23;
                        result[k++] = temp[j];
                    }
                    else
                        result[k++] = temp[j] - 3;
                }
            }
            memset(temp,0,sizeof(temp));
            j=0;
            result[k++] = ' ';
        }
        else{
            temp[j++] = original[i];
        }
        i++;
    }
    printf("%s",result);
    return 0;
}
