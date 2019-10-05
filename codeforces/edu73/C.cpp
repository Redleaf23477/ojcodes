//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

ll coder, math, n00b;

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
    cin >> coder >> math >> n00b;
}

bool ok(ll teamNum)
{
    return coder+math+n00b-2*teamNum >= teamNum;
}

void process()
{
    ll low = 0, high = min(coder,math), mid, ans = 0;
    while(low <= high)
    {
        mid = (low+high)/2;
        if(ok(mid)) ans = mid, low = mid+1;
        else high = mid-1;
    }
    cout << ans << endl;
}

