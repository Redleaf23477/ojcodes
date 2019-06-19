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
    ll x, a, b, c; cin >> x;
    a = 1, b = 1, c = x-2;
    if(c%3 == 0) b++, c-=1;
    cout << a << " " << b << " " << c << endl;
}

