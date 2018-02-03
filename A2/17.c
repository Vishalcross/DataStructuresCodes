#include<stdio.h>
#include<stdlib.h>
#define length 20
typedef struct node{
    int arr[length];
    struct node* next;
}node;
node* head=NULL;
void combinationUtil(int arr[], int data[], int start, int end,
                     int index, int r){

    if (index == r){
        for (int j=0; j<r; j++)
            printf("%d ", data[j]);
        printf("\n");
        node* temp=head;
        node* newNode;
        if(head == NULL){
            head = (node*)malloc(sizeof(node));
            for(int j=0;j<r;j++) head->arr[j] = data[j];
            head->next = NULL;
        }
        else{
            while(temp->next != NULL){
                temp = temp->next;
            }
            newNode = (node*)malloc(sizeof(node));
            for(int j=0;j<r;j++) newNode->arr[j] = data[j];
            temp->next = newNode;
            newNode->next = NULL;
        }

        return;
    }

    for (int i=start; i<=end && end-i+1 >= r-index; i++){
        data[index] = arr[i];
        combinationUtil(arr, data, i+1, end, index+1, r);
    }
}
int main(){
    int n,sum=0,optimal=0;
    scanf("%d",&n);
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }


    for(int i=1;i<=n;i++){
        int data[i],arr[n];
        for(int j=0;j<n;j++){
            arr[j] = j;
        }
        combinationUtil(arr, data, 0, n-1, 0, i);
        node* temp1 = head;
        node* temp2;
        while(temp1!=NULL){
			temp2=head;
			while(temp2!=NULL){
				sum=0;
				/*printf("The elements accessed are:\n");
				printf("Rows selected\n");
				for(int m=0;m<i;m++){
					printf("%d ",temp1->list[m]);
				}
				printf("\n");
				printf("The columns selected\n");
				for(int n=0;n<i;n++){
					printf("%d ",temp2->list[n]);
				}
				printf("\n");*/

				for(int m=0;m<i;m++){
					for(int n=0;n<i;n++){
						sum+=a[temp1->arr[m]][temp2->arr[n]];
						//printf("The sum:%d\n",sum);
					}
				}
				if(sum>optimal){
					optimal=sum;
				}
				temp2=temp2->next;
			}
			temp1=temp1->next;
		}
        head = NULL;
    }
    printf("%d",optimal);
    return 0;
}
