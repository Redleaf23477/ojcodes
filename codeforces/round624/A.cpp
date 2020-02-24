#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long int;

ll a, b;

void init()
{
    cin >> a >> b;
}

void process()
{
    ll diff = b-a;
    if(diff == 0) cout << 0 << endl;
    else if(diff > 0)
    {
        if(diff%2 == 1) cout << 1 << endl;
        else if(diff == 1) cout << 3 << endl;
        else cout << 2 << endl; 
    }
    else
    {
        if(diff%2 == 0) cout << 1 << endl;
        else cout << 2 << endl;
    }
    
}

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
}