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
ll k;
vector<char> arr;

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
    cin >> n >> k;
    arr.resize(n);
    for(auto &x : arr) cin >> x;
}

pair<ll,ll> good(vector<vector<int>> &log)
{
    ll mn = 0, mx = 0;
    queue<int> pairs;  // right
    vector<int> tmp;
    for(int i = 1; i < n; i++)
    {
        if(arr[i] == 'L' && arr[i-1] == 'R')
        {
            pairs.push(i);
            tmp.push_back(i);
        }
    }
    if(!tmp.empty()) log.push_back(tmp);
    while(true)
    {
        mn++;
        vector<int> tmp;

        while(!pairs.empty())
        {
            mx++;
            int idx = pairs.front(); pairs.pop();
            arr[idx] = 'R', arr[idx-1] = 'L';
            if(idx-1 > 0 && arr[idx-2] == 'R') tmp.push_back(idx-1);
            if(idx+1 < n && arr[idx+1] == 'L') tmp.push_back(idx+1);
        }

        if(tmp.empty()) break;
        for(auto x : tmp) pairs.push(x);
        log.push_back(tmp);
    }
    return make_pair(mn, mx);
}

void process()
{
    vector<vector<int>> log;
    pair<ll,ll> valid = good(log);
    ll mn = valid.first, mx = valid.second;
    if(k < mn || mx < k)
    {
        cout << -1 << endl; return;
    }
    int i = 0;
    while(k != (int)log.size()-i)
    {
        cout << 1 << " " << log[i].back() << endl;
        log[i].pop_back();
        if(log[i].empty()) i++;
        k--;
    }
    while(i < (int)log.size())
    {
        cout << log[i].size() << " ";
        for(auto x : log[i]) cout << x << " ";
        cout << endl;
        i++;
    }
}

