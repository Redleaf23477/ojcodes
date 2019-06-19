//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;

struct People
{
    ll h, b, d;
};

bool cmp(const People &a, const People &b)
{
    return a.h < b.h || (a.h == b.h && a.b < b.b);
}

const int N = 100005;
int n, st_n;
People people[N];
ll st[4*N];

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

void buildst(int l, int r, int idx)
{
    st[idx] = 0;
    if(l == r) return;
    int mid = (l+r)/2;
    buildst(l, mid, idx*2);
    buildst(mid+1, r, idx*2+1);
}

void modify_if_greater(int x, ll v, int l, int r, int idx)
{
    if(l == x && r == x)
    {
        st[idx] = max(st[idx], v);
        return;
    }
    if(x < l || r < x) return;
    int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;
    modify_if_greater(x, v, l, mid, lson);
    modify_if_greater(x, v, mid+1, r, rson);
    st[idx] = max(st[lson], st[rson]);
}

ll query(int L, int R, int l, int r, int idx)
{
    if(L <= l && r <= R) return st[idx];
    if(r < L || R < l) return 0;
    int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;
    return max( query(L, R, l, mid, lson), query(L, R, mid+1, r, rson) );
}

void init()
{
    cin >> n;
    int h[N], b[N], d[N];
    vector<ll> tmp(n);
    for(int i = 0; i < n; i++) 
    {
        cin >> h[i] >> b[i] >> d[i];
        tmp[i] = b[i];
    }
    sort(tmp.begin(), tmp.end());
    tmp.resize(unique(tmp.begin(), tmp.end())-tmp.begin());
    st_n = tmp.size();
    for(int i = 0; i < n; i++) b[i] = lower_bound(tmp.begin(), tmp.end(), b[i])-tmp.begin()+1;
    for(int i = 0; i < n; i++) people[i] = (People){h[i], b[i], d[i]};
    sort(people, people+n, cmp);
    for(int i = 1; i < n; i++)
    {
        if(people[i].h == people[i-1].h && people[i].b == people[i-1].b) people[i].d += people[i-1].d;
    }
    buildst(0, st_n, 1);
}

void update(vector<P> &buff)
{
    for(auto p:buff)
    {
        modify_if_greater(p.first, p.second, 0, st_n, 1);
    }
}

void process()
{
    ll mxdonate = 0;
    vector<P> buff;  // modify_if_greater(idx, v)
    int bef = people[0].h;
    for(int i = 0; i < n; i++)
    {
        if(people[i].h != bef) 
        {
            update(buff);
            buff.clear();
            bef = people[i].h;
        }
        ll mx = query(0, people[i].b-1, 0, st_n, 1);
        ll dp = mx + people[i].d;
        mxdonate = max(mxdonate, dp);
        buff.emplace_back(people[i].b, dp);
    }
    cout << mxdonate << endl;
}

