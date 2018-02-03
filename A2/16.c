#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int n,i;
    scanf("%d",&n);


    int** a = (int**) malloc(n*sizeof(int*));
    for(i=0;i<n;i++) a[i] = (int*) malloc(n*sizeof(int));
    int total=n*n,count1,count2;

    int j=0,k=1,l=n,m=0;
    i=0;
    while(k<=total && l>0){
        while(m < l){
            for(count1=0;count1<n;count1++){
               // for(count2=0;count2<n;count2++) printf("%d ",a[count1][count2]);
               // printf("\n");
            }
            a[i][j] = k;
            k++;
            j++;
            m++;
        }
        j--;
        i++;
        l--;
        m=0;
        while(m < l){
            for(count1=0;count1<n;count1++){
                //for(count2=0;count2<n;count2++) printf("%d ",a[count1][count2]);
               // printf("\n");
            }
            a[i][j] = k;
            k++;
            m++;
            i++;
        }
        i--;
        j--;
        m=0;
        while(m < l){
            for(count1=0;count1<n;count1++){
               // for(count2=0;count2<n;count2++) printf("%d ",a[count1][count2]);
               // printf("\n");
            }
            a[i][j] = k;
            k++;
            j--;
            m++;
        }
        j++;
        i--;
        m=0;
        l--;
        while(m < l){
            for(count1=0;count1<n;count1++){
                //for(count2=0;count2<n;count2++) printf("%d ",a[count1][count2]);
               // printf("\n");
            }
            a[i][j] = k;
            k++;
            m++;
            i--;
        }
        i++;
        j++;
        m=0;
    }
    for(count1=0;count1<n;count1++){
        for(count2=0;count2<n;count2++) printf("%d ",a[count1][count2]);
        printf("\n");
    }
    return 0;
}
