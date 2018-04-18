#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n],m=2e9;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			m=min(m,a[i]);
		}
        int ans=2e9;
        for(int i=0;i<=4;i++)
        {
            int toreach=m-i;
            int cans=0;
            for(int j=0;j<n;j++)
            {
                int tmp=(a[j]-toreach);
                cans+=tmp/5;
                tmp%=5;
                cans+=tmp/3;
                tmp%=3;
                cans+=tmp;
            }
            ans=min(cans,ans);
        }
        cout<<ans<<'\n';
    }

    return 0;
}
