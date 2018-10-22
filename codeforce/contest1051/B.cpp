//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    process();
    cout.flush();
    return 0;
}

void init()
{
}

void process()
{
    ll l, r; cin >> l >> r;
    cout << "YES" << endl;
    for(ll i = l; i <= r; i += 2)
    {
        cout << i << " " << i+1 << endl;
    }
}

