//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

const int N = 1000006;
int n;
ll high[N], low[N];

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
    for(int i = 0; i < n; i++) 
    {
        cin >> high[i]; low[i] = high[i];
    }
}

ll dc(int l, int r)
{
    ll sum = 0;
    if(l == r) return 0;
    int mid = (l+r)/2;
    sum += dc(l, mid) + dc(mid+1, r);
    // high
    
    // low
}

void process()
{
    cout << dc(0, n-1) << endl;
}

