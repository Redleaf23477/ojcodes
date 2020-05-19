// by redleaf23477
#include <bits/stdc++.h>

// iostream macros
#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
// chrono macros
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()
#define chrono_rand_seed chrono_now.time_since_epoch().count()
// random
std::mt19937_64 myrand(chrono_rand_seed);

using namespace std;
using ll = long long int;

const int N = 200005;

int n, k;
vector<int> tree[N], dep, chsz;

void init();
void process();

struct cmp
{
    bool operator() (const int &lhs, const int &rhs)
    {
        return dep[lhs] < dep[rhs];
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    init();
    process();
    cout.flush();
    return 0;
}

void dfs(int u, int p, int d)
{
    dep[u] = d;
    chsz[u] = 0;
    for(auto v : tree[u])
    {
        if(v == p) continue;
        dfs(v, u, d+1);
        chsz[u] += 1 + chsz[v];
    }
}

void init()
{
    cin >> n >> k;
    for(int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;
        tree[u].emplace_back(v);
        tree[v].emplace_back(u);
    }
    dep.resize(n+1, 0);
    chsz.resize(n+1, 0);
    dfs(1, 1, 0);
}

void process()
{
    vector<ll> tmp(n);
    for(int i = 1; i <= n; i++)
    {
        tmp[i-1] = dep[i] - chsz[i];
    }
    sort(tmp.begin(), tmp.end());
    ll sum = 0;
    for(int i = n-1; i >= n-k; i--)
        sum += tmp[i];
    cout << sum << endl;
}

