//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

ll str, smart, ex;

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
    cin >> str >> smart >> ex;
}

void process()
{
    // x <= ex
    // str+ex-x > smart+x
    // str+ex-smart > 2x
    // (str+ex-smart)/2 > x
    // x = 0 ~ min(ex, (str+ex-smart-1)/2)
    if(str+ex-smart <= 0) cout << 0 << endl;
    else
    {
        ll mx = (str+ex-smart-1)/2;
        mx = min(ex, mx);
        cout << max(0ll, mx+1) << endl;
    }
}

