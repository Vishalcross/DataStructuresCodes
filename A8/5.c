/*
5 8
WWWWWWWE
WHMAEEEM
WEWWEWAW
WEDWEEDW
EWWWWWWW
3 3
DMD
MHM
DMD
3 7
WWWWWWW
MHEEDAM
WWWWWWW
4 1
W
H
D
W
1 13
HDWEMDEADWEMD
-1 -1
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>

void findStart(int* r, int* c, int row, int coloumn, char maze[row][coloumn]){
    for(int i=0;i<row;i++){
        for(int j=0;j<coloumn;j++){
            if(maze[i][j] == 'H'){
                *r = i;
                *c = j;
                return;
            }
        }
    }
}

bool inside(int a, int b, int c) {
	return (a <= b && b <= c);
}
/*
int bfs(int r, int c, int R, int C, char maze[R][C]) {
    int dr[] = {0, 0, -1, 1};
    int dc[] = {-1, 1, 0, 0};
    int d[R][C][3];
    memset(d,9999,sizeof(d));
	if(r==R-1 || r==0 || c==0 || c==C-1) return 0;
	int i, rr, cc, fl, now;
	//queue< int > Q;
    int queue[MAX], head = 0, tail= -1;
    memset(queue,0,sizeof(queue));
    queue[++tail] = r;
    queue[++tail] = c;
    queue[++tail] = 0;
	//Q.push(r), Q.push(c), Q.push(0);
	d[r][c][0] = 0;
	while(head <= tail) {
        r = queue[head];
        head++;
		//r = Q.front(); Q.pop();
        c = queue[head];
        head++;
		//c = Q.front(); Q.pop();
		//fl = Q.front(); Q.pop();
        fl = queue[head];
        head++;
		for(i = 0; i < 4; i++) {
			rr = r + dr[i];
			cc = c + dc[i];
			if(inside(0,rr,R-1) && inside(0,cc,C-1) && maze[rr][cc] != 'W') {
				if(fl != 1 && maze[rr][cc]=='M') continue;
				if(rr==0 || rr==R-1 || cc==0 || cc==C-1) return d[r][c][fl] + 1;
				if(maze[rr][cc] == 'M') now = 1;
				else if(maze[rr][cc] == 'A') now = 2;
				else now = fl;
				if(d[rr][cc][now] > d[r][c][fl] + 1) {
                    queue[++tail] = rr;
                    queue[++tail] = cc;
                    queue[++tail] = now;
					//Q.push(rr), Q.push(cc), Q.push(now);
					d[rr][cc][now] = d[r][c][fl] + 1;
				}
			}
		}
	}
	return -2;
}
*/
int bfs(int r, int c, int row, int coloumn, char maze[row][coloumn]){
    int dr[] = {0, 0, -1, 1};
    int dc[] = {-1, 1, 0, 0};
    int d[row][coloumn][3];
    memset(d,9999,sizeof(d));
    if(r == 0 || r == row-1 || c == 0 || c == coloumn-1) return 1;
    int currentRow, currentColoumn, state, fl;
    int queue[100], head = 0, tail = -1;
    memset(queue,0,sizeof(queue));
    queue[++tail] = r;
    queue[++tail] = c;
    queue[++tail] = 0;
    d[r][c][0] = 0;
    while(head <= tail){
        r = queue[head++];
        c = queue[head++];
        fl = queue[head++];
        for(int i=0;i<4;i++){
            currentRow = r + dr[i];
            currentColoumn = c + dc[i];
            if(inside(0,currentRow,row-1) && inside(0,currentColoumn,coloumn-1) && maze[currentRow][currentColoumn] != 'W'){
                if(fl != 1 && maze[currentRow][currentColoumn] == 'M') continue;
                if(currentRow == 0 || currentRow == row-1 || currentColoumn == 0 || currentColoumn == coloumn-1 ) return d[r][c][fl] + 2;
                if(maze[currentRow][currentColoumn] == 'D') state = 1;
                else if(maze[currentRow][currentColoumn] == 'A') state = 2;
                else state = fl;
                if(d[currentRow][currentColoumn][state] > d[r][c][fl] + 1){
                    queue[++tail] = currentRow;
                    queue[++tail] = currentColoumn;
                    queue[++tail] = state;
                    d[currentRow][currentColoumn][state] = d[r][c][fl] + 1;
                }
            }
        }
    }
    return -1;
}

int main() {
    char s1[10] = {"asd"}, s2[10] = {"asd"};
    while(strcmp(s1,"-1") && strcmp(s2,"-1")){
        scanf("%s%s",s1,s2);
        if(strcmp(s1,"-1") && strcmp(s2,"-1")){
            int row = atoi(s1), col = atoi(s2);
            char maze[row][col];
            memset(maze,0,sizeof(maze));
            for(int i=0;i<row;i++) scanf("%s",maze[i]);
            int r, c;
            findStart(&r,&c,row,col,maze);
            printf("%d\n",bfs(r,c,row,col,maze));
        }
    }
	return 0;
}
