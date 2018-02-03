#include<stdio.h>
#include<math.h>//satorarepotenetoperarotas
#include<string.h>
int main(){
    int n,i,j,k;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        char a[101];
        memset(a,0,sizeof(a));
        scanf("%s", a);
        int temp = strlen(a);
        int x = (int)sqrt(temp);
        if(x*x != temp){
            printf("No\n");
            continue;
        }
        else{
            int flag = 0;

            //palindrome
            for(j=0;j<temp/2;j++){
                if(a[j] != a[temp - j -1]){
                    printf("No\n");
                    flag=1;
                    break;
                }
            }

            if(!flag){
                int b[x][x],y=0;
                //copy into 2d array
                for(j=0;j<x;j++){
                    for(k=0;k<x;k++){
                        b[j][k] = a[y++];
                    }
                }
                for(j=0;j<x;j++){
                    for(k=0;k<x;k++){
                        printf("%c ",b[j][k]);
                    }
                    printf("\n");
                }
                //diagonal
                for(j=0;j<x/2;j++){
                    if(b[j][j] != b[x-j-1][x-j-1]){
                        flag = 1;
                        printf("No\n");
                        break;
                    }
                }
                    //matrix symmetry
                for(j=1;j<x;j++){
                    for(k=0;k<j;k++){
                        if(b[j][k] != b[k][j]){
                           // printf("No\n");
                            flag = 1;
                            break;
                        }
                    }
                }
                if(!flag) printf("Yes\n");
                else printf("No\n");
            }


        }
    }
    return 0;
}
