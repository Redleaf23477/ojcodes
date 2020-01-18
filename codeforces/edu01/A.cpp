//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

ll x;

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
    cin >> x;
}

void process()
{
    ll sum = (1+x)*x/2;
    for(ll pw = 1; pw <= x; pw *= 2)
    {
        sum -= 2*pw;
    }
    cout << sum << endl;
}

