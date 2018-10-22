//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 300005;
const int C = 101;

int n, q;
int color[N];
vector<int> G[N];
int tim, inTime[N], outTime[N], t[N];

bitset<C> st[4*N];

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

void dfs(int x)
{
    inTime[x] = ++tim;
    t[tim] = x;
    for(auto c:G[x])
        dfs(c);
    outTime[x] = tim;
}

void buildst(int l, int r, int idx)
{
    if(l == r)
    {
        st[idx][color[t[l]]] = true;
        return;
    }
    int mid = l+(r-l)/2, lson = idx*2, rson = idx*2+1;
    buildst(l, mid, lson);
    buildst(mid+1, r, rson);
    st[idx] = st[lson]^st[rson];
}

bitset<C> query(int l, int r, int idx, int L, int R)
{
    if(r < L || R < l) return bitset<C>();
    if(L <= l && r <= R) return st[idx];
    int mid = l+(r-l)/2, lson = idx*2, rson = idx*2+1;
    return query(l, mid, lson, L, R) ^ query(mid+1, r, rson, L, R);
}

void modify(int l, int r, int idx, int pos, int val)
{
    if(r < pos || pos < l) return;
    if(l == pos && r == pos)
    {
//        st[idx][color[t[l]]] = false;
//        color[t[l]] = val;
//        st[idx][color[t[l]]] = true;
        st[idx].reset();
        st[idx][val] = true;
        return;
    }
    int mid = l+(r-l)/2, lson = idx*2, rson = idx*2+1;
    modify(l, mid, lson, pos, val);
    modify(mid+1, r, rson, pos, val);
    st[idx] = st[lson] ^ st[rson];
}

void init()
{
    cin >> n >> q;
    tim = 0;
    for(int i = 1; i <= n; i++) cin >> color[i];
    for(int c = 2, p; c <= n; c++) 
    {
        cin >> p;
        G[p].push_back(c);
    }
    dfs(1);
    // for(int i = 1; i <= n; i++) cout << i << " : " << inTime[i] << " " << outTime[i] << " " << t[inTime[i]] << endl;
    buildst(1, n, 1);
}

void process()
{
    while(q--)
    {
        int k, x; cin >> k >> x;
        if(k == 0) // query
        {
            cout << query(1, n, 1, inTime[x], outTime[x]).count() << endl;
        }
        else       // modify
        {
            modify(1, n, 1, inTime[x], k);
        }
    }
}

