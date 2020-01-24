//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

ll n;

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
}

void process()
{
    double sum = 0;
    for(ll i = n; i > 0; i--)
    {
        sum += 1.0/(double)i;
    }
    cout << fixed << setprecision(10) << sum << endl;
}

