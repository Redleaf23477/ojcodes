// by redleaf23477
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"

using namespace std;
using ll = long long int;

ll n, x;
vector<ll> pre;

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--)
    {
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init()
{
    string str;
    cin >> n >> x >> str;
    pre.resize(n, 0);
    if(str[0] == '0') pre[0] = 1;
    else pre[0] = -1;
    for(int i = 1; i < n; i++)
    {
        if(str[i] == '0') pre[i] = pre[i-1]+1;
        else pre[i] = pre[i-1]-1;
    }
}

void process()
{
    ll ans = 0;
    if(x == 0) ans++;
    ll dur = pre.back();
    for(int i = 0; i < n; i++)
    {
        if(dur == 0)
        {
            if((x-pre[i]) == 0) { ans = -1; break; }
        }
        else
        {
            if((x-pre[i])%dur == 0 && (x-pre[i])*dur >= 0) ans++;
        }
    }
    cout << ans << endl;
}
