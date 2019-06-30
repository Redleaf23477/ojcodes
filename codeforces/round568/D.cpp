//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;
typedef pair<ll, int> P;
#define val first
#define idx second

int n;
vector<P> arr;

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
        cin >> arr[i].val;
        arr[i].idx = i;
    }
    sort(arr.begin(), arr.end());
}

void process()
{
    // case 0 : n = 2
    if(n == 2)
    {
        cout << 1 << endl; return;
    }

    // case 1 : kill a1
    bool case1 = true;
    ll d1 = arr[2].val-arr[1].val;
    for(int i = 3; i < n && case1; i++)
    {
        if(arr[i].val-arr[i-1].val != d1) case1 = false;
    }
    if(case1)
    {
        cout << arr[0].idx+1 << endl; return;
    }

    // case 2 : kill a2
    bool case2 = true;
    ll d2 = arr[2].val-arr[0].val;
    for(int i = 3; i < n && case2; i++)
    {
        if(arr[i].val-arr[i-1].val != d2) case2 = false;
    }
    if(case2)
    {
        cout << arr[1].idx+1 << endl; return;
    }

    // case 3
    bool case3 = true;
    ll idx = -1;
    ll d3 = arr[1].val-arr[0].val;
    for(int i = 2; i < n && case3; i++)
    {
        if(idx == -1)
        {
            if(arr[i].val-arr[i-1].val != d3) idx = i;
        }
        else if(idx != -1)
        {
            if(i-1 == idx && arr[i].val-arr[i-2].val != d3) case3 = false;
            if(i-1 != idx && arr[i].val-arr[i-1].val != d3) case3 = false;
        }
    }
    if(case3)
    {
        if(idx == -1) cout << arr[0].idx+1 << endl;
        else cout << arr[idx].idx+1 << endl;
        return;
    }
    cout << -1 << endl;
}

