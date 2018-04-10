#include<stdio.h>
#include<string.h>
int main(){
    int n;
    scanf("%d",&n);
    char s[n+1];
    int a[26];
    memset(a,0,sizeof(a));
    scanf("%s",s);
    int res[n];
    int indices[26][n];
    int length[26];
    memset(indices,0,sizeof(indices));
    memset(length,0,sizeof(length));
    for(int i=0;i<n;i++){
        indices[s[i] - 'a'][length[s[i] - 'a']] = i;
        length[s[i] - 'a']++;
    }
    for(int i=0;i<26;i++){
        printf("%c ",(char)(i + 'a') );
        for(int j=0;j<length[i];j++){
            printf("%d ",indices[i][j]);
        }
        printf("\n");
    }
    int odd = 0;
    for(int i=0;i<26;i++){
        if(length[i]%2 == 1) odd++;
    }
    if((n%2 == 0 && odd > 0) || (n%2 == 1 && odd > 1)){
        printf("Impossible\n");
    }
    else{
        int result[n];
        memset(result,0,sizeof(result));
        int leftIndex = 0, rightIndex = n-1;
        for(int i=0;i<26;i++){
            //printf("Entering %c with frequency %d\n",i+'a',length[i]);
            if(length[i] != 0){
                //printf("He\n");
                if(length[i] % 2 == 1){
                    result[n/2] = indices[i][0];
                    for(int j=1;j<length[i];i++){
                        if(j%2 == 0){
                            result[leftIndex++] = indices[i][j];
                        }
                        else{
                            result[rightIndex--] = indices[i][j];
                        }
                    }
                }
                else{

                    for(int j=0;j<length[i];j++){
                        if(j%2 == 0){
                            result[leftIndex++] = indices[i][j];
                        }
                        else{

                            result[rightIndex--] = indices[i][j];
                        }
                    }
                }
            }
        }

        for(int i=0;i<n;i++) printf("%d ",result[i]);
    }
    return 0;
}
