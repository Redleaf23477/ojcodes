// by redleaf23477
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"

using namespace std;
using ll = long long int;

ll n;
vector<ll> arr;

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--)
    {
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init()
{
    cin >> n;
    arr.resize(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
}

bool allOdd()
{
    for(auto x : arr) if(x%2 == 0) return false;
    return true;
}

bool allEven()
{
    for(auto x : arr) if(x%2 == 1) return false;
    return true;
}

void process()
{
    if(allOdd() && n%2 == 0) cout << "NO" << endl;
    else if(allEven()) cout << "NO" << endl;
    else cout << "YES" << endl;
}

