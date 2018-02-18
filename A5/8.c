#include<stdio.h>
#include<string.h>
int main(){
    int n;
    scanf("%d",&n);
    char a[n][1000];
    memset(a,0,sizeof(a));
    for(int i=0;i<n;i++) {
        char str[1000];
        memset(str,0,sizeof(str));
        scanf("%s",str);
        strcpy(a[i],str);
    }

    int sum[n],max=0;
    memset(sum,0,sizeof(sum));
    for(int i=0;i<n;i++){
        int temp = 0;
        for(int j=0;j<strlen(a[i]);j++){
            temp += a[i][j];
        }
        //printf("%d ",temp);
        while(temp){
            sum[i] += (temp%2);
            temp/=2;
        }
        if(max < sum[i]) max = sum[i];
        //printf("%d\n",sum[i]);
    }
    //printf("%d",max);
    //count sort
    int frequency[max+1];
    memset(frequency,0,sizeof(frequency));
    for(int i=0;i<n;i++){
        frequency[sum[i]]++;
    }
    int cumulative[max+1];
    memset(cumulative,0,sizeof(cumulative));
    cumulative[0] = frequency[0];
    for(int i=1;i<max+1;i++){
        cumulative[i] = cumulative[i-1] + frequency[i];
    }

    int result[max+1];
    char resultString[max+1][1000];
    memset(result,0,sizeof(result));
    memset(resultString,0,sizeof(resultString));
    for(int i=n-1;i>=0;i--){
        result[cumulative[sum[i]]] = sum[i];
        strcpy(resultString[cumulative[sum[i]]],a[i]);
        cumulative[sum[i]]--;
    }
    for(int i=1;i<max+1;i++) if(result[i] != 0) printf("%d %s\n",result[i],resultString[i]);
    return 0;
}
