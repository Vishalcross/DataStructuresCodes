#include<stdio.h>
int bubble(int n,int a[n]){
    int count=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                count++;
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    return count;
}
int insertion(int n, int a[n]){
    int count=0;
    for(int i=0;i<n-1;i++){
        //if(a[i]>a[i+1]){
            int j = i+1;
            while(a[j-1]>a[j] && j>0){
                count++;
                int temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
                j--;
            }
        //}
    }
    return count;
}


int selection(int n, int a[n]){
    int count=0;
    for(int i=0;i<n-1;i++){
        int index=i,min = a[i];
        for(int j=i+1;j<n;j++){
            if(a[j]<min){
                index = j;
                min = a[j];
            }
        }
        if(index != i) {
            count++;
            a[index] = a[i];
            a[i] = min;
        }
    }
    return count;
}


int main(){
    int n;
    scanf("%d",&n);
    int bub[n],sel[n],ins[n];
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        bub[i] = x;
        sel[i] = x;
        ins[i] = x;
    }
    int b = bubble(n,bub);
    int i = insertion(n,ins);
    int s = selection(n,sel);
    for(int i=0;i<n;i++) printf("%d ",bub[i]);
    printf("\n");
     for(int i=0;i<n;i++) printf("%d ",ins[i]);
    printf("\n");
     for(int i=0;i<n;i++) printf("%d ",sel[i]);
    printf("\n");
    printf("Bubble: %d Insertion: %d Selection: %d\n",b,i,s);
    if(b<=i){
        if(i<=s){
            printf("Bubble");
        }
        else if(i>s){
            if(s<b){
                printf("Selection");
            }
            else{
                printf("Bubble");
            }
        }
    }
    else{
        if(i<=s){
            printf("Insertion");
        }
        else if(i>s){
            if(s<b){
                printf("Selection");
            }
            else{
                printf("Bubble");
            }
        }
    }
    return 0;
}
