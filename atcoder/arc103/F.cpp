//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

class DisjointSet
{
private:
    vector<int> pa, sz;

public:
    void init(int n)
    {
        pa.resize(n), sz.resize(n);
        for(int i = 0; i < n; i++)
        {
            pa[i] = i, sz[i] = 1;
        }
    }
    int findrt(int x)
    {
        if(x == pa[x]) return x;
        else return pa[x] = findrt(pa[x]);
    }
    bool same(int x, int y) { return findrt(x) == findrt(y); }
    int ccSize(int x) { return sz[findrt(x)]; }
    void uni(int x, int y)
    {
        x = findrt(x), y = findrt(y);
        if(x == y) return;
        if(sz[x] > sz[y]) swap(x, y);
        pa[x] = y, sz[y] += sz[x];
    }
};

const int N = 100005;

int vn;
vector<ll> arr;
map<ll, int> ori2idx, val2idx;

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
    cin >> vn;
    arr.resize(vn);
    for(int i = 0; i < vn; i++) cin >> arr[i];
    for(int i = 0; i < vn; i++) ori2idx[arr[i]] = i;
    sort(arr.begin(), arr.end());
    for(int i = 0; i < vn; i++) val2idx[arr[i]] = i;
}

void dfs(int idx, vector<int> tree[])
{
    static vector<bool> vis(vn, false);
    vis[idx] = true;
    for(auto c:tree[idx])
    {
        if(vis[c]) continue;
        cout << ori2idx[arr[idx]]+1 << " " << ori2idx[arr[c]]+1 << endl;
        dfs(c, tree);
    }
}

void process()
{
    vector<int> tree[N]; 
    DisjointSet ds; ds.init(vn);
    for(int i = vn-1; i >= 0; i--)
    {
        if(ds.ccSize(i) == 1)
        {
            int idx = i;
            while(true)
            {
                ll paVal = arr[idx] - vn + 2*ds.ccSize(idx);
                if(val2idx.count(paVal) == 0) break;
                int paidx = val2idx[paVal];
                if(ds.same(idx, paidx)) break;
                tree[idx].push_back(paidx);
                tree[paidx].push_back(idx);
                ds.uni(idx, paidx);
                idx = paidx;
            }
        }
    }
    if(ds.ccSize(0) == vn)
    {
        dfs(0, tree);
    }
    else cout << -1 << endl;
}

