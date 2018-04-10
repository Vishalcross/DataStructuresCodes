#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
	struct Node* prev;
}node;

node* createNode(int data){
	node* temp=(node*)calloc(1,sizeof(node));
	temp->data=data;
	temp->next=NULL;
	temp->prev=NULL;
	return temp;
}
node* createTree(int numOfNodes,int* inOrder,int* postOrder){
	int rootVal=postOrder[numOfNodes-1],flag=0,count=0;
	char ch;
	node* root=createNode(rootVal);
	if(numOfNodes==0){
		return NULL;
	}
	if(numOfNodes==1){
		return root;
	}

	for(int i=0;i<numOfNodes;i++){
		if(flag==1){
			count++;
		}
		if(inOrder[i]==rootVal){
			flag=1;
		}
	}
	int divider=numOfNodes-1-count;//-1 as he last element is root
	printf("The divider is %d and the count is %d\n",divider,count);
	scanf("%c",&ch);
	root->next=createTree(count,inOrder+divider+1,postOrder+divider);//As we need to skip the root we need to add 1 in the inOrder,the size takes care of it in postOrder
	root->prev=createTree(numOfNodes-count-1,inOrder,postOrder);
	return root;
}

void preOrderTraversal(node* root){
	if(root==NULL){
		return ;
	}
	else{
		printf("%d ",root->data);
		preOrderTraversal(root->prev);
		preOrderTraversal(root->next);
	}
}
int main(){
	node* root=NULL;
	int numOfNodes;
	printf("Enter the number of elements\n");
	scanf("%d",&numOfNodes);

	int inOrder[numOfNodes],postOrder[numOfNodes],marked[numOfNodes];
	memset(marked,0,sizeof(marked));

	printf("Enter the data for the inorder traversal\n");
	for(int i=0;i<numOfNodes;i++){
		scanf("%d",&inOrder[i]);
	}

	printf("Enter the data for the postorder traversal\n");
	for(int i=0;i<numOfNodes;i++){
		scanf("%d",&postOrder[i]);
	}

	root=createTree(numOfNodes,inOrder,postOrder);
	preOrderTraversal(root);
	printf("\n");
	return 0;
}
