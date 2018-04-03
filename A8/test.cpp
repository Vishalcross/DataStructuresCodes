#include <bits/stdc++.h>
using namespace std;
bool check[10009];
void sieve()
{
    for(int i=2;i<=100;i++)
    {
        if(!check[i])
        {
            for(int j=i*i;j<=10000;j+=i)
            {
                check[j] = true;
            }

        }
    }
}
int conv_num(int a[])
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
    for(int i=0;i<10009;i++) cout<<check[i]<<" ";
    while(t--)
    {
        int digit[4],dist[10009],a,b,parent[10009];
        scanf("%d%d",&a,&b);
        memset(dist,-1,sizeof(dist));
        memset(parent,-1,sizeof(parent));
        queue<int> q;
        dist[a]=0;
        q.push(a);
        parent[a]=0;
        while(!q.empty())
        {
            int num = q.front();
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
                        q.push(temp);
                        cout<<temp<<endl;
                    }
                }
            }
            q.pop();
        }
        dist[b]==-1 ? cout<<"Impossible"<<endl : cout<<dist[b]<<endl;
    }
    return 0;
}
