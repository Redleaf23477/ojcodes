//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

struct Casher
{
    ll bitMx, scanTime, packTime;
};

ll robotNum, bitNum, casherNum;
vector<Casher> casher;

void init();
void process();

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T, caseN = 0; cin >> T;
    while(T--)
    {
        cout << "Case #" << ++caseN << ": ";
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init()
{
    cin >> robotNum >> bitNum >> casherNum;
    casher.resize(casherNum);
    for(int i = 0; i < casherNum; i++) 
        cin >> casher[i].bitMx >> casher[i].scanTime >> casher[i].packTime;
}

bool ok(ll tim)
{
    vector<int> quota(casherNum);
    for(int i = 0; i < casherNum; i++)
    {
        quota[i] = min(casher[i].bitMx, max(0ll, (tim-casher[i].packTime)/casher[i].scanTime));
    }
    sort(quota.begin(), quota.end(), greater<ll>());
    ll sum = 0;
    for(int i = 0; i < robotNum; i++) sum += quota[i];
    return sum >= bitNum;
}

void process()
{
    ll high = 2e18, low = 0, mid = -1, ans = -1;
    while(low <= high)
    {
        mid = low+(high-low)/2;
        if(ok(mid)) high = mid-1, ans = mid;
        else low = mid+1;
    }
    cout << ans << endl;
}

