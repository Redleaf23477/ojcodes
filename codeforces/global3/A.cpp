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
    process();
    cout.flush();
    return 0;
}

void init()
{
}

void process()
{
    ll a, b, c; cin >> a >> b >> c;
    cout << 2*(c+min(a,b))+(a==b? 0:1) << endl;
}

