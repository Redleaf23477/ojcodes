//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

class DisjointSet
{
private:
    int forestNum;
    vector<int> pa, sz;
public:
    void init(int n)
    {
        forestNum = n;
        pa.resize(n);
        sz.resize(n);
        for(int i = 0; i < n; i++)
        {
            pa[i] = i, sz[i] = 1;
        }
    }
    int findrt(int x) 
    {
        if(pa[x] == x) return x;
        else return pa[x] = findrt(pa[x]);
    }
    bool same(int x, int y) { return findrt(x) == findrt(y); }
    void uni(int x, int y)
    {
        x = findrt(x), y = findrt(y);
        if(x == y) return;
        forestNum--;
        if(sz[x] > sz[y]) swap(x, y);
        pa[x] = y;
        sz[y] += sz[x];
    }
    int ccNum() { return forestNum; }
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
        int a, b, c; cin >> a >> b >> c;
        ds.uni(a, b);
    }
}

void process()
{
    cout << ds.ccNum() << endl;
}

