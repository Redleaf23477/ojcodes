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
vector<vector<int>> seg;
vector<set<int>> occur;

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
    seg.clear(), occur.clear();
    occur.resize(n+1);
    for(int i = 1; i < n; i++)
    {
        vector<int> tmp;
        int x; cin >> x; tmp.resize(x);
        for(auto &y : tmp)
        {
            cin >> y;
            occur[y].insert(seg.size());
        }
        seg.push_back(tmp);
    }
}

void process()
{
    vector<int> ans;
    vector<bool> used(n+1, false);
    for(int i = n-1; i > 0; i--)
    {
        // find back
        int bk = -1;
        for(int x = 1; x <= n; x++)
        {
            if(!used[x] && occur[x].size() == 1)
            {
                bk = x; break;
            }
        }
        ans.push_back(bk);
        used[bk] = true;
        // clean up
        int idx = *occur[bk].begin();
        for(auto x : seg[idx])
        {
            occur[x].erase(idx);
        }
    }
    for(int i = 1; i <= n; i++) 
    {
        if(!used[i])
        {
            ans.push_back(i); break;
        }
    }
    reverse(ans.begin(), ans.end());
    for(auto x : ans) cout << x << " ";
    cout << endl;
}

