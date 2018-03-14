#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
	int i;
	int j;
	struct node* next;
}node;
node *head1 = NULL;
node *head2 = NULL;

//Push elements into the stack
void push(int i, int j){
    node *newNode,*head,*temp;
	newNode = malloc(sizeof(node));
	newNode->i = i;
	newNode->j = j;
	newNode->next = NULL;

	if(head1 == NULL)	head1 = newNode;
	else{
    	temp = head1;
    	newNode->next = temp;
    	head1 = newNode;
    }
}

//Stores elements popped from the stack in a nexted List
void popstore(node* newNode){
	node *temp;
	newNode->next = NULL;
	if(head2 == NULL)	head2 = newNode;
    else{
    	temp = head2;
    	newNode->next = temp;
    	head2 = newNode;
 	}
}

//Checks if i, j have already been popped from the stack
int checkpop(int i, int j){
    node* temp;
	temp = head2;
	if(temp == NULL)
	return 1;
	else{
    	while(temp != NULL){
    		if(((temp->i) == i) && ((temp->j) == j)) return 0;
    		temp = temp->next;
    	}
	}
	return 1;
}

//Pops elements from the stack
node* pop(){
    node *temp;
	temp = head1;
	head1 = head1->next;
	return temp;
}

//Checks if i, j have already been pushed into stack 1
int check(int i, int j){
	node* temp;
	temp = head1;
	if(i == 0 && j == 0)
	   return 0;
	else{
		while(temp!=NULL){
		    if(((temp->i) == i) && ((temp->j) == j)) return 0;
            temp = temp->next;
    	}
	}
	return 1;
}

//Checks the Right, Down, Left, Up conditions and changes value of stack, maze[i][j] and sol[i][j] accordingly
void solveMaze(int n, int maze[n][n], int sol[n][n]){
	int i = 0, j = 0;
	node *temp = (node*)malloc(sizeof(node));
	temp->i = 0;
	temp->j = 0;
	while(i<n && j<n){
		if(head1 == NULL){
            push(i,j);
        }
        else{
		    i = head1->i;
			j = head1->j;

			//Down
            if(maze[i+1][j] != 0 && check((i+1),j) && checkpop((i+1),j) && i<n-1){
				maze[i][j]++;
				sol[i][j]++;
				i++;
				push(i,j);
			}
            //Left
    		else if(maze[i][j-1] != 0 && check(i,(j-1)) && checkpop(i,(j-1))  && j>0){
				maze[i][j]++;
				sol[i][j]++;
				j--;
				push(i,j);
			}
			//Up
	        else if(maze[i-1][j] != 0 && check((i-1),j) && checkpop((i-1),j)  && i>0){
				maze[i][j]++;
				sol[i][j]++;
				i--;
				push(i,j);
			}
            //Right
			else if(maze[i][j+1] != 0 && check(i,(j+1)) && checkpop(i,(j+1)) && j<n-1){
				maze[i][j]++;
				sol[i][j]++;
				j++;
				push(i,j);
			}
			//BackTracking
    		else{
				maze[i][j]++;
				sol[i][j]++;
				popstore(pop());
			}
			if(i == n-1 && j == n-1){
				maze[i][j] = 1;
				sol[i][j] = 1;
				printf("\nSolution path for Maze is:\n--------------------------\n");
				break;
			}
    		if(i == 0 && j == 0){
				printf("\nSolution doesn't exist...");
    			printf("\nPath till reaching a dead end was:\n----------------------------------\n");
				break;
			}
    		temp = head1->next;
    		if(temp == NULL){
				temp = malloc(sizeof(node));
				temp->i=0;
				temp->j=0;
			}
        }
	}
}

//Prints the effective path traversed by mouse in nexted list and matrix form
void printSolution(int n, int maze[n][n], int sol[n][n]){
	node *temp;
	int i = 0, j = 0;
	temp = head1;
	while(temp != NULL){
		printf(" <- (%d,%d) ",(temp->i),(temp->j));
  		temp = temp->next;
	}
	printf("\n");
	printf("\nThe Path traversed:\n");
    for(i=0;i<n;i++){
    	for(j=0;j<n;j++){
			printf(" %d  ",sol[i][j]);
		}
    	printf("\n");
  	}
}

int main(){
    int n;
    scanf("%d",&n);
	int maze[n][n];
    int sol[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) scanf("%d",&maze[i][j]);
    }
	memset(sol,0,sizeof(sol));
    solveMaze(n,maze,sol);
	printSolution(n,maze,sol);
	return 0;
}
