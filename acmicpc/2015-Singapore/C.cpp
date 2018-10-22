//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

#define PB push_back
#define SZ(x) (int)x.size()
#define F first
#define S second

struct DisjointSet {
    // save() is like recursive
    // undo() is like return
    static const int MXN = 500005;
    int n, fa[MXN], sz[MXN];
    vector<pair<int*,int>> h;
    vector<int> sp;
    void init(int tn) {
        n=tn;
        for (int i=0; i<n; i++) sz[fa[i]=i]=1;
        sp.clear(); h.clear();
    }
    void assign(int *k, int v) {
        h.PB({k, *k});
        *k=v;
    }
    void save() { sp.PB(SZ(h)); }
    void undo() {
        assert(!sp.empty());
        int last=sp.back(); sp.pop_back();
        while (SZ(h)!=last) {
            auto x=h.back(); h.pop_back();
            *x.F=x.S;
        }
    }
    int f(int x) {
        while (fa[x]!=x) x=fa[x];
        return x;
    }
    void uni(int x, int y) {
        x=f(x); y=f(y);
        if (x==y) return ;
        if (sz[x]<sz[y]) swap(x, y);
        assign(&sz[x], sz[x]+sz[y]);
        assign(&fa[y], x);
    }
}djs;

const int N = 20005;
int n;
vector<int> recipe;

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
    cin >> n;
}

void process()
{
    int ans = 0;
    int sz;
    djs.init(500003);
    for(int i = 0; i < n; i++)
    {
        djs.save();
        recipe.clear();
        cin >> sz;
        recipe.resize(sz);
        for(int j = 0; j < sz; j++) cin >> recipe[j];

        for(int j = 1; j < sz; j++) djs.uni(recipe[j], recipe[j-1]);
        if(djs.sz[djs.f(recipe[0])] == sz) djs.save(), ans++;
        else djs.undo();
    }
    cout << ans << endl;
}

