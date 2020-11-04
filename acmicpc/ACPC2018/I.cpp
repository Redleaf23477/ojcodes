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
using LL = long long int;

ifstream fin("icecream.in");
#define cin fin

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    for(int t = 1; t <= T; t++)
    {
        init();
        process();
    }
    cout.flush();
    return 0;
}

int n, k;
vector<pair<LL,LL>> arr;

void init()
{
    cin >> n >> k;
    arr.resize(n);
    for(int i = 0; i < n; i++) cin >> arr[i].first;
    for(int i = 0; i < n; i++) cin >> arr[i].second;
    sort(arr.begin(), arr.end());
}

void process()
{
    vector<LL> fat, knt;
    vector<vector<LL>> happy;
    for(int i = 0; i < n; i++)
    {
        if(fat.empty() || fat.back() != arr[i].first)
        {
            fat.emplace_back(arr[i].first);
            knt.emplace_back(0);
            happy.emplace_back(vector<LL>());
        }
        happy.back().emplace_back(arr[i].second);
        knt.back()++;
    }
    for(int i = 1; i < (int)knt.size(); i++)
        knt[i] += knt[i-1];
    int idx = lower_bound(knt.begin(), knt.end(), k) - knt.begin();
    vector<LL> h;
    for(int i = 0; i <= idx; i++)
        h.insert(h.end(), happy[i].begin(), happy[i].end());
    sort(h.begin(), h.end(), greater<LL>());
    cout << fat[idx] << " ";
    LL sum = 0;
    for(int i = 0; i < k; i++) sum += h[i];
    cout << sum << endl;
}
