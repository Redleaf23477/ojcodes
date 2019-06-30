//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

int d;
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
    for(int i = 0; i < 3; i++)
    {
        int x; cin >> x;
        arr.push_back(x);
    }
    cin >> d;
}

void process()
{
    sort(arr.begin(), arr.end());
    int ans = 0;
    if(arr[2]-arr[0] >= 2*d)
    {
        ans += (arr[1]-arr[0] < d)? d-(arr[1]-arr[0]) : 0;
        ans += (arr[2]-arr[1] < d)? d-(arr[2]-arr[1]) : 0;
    }
    else
    {
        ans += (arr[1]-arr[0] < d)? d-(arr[1]-arr[0]) : 0;
        ans += (arr[2]-arr[1] < d)? d-(arr[2]-arr[1]) : 0;
    }
    cout << ans << endl;
}

