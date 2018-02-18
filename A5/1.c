#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int freqSubString(int start,int end,char* array){
	int count=0,temp=0,index=0;
	for(int i=0;i<strlen(array);i++){
		index=start;
		temp=i;
		while(array[index]==array[temp] && temp<strlen(array) && index<=end){
			index++;
			temp++;
		}
		if(index-1==end){
			count++;
		}
	}
	printf("The frequency is:%d and the length is:%d\n",count,end-start+1);
	return count*(end-start+1);
}
int main(){
	char buffer[100],ch='f';
	memset(buffer,0,sizeof(buffer));
	int index=0,start,end,max=-1,temp;
	printf("Enter the string\n");
	while(ch!='\n' || index==0){
		scanf("%c",&ch);
		if(ch!='\n'){
			buffer[index]=ch;
			index++;
		}
	}
	printf("The input string is:\n");
	printf("%s\n",buffer);

	for(int i=0;i<strlen(buffer);i++){
		for(int j=i;j<strlen(buffer);j++){
			start=i;
			end=j;
			printf("The substring is:\n");
			for(int k=start;k<=end;k++){
				printf("%c",buffer[k]);
			}
			printf("\n");
			temp=freqSubString(start,end,buffer);
			if(max<temp){
				max=temp;
			}
		}
	}
	printf("The answer is:%d\n",max);
	return 0;
}
