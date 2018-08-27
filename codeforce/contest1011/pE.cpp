//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 100005;

ll n, k;
ll arr[N];

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
    cin >> n >> k;
    for(int i = 0; i < n; i++) 
    {
        cin >> arr[i];
        arr[i] = arr[i]%k;
    }
}

void process()
{
    ll g = arr[0];
    for(int i = 1; i < n; i++) g = __gcd(g, arr[i]);
    set<ll> myset;
    for(int i = 0; i < k; i++) myset.insert(g*i%k);
    cout << myset.size() << endl;
    for(auto x:myset) cout << x << " "; cout << endl;
}

