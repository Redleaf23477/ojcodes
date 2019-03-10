//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const int N = 400005;
const int INF = 1<<30;

int n;
int arr[N];
int mnpos[N];
vector<int> pos[N];

P st[4*N];

void buildst(int l, int r, int idx)
{
    st[idx] = P(INF, INF);
    if(l == r) return;
    int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;
    buildst(l, mid, lson);
    buildst(mid+1, r, rson);
}

void modify(int l, int r, int idx, int x, int v)
{
    if(x < l || r < x) return;
    if(l == x && x == r)
    {
        st[idx].first = v; return;
    }
    int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;
    modify(l, mid, lson, x, v);
    modify(mid+1, r, rson, x, v);

    int tmp[4] = { st[lson].first, st[lson].second, st[rson].first, st[rson].second };
    sort(tmp, tmp+4);
    st[idx].first = tmp[0], st[idx].second = INF;
    for(int i = 1; i < 3; i++)
    {
        if(tmp[i] == tmp[0]) continue;
        st[idx].second = tmp[i]; break;
    }
}

P query(int l, int r, int idx, int L, int R)
{
    if(r < L || R < l) return P(INF, INF);
    if(L <= l && r <= R) return st[idx];
    int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;

    P lqry = query(l, mid, lson, L, R);
    P rqry = query(mid+1, r, rson, L, R);

    int tmp[4] = { lqry.first, lqry.second, rqry.first, rqry.second };
    sort(tmp, tmp+4);
    P ret(tmp[0], INF);
    for(int i = 1; i < 3; i++)
    {
        if(tmp[i] == tmp[0]) continue;
        ret.second = tmp[i]; break;
    }
    return ret;
}

/////////////////////////

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
    cin >> n;
    for(int i = 0; i <= n; i++) mnpos[i] = INF;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        pos[arr[i]].emplace_back(i);
        if(mnpos[arr[i]] == INF) mnpos[arr[i]] = i;
    }
    buildst(0, n, 1);
}

void process()
{
    vector<bool> vis(n+1);
    vis[arr[n-1]] = true;
    for(auto x:pos[arr[n-1]]) modify(0, n, 1, x, arr[n-1]);

    pair<int, int> ans(INF, INF);
    for(int i = n-2; i > 0; i--)
    {
        int l = mnpos[arr[i]]+1, r = i-1;
        if(l <= r)
        {
            P qry = query(0, n, 1, l, r);
            if(qry.first != INF)
            {
                if(qry.first != arr[i]) ans = min(ans, P(arr[i], qry.first));
                else if(qry.second != INF)  ans = min(ans, P(arr[i], qry.second));
            }
        }
        if(!vis[arr[i]]) 
        {
            for(auto x:pos[arr[i]]) modify(0, n, 1, x, arr[i]);
            vis[arr[i]] = true;
        }
    }
    
    if(ans.first == INF) cout << -1 << endl;
    else cout << ans.first << " " << ans.second << endl;
}

