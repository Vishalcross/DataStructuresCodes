#include<string.h>
#include<stdio.h>
#include<stdbool.h>
bool check[10009];
void sieve()
{
    for(int i=2;i<=100;i++)
    {
        if(!check[i])
        {
            for(int j=i*i;j<=10000;j+=i)
                check[j] = true;
        }
    }
}
int conv_num(int a[4])
{
    int temp=0,k=0;
    while(k<4){
        temp = temp*10 + a[k];
        k++;
    }
    return temp;
}
void arr(int a[],int num)
{
    int w=3;
    while(num)
    {
        a[w--] = num%10;
        num/=10;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    sieve();
    while(t--)
    {
        int digit[4],dist[10009],a,b,parent[10009];
        scanf("%d %d",&a,&b);
        memset(dist,-1,sizeof(dist));
        memset(parent,-1,sizeof(parent));
        //queue<int> q;
        dist[a]=0;
        int queue[10000];
        memset(queue,0,sizeof(queue));
        int tail = -1;
        int head = 0;
        //q.push(a);
        queue[++tail] = a;
        parent[a]=0;
        while(tail >= head)
        {
            int num = queue[head];
            for(int k=3;k>=0;k--)
            {
                arr(digit,num);
                for(int i=0;i<=9;i++)
                {
                    digit[k] = i;
                    int temp = conv_num(digit);
                    if((!check[temp]) && dist[temp]==-1 && temp>=1000)
                    {
                        dist[temp]= dist[num] + 1;
                        parent[temp]=num;
                        //q.push(temp);
                        queue[++tail] = temp;
                    }
                }
            }
            //q.pop();
            head++;
            //printf("%d\n",queue[head++]);
        }
        ((dist[b]==-1) ? printf("Impossible\n") : printf("%d\n",dist[b]));
    }
    return 0;
}
