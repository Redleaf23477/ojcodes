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
    arr.resize(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
}

void process()
{
    bool odd = false, even = false;
    for(int i = 0; i < n; i++) 
    {
        if(arr[i]%2 == 0) even = true;
        else odd = true;
    }
    if(odd && even) sort(arr.begin(), arr.end());
    for(auto x:arr) cout << x << " ";
    cout << endl;
}

