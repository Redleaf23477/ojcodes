//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 250005;
const int SQN = sqrt(N);

int n, q, sqn;
ll small[SQN][SQN];
ll large[N];

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    init();
    process();
    cout.flush();
    return 0;
}

void init()
{
    cin >> n >> q;
    sqn = sqrt(n);
    memset(small, 0, sizeof(small));
    memset(large, 0, sizeof(large));
}

void process()
{
    int cmd;
    while(q--)
    {
        cin >> cmd;
        if(cmd == 1)
        {
            int a, b, c; cin >> a >> b >> c;
            if(b <= sqn)
            {
                small[b][a] += c;
            }
            else
            {
                for(int i = a; i <= n; i+=b)
                    large[i] += c;
            }
        }
        else 
        {
            int x; cin >> x;
            ll ans = 0;
            for(int i = 1; i <= sqn; i++)
                ans += small[i][x%i];
            ans += large[x];
            cout << ans << endl;
        }
    }
}

