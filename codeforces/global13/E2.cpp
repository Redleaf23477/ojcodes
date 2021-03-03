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
// stl
#define range(seq) seq.begin(), seq.end()


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

int vn;
vector<vector<int>> tree;

void init() {
    cin >> vn;
    tree.assign(vn, vector<int>());
    for (int i = 1; i < vn; i++) {
        int u, v; cin >> u >> v; u--, v--;
        tree[u].emplace_back(v);
        tree[v].emplace_back(u);
    }
}

void process() {
    vector<int> fib(21, 1); {
        for (int i = 2; i < 21; i++) fib[i] = fib[i-1] + fib[i-2];
    }
    int fidx = -1; {
        for (int i = 0; i < 21; i++) if (fib[i] == vn) fidx = i;
    }
    if (fidx == -1) {
        cerr << "NO" << endl; return;
    }

    vector<vector<int>> subTreeSize(vn, vector<int>()); {
        function<int(int,int)> dfs = [&](int u, int pa) -> int {
            int paidx = -1, acc = 1;
            for (auto v : tree[u]) {
                if (v == pa) {
                    paidx = subTreeSize[u].size(); 
                    subTreeSize[u].emplace_back(0);
                    continue;
                }
                int sz = dfs(v, u);
                acc += sz;
                subTreeSize[u].emplace_back(sz);
            }
            if (paidx != -1) {
                subTreeSize[u][paidx] = vn - acc;
            }
            return acc;
        };
        dfs(0, 0);
        /*
        cerr << "trees: " << endl;
        for (int u = 0; u < vn; u++) {
            cerr << var(u) << " : ";
            assert(tree[u].size() == subTreeSize[u].size());
            for (int i = 0; i < (int)tree[u].size(); i++) {
                cerr << "(" << tree[u][i] << "," << subTreeSize[u][i] << ")";
            }
            cerr << endl;
        }
        */
    }
    bool ans = true; {
        function<void(int,int,int)>bye_pa = [&](int u, int pa, int pa_sz) -> void {
            // find pa
            int paidx = -1;
            for (int i = 0; i < (int)tree[u].size(); i++) {
                int v = tree[u][i], w = subTreeSize[u][i];
                if (w == 0) continue;
                if (v == pa) {
                    paidx = i;
                    if (pa_sz == -1) pa_sz = w;
                    break;
                }
            }
            // update pa
            subTreeSize[u][paidx] -= pa_sz;
            // update child
            for (int i = 0; i < (int)tree[u].size(); i++) {
                int v = tree[u][i], w = subTreeSize[u][i];
                if (w == 0 || v == pa) continue;
                bye_pa(v, w, pa_sz);
            }
        };
        function<int(int,int)> cut = [&](int u, int pa, int fidx) -> bool {
            int paidx = -1;
            bool found = false;
            tuple<int,int> res(-1, -1);
            for (int i = 0; i < (int)tree[u].size() && !found; i++) {
                int v = tree[u][i], w = subTreeSize[u][i];
                if (w == 0) continue;
                if (v == pa) {
                    paidx = i; continue;
                }
                // find
                if (w == fib[fidx-1]) {
                    res = make_tuple(v, fidx-1), found = true;
                    bye_pa(v, u, -1);
                } else if (w == fib[fidx-2]) {
                    res = make_tuple(v, fidx-2), found = true;
                    bye_pa(v, u, -1);
                } else if (!found) {
                    auto subres = cut(v, u, fidx);
                    if (get<0>(subres) != -1) {
                        res = subres, found = true;
                    }
                }
                // update subTreeSize if found
                if (found) {
                    subTreeSize[u][i] -= fib[get<1>(res)];
                }
            }
            if (!found) return res; // res == (-1, -1)
        };
        function<bool(int,int)> check = [&](int u, int fidx) -> bool {
            if (fidx == 0 || fidx == 1) return true;
            auto [rt, fidx2] = cut(u, u, fidx);
            if (rt == -1) return false;
            return check(u, fidx-1+fidx-2+fidx2) || check(rt, fidx2);
        };
        ans = check(0, fidx);
    }
    cout << (ans? "YES" : "NO") << endl;
}

