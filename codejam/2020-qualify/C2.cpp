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
using P = pair<int,int>;

struct Event
{
    int first, second, idx;
};

bool operator < (const Event &lhs, const Event &rhs)
{
    if(lhs.first != rhs.first) return lhs.first < rhs.first;
    else return lhs.second < rhs.second;
}

int n;
vector<Event> arr;

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
        cin >> arr[i].first >> arr[i].second;
        arr[i].idx = i;
    }
    sort(arr.begin(), arr.end());
}

void process()
{
    P p(0, 0);
    string ans(n, 'x');
    bool good = true;
    for(auto x : arr)
    {
        if(p.first <= x.first) { p.first = x.second; ans[x.idx] = 'C'; }
        else if(p.second <= x.first) { p.second = x.second; ans[x.idx] = 'J'; }
        else { good = false; break; }
    }
    if(good) cout << ans << endl;
    else cout << "IMPOSSIBLE" << endl;
}

