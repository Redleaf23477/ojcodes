// by redleaf23477
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"

using namespace std;
using ll = long long int;

ll n;
vector<ll> arr;
vector<ll> fromLeft, fromRight;

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
    fromLeft.resize(n);
    fromRight.resize(n);
    for(auto &x : arr) cin >> x;
    for(int i = 0; i < n; i++) fromLeft[i] = (arr[i] >= i);
    for(int i = 1; i < n; i++) fromLeft[i] = fromLeft[i] && fromLeft[i-1];
    for(int i = n-1; i >= 0; i--) fromRight[i] = (arr[i] >= n-i-1);
    for(int i = n-2; i >= 0; i--) fromRight[i] = fromRight[i] && fromRight[i+1];
}

void process()
{
    bool good = false;
    for(int i = 0; i < n && !good; i++)
    {
        if(fromLeft[i] == true && fromRight[i] == true)
            good = true;
    }
    if(good) cout << "Yes" << endl;
    else cout << "No" << endl;
}

