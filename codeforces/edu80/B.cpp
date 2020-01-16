//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

ll a, b;

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
    cin >> a >> b;
}

void process()
{
    ll cnt = 0;
    for(ll x = 9, l = 1; x <= b; x = x*10+9, l++)
        cnt ++;
    cout << a * cnt << endl;
}

