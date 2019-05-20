//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

class DisjointSet
{
private:
    static const int N = 500005;
    vector<int> pa;
    vector<int> sz;

public:
    void init(int n)
    {
        pa.resize(n);
        sz.resize(n);
        for(int i = 0; i < n; i++)
        {
            pa[i] = i;
            sz[i] = 1;
        }
    }
    int findrt(int x)
    {
        if(pa[x] == x) return x;
        else return pa[x] = findrt(pa[x]);
    }
    bool same(int x, int y)
    {
        return findrt(x) == findrt(y);
    }
    void uni(int x, int y)
    {
        x = findrt(x), y = findrt(y);
        if(x == y) return;
        if(sz[x] > sz[y]) swap(x, y);
        pa[x] = y, sz[y] += sz[x];
    }
    int getSize(int x) { return sz[findrt(x)]; }
};

int n, m;
DisjointSet ds;

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
    cin >> n >> m;
    ds.init(n);
    while(m--)
    {
        int sz; cin >> sz;
        if(sz == 0) continue;
        vector<int> tmp(sz);
        for(int i = 0; i < sz; i++) 
        {
            cin >> tmp[i]; 
            tmp[i]--;
        }
        if(sz > 1)
        {
            for(int i = 1; i < sz; i++) ds.uni(tmp[0], tmp[i]);
        }
    }
}

void process()
{
    for(int i = 0; i < n; i++) cout << ds.getSize(i) << " ";
    cout << endl;
}

