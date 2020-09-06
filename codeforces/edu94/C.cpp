// Tomioka has no friends
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long int;

void solve(string &str, ll x)
{
    int n = str.size();
    string ans(n, '1');
    for(int i = 0; i < n; i++)
    {
        if(str[i] == '0')
        {
            if(i-x >= 0) ans[i-x] = '0';
            if(i+x < n) ans[i+x] = '0';
        }
    }
    bool good = true;
    for(int i = 0; i < n && good; i++)
    {
        bool flg = str[i] == '0';
        if(str[i] == '1')
        {
            if(i-x >= 0 && ans[i-x] == '1') flg = true;
            if(i+x < n && ans[i+x] == '1') flg = true;
        }
        if(!flg) good = false;
    }

    if(good) cout << ans << endl;
    else cout << -1 << endl;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--)
    {
        string s; cin >> s;
        ll x; cin >> x;
        solve(s, x);
    }
    cout.flush();
    return 0;
}

