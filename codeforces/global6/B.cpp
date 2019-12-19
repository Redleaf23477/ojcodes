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

bool good()
{
    if(x <= 14) return false;
    for(int i = 1; i <= 6; i++)
    {
        if((x-i)%14 == 0) return true;
    }
    return false;
}

void process()
{
    if(good()) cout << "YES" << endl;
    else cout << "NO" << endl;
}

