//
#include <bits/stdc++.h>

//#define endl '\n'
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> P;
#define value first
#define delay second

struct Envelope
{
    ll start, stop, delay, value;
};
bool operator < (const Envelope &lhs, const Envelope &rhs)
{
    return lhs.value < rhs.value || (lhs.value == rhs.value && lhs.delay < rhs.delay);
}

struct Node
{
    ll value, delay;
    ll valueTag, delayTag;
};

const int N = 100005;
const int M = 202;
const int K = 100005;

int n, m, k;
Envelope env[K];
Node st[4*N];
ll dp[N][M];
map<int, P> mp;

void init();
void process();

void build_st(int l, int r, int idx)
{
    // build an empty st
    st[idx].value = st[idx].delay = 0;
    st[idx].valueTag = st[idx].delayTag = -1;
    if(l == r) return;
    int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;
    build_st(l, mid, lson);
    build_st(mid+1, r, rson);
}

void down(int idx, int lson, int rson)
{
    if(st[idx].valueTag != -1)
    {
        st[lson].valueTag = st[rson].valueTag = st[idx].valueTag;
    }
    if(st[idx].delayTag != -1)
    {
        st[lson].delayTag = st[rson].delayTag = st[idx].delayTag;
    }
    st[idx].value = st[idx].valueTag;
    st[idx].delay = st[idx].delayTag;
    st[idx].valueTag = st[idx].delayTag = -1;
}

void up(int idx, int lson, int rson)
{
    int lval = (st[lson].valueTag == -1)? st[lson].value : st[lson].valueTag;
    int ldel = (st[lson].delayTag == -1)? st[lson].delay : st[lson].delayTag;
    int rval = (st[rson].valueTag == -1)? st[rson].value : st[rson].valueTag;
    int rdel = (st[rson].delayTag == -1)? st[rson].delay : st[rson].delayTag;

    if(lval < rval || (lval == rval && ldel < rdel))
    {
        st[idx].value = rval;
        st[idx].delay = rdel;
    }
    else
    {
        st[idx].value = lval;
        st[idx].delay = ldel;
    }
}

void modify(int l, int r, int idx, int L, int R, ll val, ll del)
{
    if(r < L || R < l) return;
    if(L <= l && r <= R)
    {
        st[idx].valueTag = val;
        st[idx].delayTag = del;
        return;
    }
    int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;
    down(idx, lson, rson);
    modify(l, mid, lson, L, R, val, del);
    modify(mid+1, r, rson, L, R, val, del);
}

P query(int l, int r, int idx, int pos)
{
    if(mp.count(pos) != 0) return mp[pos];
    if(pos < l || r < pos) return make_pair(0, 0);
    if(l == pos && pos == r)
    {
        if(st[idx].valueTag != -1) return mp[pos] = make_pair(st[idx].valueTag, st[idx].delayTag);
        else return mp[pos] = make_pair(st[idx].value, st[idx].delay);
    }
    int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;
    down(idx, lson, rson);
    if(pos <= mid) return query(l, mid, lson, pos);
    else return query(mid+1, r, rson, pos);
}

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
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++)
    {
        cin >> env[i].start >> env[i].stop >> env[i].delay >> env[i].value;
    }
    sort(env, env+k);
    for(int i = 0; i < k; i++)
    {
        modify(0, n, 1, env[i].start, env[i].stop, env[i].value, env[i].delay);
    }
}

void process()
{
    // dp init:
    // dp[> n][for any d] = 0;
    // dp[for any n][0] = query;
    // init on startup
    for(int tim = n; tim >= 0; tim--)
    {
        // disrupt = 0
        {
            P q = query(0, n, 1, tim);
            if(q.value == 0) dp[tim][0] = dp[tim+1][0];
            else dp[tim][0] = dp[q.delay+1][0]+q.value;
        }
        for(int disrupt = 1; disrupt <= m; disrupt++)
        {
            P q = query(0, n, 1, tim);
            if(q.value == 0) dp[tim][disrupt] = dp[tim+1][disrupt];
            else dp[tim][disrupt] = min(dp[tim+1][disrupt-1], dp[q.delay+1][disrupt]+q.value);
        }
    }
    cout << dp[1][m] << endl;
/*
    for(int t = 1; t <= n; t++)
    {
        for(int d = 0; d <= m; d++)
            cout << dp[t][d] << " ";
        cout << endl;
    }
*/

}
