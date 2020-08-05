// by redleaf23477
#include <bits/stdc++.h>

// iostream macros
#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
// chrono macros
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()
#define chrono_rand_seed chrono_now.time_since_epoch().count()
// random
std::mt19937_64 myrand(chrono_rand_seed);

using namespace std;
using ll = long long int;

const int N = 500005;
const int LG_N = 14;

struct SparseTable1D
{
    int n;
    ll LG[N];
    ll st[N][LG_N+1];
    void buildLG()
    {
        LG[1] = 0;
        for(int i = 2; i <= n; i++)
            LG[i] = LG[i/2]+1;
    }
    void buildst(int _n, vector<ll> &arr)
    {
        n = _n;
        buildLG();
        for(int i = 0; i < n; i++)
            st[i][0] = arr[i];
        for(int lg = 0; lg < LG_N; lg++)
            for(int i = 0; i < n; i++)
            {
                st[i][lg+1] = -1;
                if(st[i][lg] != -1)
                    st[i][lg+1] = st[st[i][lg]][lg];
            }
        /*
        for(int i = 0; i < n; i++)
            for(int lg = 0; lg <= LG_N; lg++)
                cout << st[i][lg] << " \n"[lg==LG_N];
        */
    }
    ll query(int l, int r)
    {
        ll lg = LG[r-l+1];
        return max(st[l][lg], st[r-(1<<lg)+1][lg]);
    }
};

int n;
vector<ll> len;
SparseTable1D st;

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
    len.resize(2*n);
    for(int i = 0; i < n; i++) 
    {
        cin >> len[i];
        len[i+n] = len[i];
    }
    vector<ll> bestNeighbor(2*n);
    bestNeighbor[0] = -1;
    vector<int> stk {0};
    for(int i = 1; i < 2*n; i++)
    {
        // find
        int l = 0, r = stk.size()-1, mid, ans = -1;
        while(l <= r)
        {
            mid = (l+r)/2;
            if(i - len[i] <= stk[mid])
            {
                r = mid-1, ans = mid;
            }
            else
            {
                l = mid+1;
            }
        }
        assert(ans != -1);
        bestNeighbor[i] = stk[ans];
        /*
        cerr << "bestNeighbor:" << endl;
        cerr << var(i) << " => " << bestNeighbor[i] << endl;
        */
        // pop
        while(!stk.empty() && i - len[i] < stk.back() - len[stk.back()])
            stk.pop_back();
        // push
        stk.push_back(i);
    }
    st.buildst(2*n, bestNeighbor);
}

void process()
{
    ll ans = 0;
    for(int start = n, stop = 1; start < 2*n; start++, stop++)
    {
        ll cur = start, dist = 0;
        if(start - len[start] <= stop)
        {
            dist = 1;
        }
        else
        {
            for(int lg = LG_N; lg >= 0; lg--)
            {
                ll jp = st.st[cur][lg];
                if(jp == -1) continue;
                if(jp - len[jp] > stop)
                {
                    cur = jp;
                    dist += (1<<lg);
                }
            }
            // cur -> jp -> stop
            dist += 2;
        }
        ans += dist;
    }
    cout << ans << endl;
}

