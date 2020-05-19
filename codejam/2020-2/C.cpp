// by redleaf23477
// small
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

int n;
vector<P> arr;

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    for(int t = 1; t <= T; t++)
    {
        cout << "Case #" << t << ": ";
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init()
{
    cin >> n;
    arr.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].x >> arr[i].y;
    }
}

ll run(vector<int> &ord)
{
    ll cnt = 4;
    ll dx = arr[ord[2]].x - arr[ord[1]].x;
    ll dy = arr[ord[2]].y - arr[ord[1]].y;
    ll g = __gcd(dx, dy);
    P dir(dx/g, dy/g);
    for(int i = 4; i < n; i++)
    {
        dx = arr[ord[i]].x - arr[ord[i-1]].x;
        dy = arr[ord[i]].y - arr[ord[i-1]].y;
        g = __gcd(dx, dy);
        if(dir.x == dx/g && dir.y == dy/g) cnt++;
        else break;
    }
    return cnt;
}

void process()
{
    if(n <= 3)
    {
        cout << n << endl; return;
    }
    ll ans = 0;
    vector<int> tmp(n);
    for(int i = 0; i < n; i++) tmp[i] = i;
    do
    {
        ans = max(run(tmp), ans);
    } while(next_permutation(tmp.begin(), tmp.end()));
    cout << ans << endl;
}

