#include<stdio.h>
#include<string.h>
#include<math.h>
void mergeSort(int n, int* a, int* b){
    if(n<=1){
        return;
    }
    int mid = n/2;
    mergeSort(mid,a,b);
    mergeSort(n - mid,a+mid,b+mid);
    int* l1 = a;
    //int* l2 = b;
    int *r1 = a+mid;
    //int *r2 = b+mid;
    int temp1[n],temp2[n],index=0;
    memset(temp1,0,sizeof(temp1));
    memset(temp2,0,sizeof(temp2));
    while(l1< a+mid && r1<a+n){
        if(*l1 < *r1){
            temp1[index] = *l1;
            temp2[index++] = *(l1 - a + b);
            l1++;
            //l2++;
        }
        else{
            temp1[index] = *r1;
            temp2[index++] = *(r1 - a + b);
            r1++;
            //r2++;
        }
    }
    while(l1<a+mid && index<n){
        temp1[index] = *l1;
        temp2[index++] = *(l1 - a + b);
        l1++;
        //l2++;
    }
    while(r1<a+n && index<n){
        temp1[index] = *r1;
        temp2[index++] = *(r1 - a + b);
        r1++;
        //r2++;
    }
    for(int i=0;i<n;i++){
        a[i] = temp1[i];
        b[i] = temp2[i];
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int num[n],factors[n];
    memset(num,0,sizeof(num));
    memset(factors,0,sizeof(factors));
    for(int i=0;i<n;i++) {
        scanf("%d",&num[i]);
    }
    //factor finding
    for(int i=0;i<n;i++){
        int count=0;
        int temp = (int)sqrt(num[i]);
        for(int j=1;j<=temp;j++){
            if((num[i])%j == 0){
                count++;
            }
        }
        if(temp*temp != num[i]){
            count*=2;
        }
        else{
            count*=2;
            count--;
        }
        factors[i] = count;
    }

    mergeSort(n,factors,num);

    for(int i=n-1;i>=0;i--) printf("%d %d\n",num[i],factors[i]);

    printf("\n");
    for(int i=n-1;i>=0;i--){
        printf("%d ",num[i]);
    }
//Alternate Solution
    /*
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[0][i] == b[j]){
                a[1][i] = j;
                break;
            }
        }
    }
    //sorting on ascending factors
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[2][i] < a[2][j]){
                for(int k=0;k<3;k++){
                    int x = a[k][i];
                    a[k][i] = a[k][j];
                    a[k][j] = x;
                }
            }
        }
    }
    //sorting based on ascending indices
    int i=0;
    while(i<n){
        int j=i;
        while(a[2][j] == a[2][i]){
            j++;
        }
        for(int k=i;k<j-1;k++){
            for(int l=k+1;l<j;l++){
                if(a[1][k] > a[1][l]){
                    for(int m=0;m<3;m++){
                        int x = a[m][k];
                        a[m][k] = a[m][l];
                        a[m][l] = x;
                    }
                }
            }
        }
        i = j;
    }
    for(int i=0;i<n;i++) printf("%d ",a[0][i]);
    */
    return 0;
}
