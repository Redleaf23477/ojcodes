//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

ll n, x;
vector<ll> d, h;

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
    cin >> n >> x;
    d.resize(n);
    h.resize(n);
    for(int i = 0; i < n; i++) cin >> d[i] >> h[i];
}

void process()
{
    ll best = 0, hurt = 0;
    for(int i = 0; i < n; i++)
    {
        best = max(best, d[i]-h[i]);
        hurt = max(hurt, d[i]);
    }
    if(hurt == 0) cout << -1 << endl;
    else if(hurt < x && best == 0) cout << -1 << endl;
    else if(hurt >= x) cout << 1 << endl;
    else cout << 1+(x-hurt)/best+((x-hurt)%best!=0) << endl;
}

