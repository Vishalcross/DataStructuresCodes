#include<stdio.h>
#include<string.h>
int main(){
    char c = 'a';
    int a[10000],size=0;
    memset(a,0,sizeof(a));
    while(c != '\n'){
        scanf("%c",&c);
        if(c>='0' && c<='9'){
            if(size == 0 && c == '0'){}
            else a[size++] = c - '0';
        }
    }
    int flag = 0;
    for(int i=0;i<size;i++){
        if(a[i] != a[size-1-i]){
            flag = 1;
        }
    }
    if(!flag){
        int carry=1;
        for(int i=size-1;i>=0;i--){
            int temp = a[i] + carry;
            carry = temp/10;
            a[i] = temp%10;
        }
        if(carry!=0){

        }
        //for(int i=0;i<size;i++) printf("%d", a[i]);
    }
    flag=0;
    for(int i=0;i<size;i++){
        if(a[i] != 9){
            flag = 1;
            break;
        }
    }
    if(size == 1){
        printf("The palindrome is 11\n");
        return 0;
    }
    else if(flag == 0 && size>1){
        a[0] = 1;
        for(int i=1;i<size;i++) a[i] = 0;
        a[size++] = 1;
        printf("The palindrome is ");
        for(int i=0;i<size;i++) printf("%d",a[i]);
    }
    else if(flag==1 && size>1){
        int left,right;
        if(size%2==0){
            left = size/2 - 1;
            right = size/2;
        }
        else{
            left = size/2 - 1;
            right = size/2 + 1;
        }
        //ignore duplicates
        while(a[left] == a[right]){
            left--;
            right++;
        }

        if(size%2==0){
            if(a[left] < a[right]){
                if(a[size/2] == 9){
                    left = size/2 - 1;
                    right = size/2;
                    while(a[left] == a[right] && a[left] == 9){
                        left--;
                        right++;
                    }
                    for(int i=left+1;i<right;i++) a[i] = 0;
                    a[left]++;
                }
                else{
                    left = size/2 - 1;
                    right = size/2;
                    a[left]++;
                }
            }
        }
        else{
            if(a[left] < a[right] && a[size/2] == 9){
                left = size/2 - 1;
                right = size/2 + 1;
                while(a[left] == a[right] && a[left] == 9){
                    left--;
                    right++;
                }
                for(int i=left+1;i<right;i++) a[i] = 0;
                a[left]++;
            }
            else if( a[left] < a[right] && a[size/2] != 9){
                a[size/2]++;
                left = size/2 - 1;
                right = size/2 + 1;
            }
        }
        //copy
        while (left>=0)
        {
            //printf("Copy mode");
            a[right] = a[left];
            right++;
            left--;
        }
        printf("The palindrome is ");
        for(int i=0;i<size;i++) printf("%d",a[i]);
    }
//    printf("The palindrome is ");
//    for(int i=0;i<size;i++) printf("%d",a[i]);
    printf("\n");
    return 0;
}
