#include<stdio.h>

int main(){
    int length=6,pos[10][3],temp,k=0;
    for(int i=0;i<length;i++){
        for(int j=0;j<length;j++){
            scanf("%d",&temp);
            if(temp != 0 && k<10){
                pos[k][0] = temp;
                pos[k][1] = i;
                pos[k++][2] = j;
            }
        }
    }
    if(k>=10){
        printf("Not sparse\n");
    }
    else{
        printf("Sparse matrix, has %d non zero elements\nThe sparse representation is\nRow Col Value\n",k);
        for(int i=0;i<k;i++){
            for(int j=2;j>=0;j--) printf("%d ",pos[i][j]);
            printf("\n");
        }
        printf("The transpose is\nRow Col Value\n");
        for(int i=0;i<k;i++){
            printf("%d %d %d\n",pos[i][1],pos[i][2],pos[i][0]);
        }
    }
    return 0;
}
/*
15 0 12 22 0 -15
0 11 3 0 0 0
0 0 0 -6 0 0
0 12 0 10 0 0
0 0 0 0 0 0
0 0 0 0 0 0
*/
