#include<stdio.h>
#include<string.h>
int merge(int n, int l, int r, int arr[n], int left[l], int right[r]) {
    int i = 0, j = 0, count = 0;
    while (i < l || j < r) {
        if (i == l) {
            arr[i+j] = right[j];
            j++;
        }
        else if (j == r) {
            arr[i+j] = left[i];
            i++;
        }
        else if (left[i] <= right[j]) {
            arr[i+j] = left[i];
            i++;
        }
        else {
            arr[i+j] = right[j];
            count += l-i;
            j++;
        }
    }
    return count;
}

int invCount(int n, int arr[n]) {
    if (n < 2)
        return 0;

    int m = (n + 1) / 2;
    int left[m];
    memset(left,0,sizeof(left));
    for(int i=0;i<m;i++) left[i] = arr[i];
    int right[n-m];
    memset(right,0,sizeof(right));
    for(int i=m;i<n;i++) right[i-m] = arr[i];

    return invCount(m,left) + invCount(n-m,right) + merge(n,m,n-m,arr, left, right);
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    int  count = invCount(n,arr);
    printf("%d",count);
    return 0;
}
