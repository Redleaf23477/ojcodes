#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long int;

ll n, m;
string str;
vector<ll> arr;

void init()
{
    cin >> n >> m;
    cin >> str;
    arr.resize(m);
    for(auto &a : arr) cin >> a;
}

void process()
{
    vector<ll> sum[26];
    for(int c = 0; c < 26; c++)
    {
        sum[c].resize(n+1, 0);
        char ch = 'a' + c;
        for(int i = 1; i <= n; i++)
            sum[c][i] = sum[c][i-1] + (str[i-1] == ch);
    }
    vector<ll> ans(26, 0);
    for(int c = 0; c < 26; c++) ans[c] = sum[c][n];
    for(auto x : arr)
    {
        for(int c = 0; c < 26; c++)
            ans[c] += sum[c][x];
    }
    for(auto a : ans) cout << a << " ";
    cout << endl;
}

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
}