#include<stdio.h>
int main(){
    int n,distinct;
    scanf("%d %d",&n,&distinct);
    int min=0, max=9, distinct1 = distinct, distinct2 = distinct;
    printf("The minimum number is ");
    if(distinct != 1){
        printf("1");
        distinct1--;
        for(int i=0;i<n-distinct1;i++){
            printf("%d",min);
        }
        distinct1--;
        min+=2;
        for(int i=0;i<distinct1;i++) printf("%d",min++);
    }
    else {
        for(int i=0;i<n;i++) printf("1");
    }
    printf("\nThe maximum number is ");
    for(int i=0;i<n-distinct2+1;i++) printf("%d",max);
    max--;
    distinct2--;
    for(int i=0;i<distinct2;i++) printf("%d",max--);

}
