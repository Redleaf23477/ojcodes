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

void init();
void process();

const LL P = 1000000;
vector<LL> sp, primes;

void build_sp()
{
    sp.resize(P);
    iota(sp.begin(), sp.end(), 0);
    for(LL i = 2; i*i < P; i++)
    {
        if(sp[i] != i) continue;
        for(LL j = i*i; j < P; j+=i)
            if(sp[j] == j) sp[j] = i;
    }
    for(LL i = 2; i < P; i++)
        if(sp[i] == i)
            primes.emplace_back(i);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    LL T; cin >> T;
    build_sp();
    for(LL t = 1; t <= T; t++)
    {
        process();
    }
    cout.flush();
    return 0;
}

map<LL,LL> de_fac(LL n)
{
    map<LL,LL> fac;
    // n >= P
    for(LL i = 0; i < (LL)primes.size() && n >= P; i++)
    {
        LL p = primes[i];
        if(n%p == 0) fac[p] = 0;
        while(n%p == 0) fac[p]++, n/=p;
    }
    // n < P
    if(n < P)
    {
        while(n > 1)
        {
            LL p = sp[n];
            if(fac.count(p) == 0) fac[p] = 0;
            fac[p]++; n /= p;
        }
    }
    else
    {
        fac[n] = 1;
    }
    return fac;
}

LL get_sp(LL n)
{
    if(n < P) return sp[n];
    for(LL i = 0; i < (LL)primes.size() && n >= P; i++)
    {
        LL p = primes[i];
        if(n%p == 0) return p;
    }
    return -1; // unreachable
}

void process()
{
    LL n; cin >> n;
    map<LL,LL> fac = de_fac(n);
    
    /*
    cerr << "fac(n) = ";
    for(auto [x,p] : fac) cerr << "(" << x << "^" << p << ") ";
    cerr << endl;
    */
    
    if(fac.size() == 1)
    {
        auto [x,p] = *fac.begin();
        for(LL i = 1, val = x; i <= p; i++, val *= x) cout << val << " ";
        cout << endl;
        cout << 0 << endl;
        return;
    }
    else if(fac.size() == 2)
    {
        vector<pair<LL,LL>> tmp;
        for(auto p : fac) tmp.emplace_back(p);
        if(max(tmp[0].second, tmp[1].second) == 1)
        {
            cout << tmp[0].first << " " << tmp[0].first*tmp[1].first << " " << tmp[1].first << endl;
            cout << 1 << endl;
            return;
        }
    }
    // init cycle
    vector<vector<LL>> ans;
    map<LL,LL> mp;
    set<LL> init_used { 1, n }; // treat 1 as special case
    for(auto [x, p] : fac) 
    {
        mp[x] = ans.size();
        ans.push_back(vector<LL>(1, x));
        init_used.insert(x);
    }
    for(LL i = 0; i < (LL)ans.size(); i++)
    {
        LL nxt = (i+1) % ans.size();
        LL mul = ans[i][0] * ans[nxt][0];
        if(init_used.count(mul) != 0) continue;
        init_used.insert(mul);
        ans[i].push_back(mul);
    }
    ans.back().push_back(n);
    // enum all divisor
    vector<vector<LL>> ans2(ans.size());
    for(LL i = 1; i*i <= n; i++)
    {
        if(n % i == 0)
        {
            LL a = i, b = n/i;
            if(init_used.count(a) == 0)
            {
                LL idx = mp[get_sp(a)];
                ans2[idx].emplace_back(a);
            }
            if(b != a && init_used.count(b) == 0)
            {
                LL idx = mp[get_sp(b)];
                ans2[idx].emplace_back(b);
            }
        }
    }
    // print
    for(int i = 0; i < (int) ans.size(); i++)
    {
        cout << ans[i][0] << " ";
        for(auto x : ans2[i]) cout << x << " ";
        for(int j = 1; j < (int)ans[i].size(); j++) cout << ans[i][j] << " ";
    }
    cout << endl;
    cout << 0 << endl;
}

