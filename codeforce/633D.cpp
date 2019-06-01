//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

const ll M = 104729;
const ll MV = 1e18;

ll n;
vector<ll> arr;
map<ll, ll> myhash[M];

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
    arr.resize(n);
    for(int i = 0; i < n; i++) 
    {
        cin >> arr[i];
        arr[i] += MV;
        if(myhash[arr[i]%M].count(arr[i]) == 0) myhash[arr[i]%M][arr[i]] = 0;
        myhash[arr[i]%M][arr[i]]++;
    }
}

ll run(ll f1, ll f2)
{
    vector<ll> seq = {f1, f2};
    myhash[f1%M][f1]--, myhash[f2%M][f2]--;
    ll nxt = f1 + f2 - MV;
    while(myhash[nxt%M].count(nxt) != 0 && myhash[nxt%M][nxt] > 0)
    {
        myhash[nxt%M][nxt]--;
        seq.emplace_back(nxt);
        nxt = seq[seq.size()-2] + seq[seq.size()-1] - MV;
    }
    for(auto x:seq) myhash[x%M][x]++;
    return seq.size();
}

void process()
{
    ll ans = 1;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            if(i == j) continue;
            if(arr[i] == MV && arr[j] == MV) 
                ans = max(ans, myhash[MV%M][MV]);
            else
                ans = max(ans, run(arr[i], arr[j]));
        }
    cout << ans << endl;
}

