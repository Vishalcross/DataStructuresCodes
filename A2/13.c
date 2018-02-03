#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
    int size[3];
    for(int i=0;i<3;i++) scanf("%d", &size[i]);
    int *a[3];
    for(int i=0;i<3;i++){
        a[i] = (int*)malloc(size[i]*sizeof(int));
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<size[i];j++){
            scanf("%d",&a[i][j]);
        }
    }
    int optimum=999999,sum=0,a1=0,a2=0,a3=0;
    int m=0,k=0;
    for(int i=0;i<size[0];i++){
        sum = 0;
        a1 = a[0][i];
        a2 = a[1][m];
        while(a1 >= a[1][m] && m<size[1]){
            printf("m is %d\n",m);
            m++;
        }
        if(m != 0) a2 = a[1][m-1];

        a3 = a[2][k];
        while(a2 >= a[2][k] && k<size[2]){
            printf("k is %d\n",k);
            k++;
        }
        if(k != 0) a3 = a[2][k-1];

        printf("a1 is %d a2 is %d a3 is %d\n",a1,a2,a3);
        sum = abs(a1 - a2) + abs(a2 - a3) + abs(a3 - a1);
        printf("sum is %d\n",sum);
        if(sum < optimum) optimum = sum;
    }

    printf("optimum is %d",optimum);

    return 0;
}
