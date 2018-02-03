#include<stdio.h>
#include<string.h>
int main(){
    int a[8][8];
    memset(a,0,sizeof(a));
    int i,j;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("\n");
  /*  for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }*/

    int flag = 0, flag2=0,index=0,index2=0;
    //scan for 1s

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(a[i][j] == 1){
                //horizontal
                for(int k=0;k<8;k++){
                    if(a[i][k] == 1 && k!= j){
                        flag = 1;
                        index = i;
                        index2 = k;
                        printf("Horizontal Anomaly at %d %d & %d %d",i,j,i,k);
                        break;
                    }
                }
                if(flag) break;
                //vertical
                for(int k=0;k<8;k++){
                    if(a[k][j] == 1 && k!= i){
                        flag = 1;
                        index = k;
                        index2 = j;
                        printf("Vertical Anomaly at %d %d & %d %d",i,j,k,j);
                        break;
                    }
                }
                if(flag) break;
                //diagonal primary down
                index = i;
                index2 = j;
                while((index >= 0) && (index2>=0) && (index<8) && (index2<8)){
                    if(a[index][index2] == 1 && index != i && index2 != j){
                        flag = 1;
                        printf("Diagonal primary down Anomaly at %d %d & %d %d",i,j,index,index2);
                        break;
                    }
                    index2++;
                    index++;
                }
                if(flag) break;
                //diagonal primary up
                index = i;
                index2 = j;
                while((index >= 0) && (index2>=0) && (index<8) && (index2<8)){
                    if(a[index][index2] == 1 && index != i && index2 != j){
                        flag = 1;
                        printf("Diagonal primary up Anomaly at %d %d & %d %d",i,j,index,index2);
                        break;
                    }
                    index2--;
                    index--;
                }
                if(flag) break;
                //diagonal secondary up
                index = i;
                index2 = j;
                while((index >= 0) && (index2>=0) && (index<8) && (index2<8)){
                    if(a[index][index2] == 1 && index != i && index2 != j){
                        flag = 1;
                        printf("Diagonal secondary up Anomaly at %d %d & %d %d",i,j,index,index2);
                        break;
                    }
                    index2++;
                    index--;
                }
                if(flag) break;
                //diagonal secondary down
                index = i;
                index2 = j;
                while((index >= 0) && (index2>=0) && (index<8) && (index2<8)){
                    if(a[index][index2] == 1 && index != i && index2 != j){
                        flag = 1;
                        printf("Diagonal secondary down Anomaly at %d %d & %d %d",i,j,index,index2);
                        break;
                    }
                    index2--;
                    index++;
                }
                if(flag) break;
            }
            if(flag) break;
        }
        if(flag) break;
    }



    if(flag) printf("\nNo\n");
    else printf("\nYes\n");
    return 0;
}
/*
0 0 0 0 0 0 0 1
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 1 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
*/
