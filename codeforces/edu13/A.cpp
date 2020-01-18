//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

ll n, k;

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
}

void process()
{
    cout << k*(n/k+1) << endl;
}

