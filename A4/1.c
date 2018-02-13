#include<stdio.h>
#include<string.h>
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
    int a[n],b[2][n];
    int k = 0;
    memset(b,0,sizeof(b));
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        int flag = 0;
        for(int j=0;j<k;j++){
            if(b[0][j] == a[i]){
                b[1][j]++;
                flag = 1;
                break;
            }
        }
        if(!flag){
            b[0][k] = a[i];
            b[1][k++] = 1;
        }
        //temp[i] = a[i];
    }
    for(int i=0;i<k;i++) printf("%d %d\n",b[0][i],b[1][i]);
    printf("\n");
    int num[k],frequency[k];
    memset(num,0,sizeof(num));
    memset(frequency,0,sizeof(frequency));
    for(int i=0;i<k;i++){
        num[i] = b[0][i];
        frequency[i] = b[1][i];
    }

    mergeSort(k,frequency,num);

    for(int i=k-1;i>=0;i--) printf("%d %d\n",num[i],frequency[i]);

    printf("\n");
    for(int i=k-1;i>=0;i--){
        for(int j=0;j<frequency[i];j++) printf("%d ",num[i]);
    }






















    /*
    for(int i=0;i<k;i++){
        int max = b[1][i],index=i;
        for(int j=i;j<k;j++){
            if(b[1][j] > max){
                index = j;
                max = b[1][j];
            }
        }
        for(int j=0;j<2;j++){
            ans[j][l] = b[j][index];
        }
        printf("Data within the answer:\n");
        for(int m=0;m<l;m++) printf("%d %d\n",ans[0][m],ans[1][m]);
        l++;
    }
    printf("\n");
    for(int i=0;i<k;i++) printf("%d %d\n",ans[0][i],ans[1][i]);*/
    /*int k=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(temp[i]>temp[j]){
                int x = temp[i];
                temp[i] = temp[j];
                temp[j] = x;
            }
        }
    }
    int visited[3][n];
    memset(visited,0,sizeof(visited));
    int i=0;
    while(i<n){
        int j=i;
        visited[0][k] = temp[i];
        while(temp[j] == temp[i]){
            visited[2][k]++;
            j++;
        }
        k++;
        i = j;
    }
    //sorting based on frequency descending
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(visited[2][i] < visited[2][j]){
                for(int k=0;k<3;k++){
                    int x = visited[k][i];
                    visited[k][i] = visited[k][j];
                    visited[k][j] = x;
                }
            }
        }
    }
    //k=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visited[0][i] == a[j]){
                visited[1][i] = j;
                break;
            }
        }
    }
    i=0;
    while(i<n){
        int j=i;
        while(visited[2][j] == visited[2][i]){
            j++;
        }
        for(int k=i;k<j-1;k++){
            for(int l=k+1;l<j;l++){
                if(visited[1][k] > visited[1][l]){
                    for(int m=0;m<3;m++){
                        int x = visited[m][k];
                        visited[m][k] = visited[m][l];
                        visited[m][l] = x;
                    }
                }
            }
        }
        i = j;
    }
    for(int i=0;i<n;i++) printf("%d %d %d\n",visited[0][i],visited[1][i],visited[2][i]);
    for(int i=0;i<n;i++){
        for(int j=0;j<visited[2][i];j++){
            printf("%d ",visited[0][i]);
        }
    }
    printf("\n");
    //for(int i=0;)*/
    return 0;
}
