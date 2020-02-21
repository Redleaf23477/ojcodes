// by redleaf23477
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"

using namespace std;
using ll = long long int;

string a, b, c;

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
    cin >> a >> b >> c;
}

void process()
{
    int n = a.size();
    bool good = true;
    for(int i = 0; i < n; i++)
    {
        char ca = a[i], cb = b[i], cc = c[i];
        if(ca == cb && cb != cc) good = false;
        if(ca != cb && cb != cc && ca != cc) good = false;
    }
    if(good) cout << "YES" << endl;
    else cout << "NO" << endl;
}

