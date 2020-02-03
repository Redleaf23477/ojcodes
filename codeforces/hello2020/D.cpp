// by redleaf23477
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"

using namespace std;
using ll = long long int;
using P = pair<ll,ll>;
#define t first
#define idx second

int n;
ll a_max_t, b_max_t;
vector<P> a_start, a_end;
vector<P> b_start, b_end;

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
    cin >> n;
    set<ll> a_set, b_set;
    for(int i = 1; i <= n; i++)
    {
        ll as, ae, bs, be; cin >> as >> ae >> bs >> be;
        ae++, be++;
        a_start.emplace_back(as, i);
        a_end.emplace_back(ae, i);
        b_start.emplace_back(bs, i);
        b_end.emplace_back(be, i);
        a_set.insert(as), a_set.insert(ae);
        b_set.insert(bs), b_set.insert(be);
    }
    ll aidx = 0, bidx = 0;
    map<ll,ll> a_map, b_map;
    for(auto a : a_set) a_map[a] = aidx++;
    for(auto b : b_set) b_map[b] = bidx++;
    for(auto &a : a_start) a.t = a_map[a.t];
    for(auto &a : a_end) a.t = a_map[a.t];
    for(auto &b : b_start) b.t = b_map[b.t];
    for(auto &b : b_end) b.t = b_map[b.t];
    a_max_t = aidx-1, b_max_t = bidx-1;
    /*
    for(auto a : a_start) cout << a.idx << " => " << a.t << endl;
    for(auto a : a_end) cout << a.idx << " => " << a.t << endl;
    for(auto b : b_start) cout << b.idx << " => " << b.t << endl;
    for(auto b : b_end) cout << b.idx << " => " << b.t << endl;
    */
}

void process()
{
    bool happy = true;
    multiset<ll> a_graph;
    // build a
    sort(a_start.begin(), a_start.end());
    sort(a_end.begin(), a_end.end());
    ll ts = 0;
    int prev = -1;  // -1 : no op, 0 : push, 1 : pop
    for(ll t = 0, i = 0, j = 0; t <= a_max_t; t++)
    {
        if(j < n && a_end[j].t == t && prev == 0 && ts != 0)
            a_graph.insert(ts);
        while(j < n && a_end[j].t == t)
            ts ^= a_end[j++].idx, prev = 1;
        while(i < n && a_start[i].t == t) 
            ts ^= a_start[i++].idx, prev = 0;
    }
    /*
    cout << "a_graph" << endl;
    for(auto x : a_graph) cout << x << endl;
    cout << "b_graph" << endl;
    */
    // run b
    sort(b_start.begin(), b_start.end());
    sort(b_end.begin(), b_end.end());
    ts = 0, prev = -1;
    for(ll t = 0, i = 0, j = 0; t <= b_max_t && happy; t++)
    {
        if(j < n && b_end[j].t == t && prev == 0 && ts != 0)
        {
//            cout << ts << endl;
            auto it = a_graph.find(ts);
            if(it == a_graph.end())
                happy = false;
            else
                a_graph.erase(it);
        }
        while(j < n && b_end[j].t == t)
            ts ^= b_end[j++].idx, prev = 1;
        while(i < n && b_start[i].t == t) 
            ts ^= b_start[i++].idx, prev = 0;
    }
    if(happy && a_graph.empty()) cout << "YES" << endl;
    else cout << "NO" << endl;
}

