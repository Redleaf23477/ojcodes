// Tomioka has no friends
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long int;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--)
    {
        ll p, f; cin >> p >> f;
        if(p > f) swap(p, f);
        ll cs, cw; cin >> cs >> cw;
        ll s, w; cin >> s >> w;
        if(s > w) swap(s, w), swap(cs, cw);
        // p is smaller, s is smaller
        ll ans = 0;
        for(int i = 0; i*s <= p && i <= cs; i++)
        {
            ll tmp = i;
            ll pleft = p - i*s;
            ll p_w = min(cw, pleft/w);
            ll sleft = cs - i;
            ll wleft = cw - p_w; tmp += p_w;

            ll f_s = min(sleft, f/s); tmp += f_s;
            ll fleft = f - s*f_s;
            tmp += min(wleft, fleft/w);

            ans = max(tmp, ans);
        }
        cout << ans << endl;
    }
    cout.flush();
    return 0;
}

