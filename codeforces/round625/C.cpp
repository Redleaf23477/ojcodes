// by redleaf23477
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()

using namespace std;
using ll = long long int;

const int N = 200005;
const ll INF = 1e18;

struct SegTree
{
    ll val[4*N];  // max
    ll tag[4*N];  // add
    void up(int idx, int lson, int rson)
    {
        val[idx] = max(val[lson]+tag[lson], val[rson]+tag[rson]);
    }
    void down(int l, int r, int idx, int lson, int rson)
    {
        val[idx] += tag[idx];
        if(l != r)
        {
            tag[lson] += tag[idx];
            tag[rson] += tag[idx];
        }
        tag[idx] = 0;
    }
    void build(int l, int r, int idx, vector<pair<ll,ll>> &arr)
    {
        tag[idx] = 0;
        if(l == r)
        {
            val[idx] = -arr[l].second; return;
        }
        int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;
        build(l, mid, lson, arr);
        build(mid+1, r, rson, arr);
        up(idx, lson, rson);
    }
    void addTag(int l, int r, int idx, int L, int R, ll val)
    {
        if(r < L || R < l) return;
        if(L <= l && r <= R)
        {
            tag[idx] += val; return;
        }
        int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;
        down(l, r, idx, lson, rson);
        addTag(l, mid, lson, L, R, val);
        addTag(mid+1, r, rson, L, R, val);
        up(idx, lson, rson);
    }
    ll query(int l, int r, int idx, int L, int R)
    {
        if(r < L || R < l) return -INF;
        if(L <= l && r <= R) return val[idx]+tag[idx];
        int mid = (l+r)/2, lson = idx*2, rson = idx*2+1;
        down(l, r, idx, lson, rson);
        return max(query(l, mid, lson, L, R), query(mid+1, r, rson, L, R));
    }
};

struct Node
{
    int type; // 1 for monster, 0 for armor
    ll atk, def, coin;
    Node(int t, ll a, ll d, ll c):type(t), atk(a), def(d), coin(c)
    {
    }
};

bool operator < (const Node &lhs, const Node &rhs)
{
    if(lhs.def != rhs.def) return lhs.def < rhs.def;
    else return lhs.type < rhs.type;
}

bool operator < (const pair<ll,ll> &lhs, const pair<ll,ll> &rhs)
{
    if(lhs.first != rhs.first) return lhs.first < rhs.first;
    else return lhs.second < rhs.second;
}

int wn, an, mn;
SegTree st;
vector<pair<ll,ll>> weapon;
vector<Node> armor_monster;

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
    cin >> wn >> an >> mn;
    for(int w = 0; w < wn; w++)
    {
        ll atk, coin; cin >> atk >> coin;
        weapon.emplace_back(atk, coin);
    }
    sort(weapon.begin(), weapon.end());
    for(int a = 0; a < an; a++)
    {
        ll def, coin; cin >> def >> coin;
        armor_monster.emplace_back(0, 0, def, coin);
    }
    for(int m = 0; m < mn; m++)
    {
        ll def, atk, coin; cin >> def >> atk >> coin;
        armor_monster.emplace_back(1, atk, def, coin);
    }
    sort(armor_monster.begin(), armor_monster.end());
    st.build(0, wn-1, 1, weapon);
}

void process()
{
    ll ans = -INF;
    /*
    cerr << "weapon : " << endl;
    for(auto w : weapon) cerr << w.first << " " << w.second << endl;
    cerr << "armor_monster : " << endl;
    for(auto w : armor_monster) cerr << w.type << " " << w.def << " " << w.atk << endl;
    */
    for(size_t i = 0; i < armor_monster.size(); i++)
    {
        auto &x = armor_monster[i];
        if(x.type == 1) // monster
        {
            auto it = upper_bound(weapon.begin(), weapon.end(), pair<ll,ll>(x.atk, INF));
            if(it == weapon.end()) continue;
            int idx = it-weapon.begin();
//            cerr << "weapon add from " << var(idx) << endl;
            st.addTag(0, wn-1, 1, idx, wn-1, x.coin);
        }
        else // armor
        {
            ans = max(ans, st.query(0, wn-1, 1, 0, wn-1)-x.coin);
        }
    }
    cout << ans << endl;
}

