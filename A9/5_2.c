#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int nax = 1e6 + 5;
vector<int> divisors[nax];
bool is_prime[nax];
ll low,high,a,b,t;

ll divCeil(ll a,ll b)
{
    return (a+b-1)/b;
}
void Seive(ll low,ll high)
{
    for(int i = 2; i < nax; ++i)
        is_prime[i] = true;
    for(int i = 2; i < nax; ++i)
        if(is_prime[i]) {
            for(int j = 2 * i; j < nax; j += i)
                is_prime[j] = false;
            for(ll x = divCeil(low, i) * i; x <= high; x += i)
                divisors[x-low].push_back(i);
        }
}
 int main() {
    ll low, high;
    cin >> low >> high;
    Seive(low,high);

    ll answer = 0;
    for(ll x = low; x <= high; ++x) {
        vector<int> times;
        ll tmp = x;
        for(int prime : divisors[x-low]) {
            int cnt = 0;
            while(tmp % prime == 0) {
                tmp /= prime;
                ++cnt;
            }

            times.push_back(cnt);
        }
        if(tmp != 1)
            times.push_back(1);
        sort(times.begin(), times.end());
        while(!times.empty()) {
            ll here = 1;
            for(ll a : times)
                here *= (a + 1);
            answer += here;
            times.back()--;
            if(times.back() == 0) times.pop_back();
            sort(times.begin(), times.end());
        }
    }
    cout << answer << "\n";
}
