#include<stdio.h>
#include<string.h>

int main(){
    int n;
    scanf("%d",&n);
    int a[n],max=-1;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i] > max) max = a[i];
    }

    for(int i=0;i<n;i++) printf("%d ",a[i]);
    int frequency[max+1];
    memset(frequency,0,sizeof(frequency));
    for(int i=0;i<n;i++) frequency[a[i]]++;

    for(int i=0;i<max+1;i++) printf("%d ",frequency[i]);
    int i=a[n-1];
    while(i>=0){
        printf("Entering %d\n",frequency[i]);
        if(frequency[i]%2==1){
            printf("Vishal\n");
            return 0;
        }
        else if(frequency[i]%2==0 && frequency[i] != 0){
            i--;
        }
        else{
            i--;
        }
    }
    printf("Tanmay\n");
    //for(int i=0;i<a[n-1]+1;i++) printf("%d ",frequency[i]);
    return 0;
}
