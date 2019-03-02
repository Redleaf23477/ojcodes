//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

void init();
void process();

int32_t main()
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
    int n; cin >> n;
    int pos = 0, neg = 0;
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x; 
        if(x > 0) pos++;
        if(x < 0) neg++;
    }
    if(pos >= (n+1)/2) cout << 712 << endl;
    else if(neg >= (n+1)/2) cout << -712 << endl;
    else cout << 0 << endl;
}

