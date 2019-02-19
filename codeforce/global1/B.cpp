//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

const int N = 100005;

int n, len, k;
int arr[N];

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
    cin >> n >> len >> k;
    for(int i = 0; i < n; i++) cin >> arr[i];
}

void process()
{
    vector<int> dist;
    for(int i = 1; i < n; i++) dist.push_back(arr[i]-arr[i-1]-1);
    sort(dist.begin(), dist.end());
    ll tot = n;
    for(int i = 0; i < n-k; i++)
    {
        tot += dist[i];
    }
    cout << tot << endl;
}

