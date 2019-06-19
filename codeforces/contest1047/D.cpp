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
    ll n, m, ans = 0; cin >> n >> m;
    ans += n/6*3*m;
    n %= 6;
    cout << ans << endl;
}

