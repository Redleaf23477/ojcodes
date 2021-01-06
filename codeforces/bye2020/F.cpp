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

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    for (int t = 1; t <= T; t++) {
        init();
        process();
    }
    cout.flush();
    return 0;
}

int n, m;
vector<tuple<int,int>> edge;

void init() {
    cin >> n >> m; 
    edge.clear();
    for (int i = 0; i < n; i++) {
        int k, u, v; cin >> k;
        if (k == 2) {
            cin >> u >> v; u--, v--;
        } else {
            cin >> u; u--; v = m;
        }
        edge.emplace_back(u, v);
    }
}

struct DisjointSet {
    int n;
    vector<int> pa;
    DisjointSet(int _n) : n(_n), pa(_n, 0) {
        iota(pa.begin(), pa.end(), 0);
    };
    int findrt(int x) {
        if (pa[x] == x) return x;
        else return pa[x] = findrt(pa[x]);
    }
    bool same(int x, int y) {
        return findrt(x) == findrt(y);
    }
    void uni(int x, int y) {
        pa[findrt(x)] = findrt(y);
    }
};

const LL MOD = 1e9+7;

LL fastpw(LL a, LL p) {
    if (p == 0) return 1;
    else if (p%2 == 0) return fastpw(a*a%MOD, p/2);
    else return a*fastpw(a*a%MOD, p/2)%MOD;
}

void process() {
    DisjointSet ds(m+1);
    vector<int> usedEdge;
    for (size_t i = 0; i < edge.size(); i++) {
        auto [u, v] = edge[i];
        if (!ds.same(u, v)) {
            usedEdge.emplace_back(i);
            ds.uni(u, v);
        }
    }
    cout << fastpw(2, usedEdge.size()) << " " << usedEdge.size()%MOD << endl;
    for (auto x : usedEdge) cout << x+1 << " ";
    cout << endl;
}

