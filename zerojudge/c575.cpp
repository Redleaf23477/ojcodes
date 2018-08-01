// apcs 1060304 基地台
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

void init();
void process();

const int N = 50005;
int n, k;
int arr[N];

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
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
}

bool ok(int len)
{
    int cnt = 0;
    for(int i = 0, ed = -1; i < n; i++)
    {
        if(arr[i] > ed) cnt++, ed = arr[i]+len;
    }
    return cnt <= k;
}

void process()
{
    int low = 0, high = arr[n-1]-arr[0], mid, ans = high;
    while(low <= high)
    {
        mid = low+(high-low)/2;
        if(ok(mid)) ans = mid, high = mid-1;
        else low = mid+1;
    }
    cout << ans << endl;
}

