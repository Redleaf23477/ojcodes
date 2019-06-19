//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

void init();
void process();

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    init();
    cout.flush();
    return 0;
}

void init()
{
    int n; cin >> n;
    vector<int> arr(n);
    int mx = 0;
    for(int i = 0; i < n; i++) cin >> arr[i], mx = max(mx, arr[i]);
    int len = 0;
    int tmp = arr[0] == mx;
    for(int i = 1; i < n; i++)
    {
        if(arr[i] == mx && arr[i] == arr[i-1]) tmp++;
        else len = max(tmp, len), tmp = 1;
    }
    cout << max(len, tmp) << endl;
}

void process()
{
}

