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

void init()
{
}

ll getsum(vector<ll> &n)
{
    ll sum = 0;
    for(auto c : n) sum += c;
    return sum;
}

void carry(vector<ll> &n)
{
    for(int i = 0; i < (int)n.size()-1; i++)
    {
        if(n[i] >= 10) n[i+1] += n[i]/10, n[i]%=10;
    }
    if(n.back() >= 10)
    {
        ll x = n.back()/10;
        n.back() %= 10;
        n.push_back(x);
    }
}

vector<ll> str2int(string m)
{
    reverse(m.begin(), m.end());
    vector<ll> ans(m.size());
    for(int i = 0; i < (int)m.size(); i++)
        ans[i] = m[i]-'0';
    return ans;
}

string num(vector<ll> n)
{
    stringstream ss;
    for(auto x : n) ss << x;
    string t; ss >> t;
    reverse(t.begin(), t.end());
    return t;
}

void process()
{
    vector<ll> p10(20, 1); for(int i = 1; i < 20; i++) p10[i] = p10[i-1]*10;
    string m; ll s; cin >> m >> s;
    vector<ll> n = str2int(m);
    ll ans = 0;
    ll sum = getsum(n);
    int idx = 0;
    while(sum > s)
    {
        while(n[idx] == 0) idx++;
        ll step = 10 - n[idx];
        ans += step*p10[idx];
        n[idx] = 0;
        idx++;
        if(idx == (int)n.size()) n.push_back(0);
        n[idx]++; carry(n);
        sum = getsum(n);
    }
    cout << ans << endl;
}

