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

int n;
vector<int> arr;

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
    cin >> n;
    arr.resize(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
}

bool good(map<int,int> &l, map<int,int> &r)
{
    if(l.size() + r.size() != (size_t)n) return false;
    auto it = l.end(); it--;
    if(it->first != (int)l.size()) return false;
    if(l.begin()->first != 1) return false;
    it = r.end(); it--;
    if(it->first != (int)r.size()) return false;
    if(r.begin()->first != 1) return false;
    return true;
}

void process()
{
    map<int,int> l, r;
    for(auto x : arr)
    {
        if(r.count(x) == 0) r[x] = 0;
        r[x]++;
    }
    vector<pair<int,int>> ans;
    for(int i = 0; i < n; i++)
    {
        if(l.count(arr[i]) == 0) l[arr[i]] = 0;
        l[arr[i]]++;
        r[arr[i]]--;
        if(r[arr[i]] == 0) r.erase(arr[i]);
        if(good(l, r)) ans.emplace_back(l.size(), r.size());
    }
    cout << ans.size() << endl;
    for(auto x : ans) cout << x.first << " " << x.second << endl;
}

