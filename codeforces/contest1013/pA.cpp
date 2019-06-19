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
    int n; ll x = 0, y = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a; cin >> a; x += a;
    }
    for(int i = 0; i < n; i++)
    {
        int a; cin >> a; y += a;
    }
    cout << (x >= y? "Yes":"No") << endl;
}

