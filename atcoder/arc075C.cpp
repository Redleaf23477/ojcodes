//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

const int N = 200005;

ll n, k;
ll arr[N];

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
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 1; i < n; i++) arr[i] += arr[i-1];
    for(int i = 0; i < n; i++) arr[i] -= (i+1)*k;
}

vector<int> tmp;
ll dc(int l, int r)
{
    if(l == r) return (arr[l] >= 0? 1 : 0);
    int mid = (l+r)/2;
    ll res = dc(l, mid) + dc(mid+1, r);
    tmp.clear();
    int i = l, j = mid+1;
    while(i <= mid && j <= r)
    {
        if(arr[i] <= arr[j]) res += r-j+1, tmp.push_back(arr[i++]);
        else tmp.push_back(arr[j++]);
    }
    while(i <= mid) tmp.push_back(arr[i++]);
    while(j <= r) tmp.push_back(arr[j++]);
    for(i = l, j = 0; i <= r; i++, j++) arr[i] = tmp[j];
    return res;
}

void process()
{
    cout << dc(0, n-1) << endl;
}

