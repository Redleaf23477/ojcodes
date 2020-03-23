// by redleaf23477
#include <bits/stdc++.h>

// iostream macros
#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
// chrono macros
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()
#define chrono_rand_seed chrono_now.time_since_epoch().count()

using namespace std;
using ll = long long int;

map<int,int> pf2idx;
bool has1, hasxx;
int n;
vector<ll> arr;

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
    cin >> n;
    has1 = hasxx = false;
    set<ll> s;
    for(int i = 0; i < n; i++)
    {
        ll x; cin >> x;
    }
}

void solve()
{
}

void process()
{
    if(has1) { cout << 1 << endl; return; }
    else if(hasxx) { cout << 2 << endl; return; }
    else solve();
}

