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
vector<string> pre, suf, mid;

bool cmp(const string &lhs, const string &rhs)
{
    return lhs.size() > rhs.size();
}

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
    pre.resize(n);
    suf.resize(n); 
    mid.resize(n);
    for(int i = 0; i < n; i++)
    {
        pre[i].clear();
        mid[i].clear();
        suf[i].clear();
    }
    for(int i = 0; i < n; i++)
    {
        string str, &p = pre[i], &m = mid[i], &s = suf[i]; cin >> str;
        int l = 0, r = str.size()-1;
        while(str[l] != '*')
        {
            p.push_back(str[l]);
            l++;
        }
        while(str[r] != '*')
        {
            s.push_back(str[r]);
            r--;
        }
        for(int j = l+1; j < r; j++)
        {
            if(str[j] == '*') continue;
            m.push_back(str[j]);
        }
    }
    sort(pre.begin(), pre.end(), cmp);
    sort(suf.begin(), suf.end(), cmp);
    /*
    cout << endl;
    for(int i = 0;i < n; i++)
    {
        cout << pre[i] << "+" << mid[i] << "+" << suf[i] << endl;
    }
    */
}

bool ok()
{
    for(int i = 1; i < n; i++)
    {
        for(size_t j = 0; j < pre[i].size(); j++)
            if(pre[i][j] != pre[0][j]) return false;
        for(size_t j = 0; j < suf[i].size(); j++)
            if(suf[i][j] != suf[0][j]) return false;
    }
    return true;
}

void process()
{
    if(!ok()) cout << "*" << endl;
    else
    {
        cout << pre[0];
        for(auto x : mid) cout << x;
        reverse(suf[0].begin(), suf[0].end());
        cout << suf[0];
        cout << endl;
    }
}
