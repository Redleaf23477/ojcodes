//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;

const int N = 100005;
ll n, m;
vector<int> tree[N];
vector<ll> dp[N];
ll ans[N]; // ans[i] = # of ways when i is black root

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    init();
    process();
    cout.flush();
    return 0;
}

void init()
{
    cin >> n >> m;
    for(int i = 1; i < n; i++)
    {
        int x, y; cin >> x >> y;
        tree[x].emplace_back(y);
        tree[y].emplace_back(x);
        dp[x].emplace_back(1);
        dp[y].emplace_back(1);
    }
}

ll add(ll lhs, ll rhs) { return (lhs + rhs)%m; }
void mul_self(ll &lhs, ll rhs) { lhs = lhs * rhs % m; }

// let v be the root, count ways
ll dfs1(int v, int p)
{
    ll cnt = 1;
    for(size_t i = 0; i < tree[v].size(); i++)
    {
        int c = tree[v][i];
        if(c == p) continue;
        dp[v][i] = dfs1(c, v);
        mul_self(cnt, add(1, dp[v][i]));
    }

    return cnt;
}

// change root from v to its childrens
void dfs2(int v, int p, ll cnt)
{
    if(tree[v].size() == 0) { ans[v] = 1; return; }
    for(size_t i = 0; i < tree[v].size(); i++)
        if(tree[v][i] == p) { dp[v][i] = cnt; break; }
    vector<ll> pre(tree[v].size(), 1), suf(tree[v].size(), 1);
    pre[0] = add(1, dp[v].front()), suf[tree[v].size()-1] = add(1, dp[v].back());
    for(int i = 1; i < dp[v].size(); i++) 
    {
        mul_self(pre[i], pre[i-1]);
        mul_self(pre[i], add(1, dp[v][i]));
    }
    for(int i = dp[v].size()-2; i >= 0; i--)
    {
        mul_self(suf[i], suf[i+1]);
        mul_self(suf[i], add(1, dp[v][i]));
    }
    /*
    cout << "v = " << v << endl;
    for(auto d:dp[v]) { cout << d << " "; } cout << endl;
    for(auto d:pre) { cout << d << " "; } cout << endl;
    for(auto d:suf) { cout << d << " "; } cout << endl;
    */
    ans[v] = pre.back();
    for(size_t i = 0; i < tree[v].size(); i++)
    {
        int c = tree[v][i];
        if(c == p) continue;
        ll tmp = 1;
        if(i > 0) mul_self(tmp, pre[i-1]);
        if(i+1 < tree[v].size()) mul_self(tmp, suf[i+1]);
        dfs2(c, v, tmp);
    }
}

void process()
{
    dfs1(1, 1);
    dfs2(1, 1, 7122);
    for(int i = 1; i <= n; i++) cout << ans[i] << endl;
}

