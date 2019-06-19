//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

const int N = 100005;
ll n;
ll sp[N];

void init();
void process();

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    init();
    process();
    cout.flush();
    return 0;
}

void init()
{
    cin >> n;
    for(int i = 0; i < N; i++) sp[i] = i;
    for(ll i = 2; i < N; i++)
    {
        if(sp[i] == i)
        {
            for(ll j = i*i; j < N; j+=i)
            {
                if(sp[j] == j) sp[j] = i;
            }
        }
    }
}

void process()
{
    int color = 1;
    vector<int> ans(n+1);
    map<int, int> mp;
    for(int i = 2; i <= n; i++)
    {
        if(sp[i] == i) ans[i] = mp[i] = color++;
    }
    for(int i = 2; i <= n; i++)
    {
        if(sp[i] != i) 
        {
            if(mp.count(sp[i]) == 0) mp[sp[i]] = color++;
            ans[i] = mp[sp[i]];
        }
    }
    for(int i = 2; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
}

