//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;
typedef pair<int, ll> P;
#define vote first
#define cost second

const int N = 3030;
int n, m, cnt[N];
P arr[N];

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
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].vote >> arr[i].cost;
        cnt[arr[i].vote]++;
    }
}

bool ok()
{
    for(int i = 2; i <= m; i++)
    {
        if(cnt[i] >= cnt[1]) return false;
    }
    return true;
}

void process()
{
    ll tot = 0;
    while(!ok())
    {
        ll mxidx = -1, mx = (1ll<<60);
        for(int i = 0; i < n; i++)
        {
            if(arr[i].vote == 1) continue;
            int v = arr[i].vote;
            if(arr[i].cost < mx) mx = arr[i].cost, mxidx = i;
            if(cnt[v]-cnt[1] >= 1)
            {
                if(arr[i].cost <= mx*2) mx = arr[i].cost/2+(arr[i].cost%2 != 0), mxidx = i;
            }
        }
        cnt[arr[mxidx].vote]-=1, tot += arr[mxidx].cost, cnt[1]++, arr[mxidx].vote = 1;
    }
    cout << tot << endl;
}

