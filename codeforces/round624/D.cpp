#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long int;

ll a, b, c;

void init()
{
    cin >> a >> b >> c;
}

void process()
{
    ll ans = 71227122;
    ll AA = -1, BB = -1, CC = -1;
    for(ll A = 1; A <= 10000; A++)
    {
        for(ll B = A; B <= 20000; B += A)
        {
            for(ll p = 0; p <= 1; p++)
            {
                ll C = c/B*B;
                if(C < B) C = B;
                if(p) C += B;
                ll tmp = abs(a-A) + abs(b-B) + abs(c-C);
                if(tmp < ans)
                {
                    ans = tmp;
                    AA = A, BB = B, CC = C;
                }
            }
        }
    }
    cout << ans << endl;
    cout << AA << " " << BB << " " << CC << endl;
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