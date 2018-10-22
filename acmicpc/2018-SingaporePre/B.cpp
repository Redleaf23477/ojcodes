//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 1000006;

struct DisjointSet
{
    int n;
    int pa[N];
    void init(int sz)
    {
        n = sz;
        for(int i = 0; i < n; i++) pa[i] = i;
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
        pa[findrt(x)] = findrt(y);
    }
};

int n, k;
DisjointSet ds;

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
    cin >> n >> k;
    ds.init(n);
    while(k--)
    {
        int a, b; cin >> a >> b; a--, b--;
        ds.uni(a, b);
    }
}

void process()
{
    bool good = true;
    for(int i = 0; i < n && good; i++)
    {
        good = ds.same(n-i-1, i);
    }
    if(good) cout << "Yes" << endl;
    else cout << "No" << endl;
}

