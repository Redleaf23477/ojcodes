// by redleaf23477
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"

using namespace std;
using ll = long long int;

ll n;

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
    cin >> n;
}

void process()
{
    if(n <= 1) 
    {
        cout << 0 << endl; return;
    }
    ll one = n/2;
    ll seven = n%2;
    if(seven == 1) one--;
    if(seven == 1) cout << 7;
    while(one--) cout << 1;
    cout << endl;
}

