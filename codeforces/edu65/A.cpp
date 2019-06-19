//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

int n;
string str;

void init();
void process();

int32_t main()
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
    cin >> str;
}

void process()
{
    size_t eight = str.find('8');
    if(eight == str.npos || n - eight < 11) cout << "NO" << endl;
    else cout << "YES" << endl;
}

