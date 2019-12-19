//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

int n;
vector<ll> arr;

void init();
void process();

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
    cin >> n;
    arr.resize(n);
    for(auto &x:arr) cin >> x;
    sort(arr.begin(), arr.end());
}

void process()
{
    ll small = 0, large = 0;
    for(int i = 0; i < n/2; i++) small += arr[i];
    for(int i = n/2; i < n; i++) large += arr[i];
    cout << small*small + large*large << endl;

}

