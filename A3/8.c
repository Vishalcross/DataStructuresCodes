#include<stdio.h>
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int visited[n],data[n];
    for(int i=0;i<n;i++) scanf("%d",&data[i]);
    for(int i=0;i<n;i++){
        if(i<m) visited[i] = -1;
        else visited[i] = 0;
    }
    int temp[m];
    for(int i=m;i<n;i++){
        //Copy
        int k=0;
        for(int j=i-m;j<i;j++){
            temp[k++] = data[j];
        }
        mergeSort(temp,0,m-1);
        if(data[i] >= 3*temp[m/2]) visited[i] = 1;
    }
    for(int i=0;i<n;i++) printf("%d ",visited[i]);
    return 0;
}
