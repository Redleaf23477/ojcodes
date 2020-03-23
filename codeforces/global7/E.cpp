// by redleaf23477
#include <bits/stdc++.h>

// iostream macros
#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
// chrono macros
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()
#define chrono_rand_seed chrono_now.time_since_epoch().count()

using namespace std;
using ll = long long int;

struct Seg1D
{
    int st[4*300005];
    void build(int l, int r, int idx, vector<int> &arr)
    {
        if(l == r) 
        {
            st[idx] = arr[l]; return;
        }
        int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;
        build(l, mid, lson, arr);
        build(mid+1, r, rson, arr);
        st[idx] = min(st[lson], st[rson]);
    }
    void modify(int l, int r, int idx, int x, int v)
    {
        if(x < l || r < x) return;
        if(x == l && r == x) 
        {
            st[idx] = v; return;
        }
        int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;
        modify(l, mid, lson, x, v);
        modify(mid+1, r, rson, x, v);
        st[idx] = min(st[lson], st[rson]);
    }
    int query(int l, int r, int idx, int L, int R)
    {
        if(r < L || R < l) return 600005;
        else if(L <= l && r <= R) return st[idx];
        int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;
        return min(query(l, mid, lson, L, R), query(mid+1, r, rson, L, R));
    }
};

int n;
vector<int> arr, bomb, pos;
Seg1D st;


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
    arr.resize(n);
    bomb.resize(n);
    pos.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i]; arr[i]--;
        pos[arr[i]] = i;
    }
    for(int i = 0; i < n; i++)
    {
        cin >> bomb[i]; bomb[i]--;
    }
    st.build(0, n-1, 1, bomb);
}

int bs(int num)
{
    int low = 0, high = n-1, mid, ans = n;
    while(low <= high)
    {
        mid = (low+high)/2;
        cerr << var(mid) << " => " << st.query(0, n-1, 1, mid, n-1) << endl;
        if(st.query(0, n-1, 1, mid, n-1) <= pos[num]) high = mid-1, ans = mid;
        else low = mid+1;
    }
    return ans;
}

void process()
{
    vector<int> tmp(n+1, 0);
    for(int i = n-1; i >= 0; i--)
    {
        int lastAlive = bs(i);
        cerr << var(i) << var(lastAlive) << endl; cerr.flush();
        if(lastAlive != n) st.modify(0, n-1, 1, lastAlive, n+2);
        tmp[lastAlive] = max(tmp[lastAlive], i);
    }
    for(int i = n-1; i >= 0; i--) tmp[i] = max(tmp[i+1], tmp[i]);
    for(int i = 0; i < n; i++) cout << tmp[i]+1 << " ";
    cout << endl;
}

