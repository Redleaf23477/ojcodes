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
vector<int> per, pos, color;

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
    per.resize(n+1);
    pos.resize(n+1);
    color.resize(n+1);
    for(int i = 1; i <= n; i++) cin >> per[i];
    for(int i = 1; i <= n; i++) pos[per[i]] = i;
    for(int i = 1; i <= n; i++) cin >> color[i];
}

vector<vector<int>> getSubgroups()
{
    vector<vector<int>> sub;
    vector<bool> mark(n+1, false);
    vector<int> tmp;
    for(int i = 1; i <= n; i++)
    {
        if(mark[i] == true) continue;
        tmp.clear();
        int idx = i;
        while(mark[idx] == false)
        {
            mark[idx] = true;
            tmp.push_back(per[idx]);
            idx = per[idx];
        }
        sub.push_back(tmp);
    }
    return sub;
}

bool test(vector<int> &s, int k)
{
    int m = s.size();
    vector<bool> mark(m, false);
    for(int i = 0; i < m; i++)
    {
        if(mark[i]) continue;
        int c = color[pos[s[i]]];
        bool good = true;
        for(int j = i; mark[j] == false; j = (j+k)%m)
        {
            mark[j] = true;
            if(color[pos[s[j]]] != c) good = false;
        }
        if(good) return true;
    }
    return false;
}

void process()
{
    vector<vector<int>> subgroups = getSubgroups();
    /*
    for(auto s : subgroups)
    {
        for(auto x : s) cout << x << " ";
        cout << endl;
    }
    */
    int ans = n;
    for(auto s : subgroups)
    {
        int m = s.size();
        for(int k = 1; k*k <= m; k++)
        {
            if(m % k != 0) continue;
            if(test(s, k)) ans = min(ans, k);
            if(test(s, m/k)) ans = min(ans, m/k);
        }
    }
    cout << ans << endl;
}

