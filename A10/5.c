#include<stdio.h>
#include<string.h>
int solved = 0;

int isOkay(int locx, int locy, int n, int chessboard[n][n]){

    for(int i=0;i<n && i!=locy;i++){
        if(chessboard[locx][i] == -1)
            //chessboard[locx][i] += value;
        return 0;
    }
    for(int i=0;i<n && i!=locx;i++){
        if(chessboard[i][locy] == -1)
            //chessboard[i][locy] += value;
        return 0;
    }

    int t1 = locx-1,t2 = locy-1;
    while(t1>=0 && t2>=0){
        if(chessboard[t1][t2] == -1)
            return 0;
        t1--,t2--;
    }
    t1 = locx-1,t2 = locy+1;
    while(t1>=0 && t2<n){
        if(chessboard[t1][t2] == -1)
         return 0;
        t1--,t2++;
    }
    t1 = locx+1,t2 = locy+1;
    while(t1<n && t2<n){
        if(chessboard[t1][t2] == -1)
         return 0;
        t1++,t2++;
    }
    t1 = locx+1,t2 = locy-1;
    while(t1<n && t2>=0){
        if(chessboard[t1][t2] == -1)
         return 0;
        t1++,t2--;
    }
    return 1;
}

void fillPositions(int locx, int locy, int n, int chessboard[n][n], int value){
    for(int i=0;i<n && i!=locy;i++){
        chessboard[locx][i] += value;
    }
    for(int i=0;i<n && i!=locx;i++){
        chessboard[i][locy] += value;
    }

    int t1 = locx-1,t2 = locy-1;
    while(t1>=0 && t2>=0){
        chessboard[t1--][t2--] += value;
    }
    t1 = locx-1,t2 = locy+1;
    while(t1>=0 && t2<n){
        chessboard[t1--][t2++] += value;
    }
    t1 = locx+1,t2 = locy+1;
    while(t1<n && t2<n){
        chessboard[t1++][t2++] += value;
    }
    t1 = locx+1,t2 = locy-1;
    while(t1<n && t2>=0){
        chessboard[t1++][t2--] += value;
    }
}

void solveNQueens(int index, int n, int chessboard[n][n]){
    if(index == n){
        solved = 1;
        printf("A solution is \n");
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                if(chessboard[i][j] == -1) printf("1 ");
            else printf("0 ");
            printf("\n");
        }
        printf("\n");
        return;
    }
    int flag = 0;
    for(int i=0;i<n;i++){
        if(chessboard[i][index] == 0){
            chessboard[i][index] = -1;
            int fl = isOkay(i,index,n,chessboard);
            if(fl == 1){
                flag = 1;
                fillPositions(i,index,n,chessboard,1);
                solveNQueens(index+1,n,chessboard);
                if(solved == 1) return;
                fillPositions(i,index,n,chessboard,-1);
            }
            chessboard[i][index] = 0;
        }
    }
    if(!flag){
        printf("No solution\n");
        return;
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int chessboard[n][n];
    memset(chessboard,0,sizeof(chessboard));
    solveNQueens(0,n,chessboard);
    /*fillPositions(1,2,n,chessboard,-11);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) printf("%d ",chessboard[i][j]);
        printf("\n");
    }*/
}
