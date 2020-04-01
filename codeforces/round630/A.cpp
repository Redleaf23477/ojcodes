// by redleaf23477
#include <bits/stdc++.h>

// iostream macros
#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
// chrono macros
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()
#define chrono_rand_seed chrono_now.time_since_epoch().count()
// random
std::mt19937_64 myrand(chrono_rand_seed);

using namespace std;
using ll = long long int;
using P = pair<ll,ll>;
#define x first
#define y second

int l, r, d, u;
P p, p1, p2;

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
    cin >> l >> r >> d >> u;
    cin >> p.x >> p.y >> p1.x >> p1.y >> p2.x >> p2.y;
}

bool good()
{
    if(p1.x == p2.x && (l != 0 || r != 0)) return false;
    if(p1.y == p2.y && (u != 0 || d != 0)) return false;
    l -= r, d -= u;
    p.x -= l, p.y -= d;
    return p1.x <= p.x && p.x <= p2.x && p1.y <= p.y && p.y <= p2.y;
}

void process()
{
    if(good()) cout << "YES" << endl;
    else cout << "NO" << endl;
}

