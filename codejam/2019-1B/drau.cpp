//
#include <bits/stdc++.h>

#define int ll
using namespace std;
typedef long long ll;

int w;
int d[10];

void init();
void process();

int32_t main()
{
    int T; cin >> T >> w;
    while(T--)
    {
        init();
        process();
    }
    return 0;
}

void init()
{
    cout << 220 << endl;
    cin >> d[0];
    cout << 56 << endl;
    cin >> d[1];
}

struct Node
{
    ll r1, r2, r3;
};

Node solve(ll qry, vector<ll> coff)
{
    for(ll x = 0; x <= 100; x++)
        for(ll y = 0; y <= 100; y++)
            for(ll z = 0; z <= 100; z++)
            {
                if(coff[0]*x + coff[1]*y + coff[2]*z == qry) return (Node){x, y, z};
            }
    return (Node){-1, -1, -1};
}

void process()
{
    Node nd220 = solve(d[0]>>36, {1<<19, 1<<8, 1});
    Node nd56 = solve((d[1]-(nd220.r1<<14)-(nd220.r2<<11)-(nd220.r3<<9))>>18, {1ll<<38, 1<<10, 1});
//    Node nd56 = solve(((d[1]-(nd220.r1<<14)-(nd220.r2<<11)-(nd220.r3<<9))%(1ll<<63)+(1ll<<63))%(1ll<<63))>>18, {1ll<<38, 1<<10, 1});

    cout << nd56.r1 << " " << nd56.r2 << " " << nd56.r3 << " " << nd220.r1 << " " << nd220.r2 << " " << nd220.r3 << endl;
    int x; cin >> x;
    assert(x==1);
}

