//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

int n;
vector<int> arr;

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
    n = 2*n;
    arr.resize(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
}

void process()
{
    bool allsame = true;
    for(int i = 1; i < n; i++) if(arr[i] != arr[i-1]) allsame = false;
    if(allsame == true) cout << -1 << endl;
    else 
    {
        for(auto x:arr) cout << x << " ";
        cout << endl;
    }
}
