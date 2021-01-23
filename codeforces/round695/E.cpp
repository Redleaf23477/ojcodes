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

int n;
vector<int> arr;
vector<vector<int>> tree;

void init() {
    cin >> n;
    arr.resize(n); {
        vector<int> tmp(n);
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            arr[i] = tmp[i] = x;
        }
        sort(tmp.begin(), tmp.end()), tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
        for (auto &x : arr) {
            x = lower_bound(tmp.begin(), tmp.end(), x)-tmp.begin();
        }

        /*
        cerr << "arr = ";
        for (auto x : arr) cerr << x << " ";
        cerr << endl;
        */
    }
    tree.resize(n); {
        for (int _  = 1; _ < n; _++) {
            int u, v; cin >> u >> v; u--, v--;
            tree[u].emplace_back(v);
            tree[v].emplace_back(u);
        }
    }
}

void process() {
    // dfs1: timestamp
    vector<vector<int>> occur(n);
    vector<int> inStamp(n, -1), outStamp(n, -1); {
        int tim = 0;
        function<void(int,int)> dfs = [&] (int u, int pa) -> void {
            inStamp[u] = ++tim;
            occur[arr[u]].emplace_back(inStamp[u]);
            for (auto v : tree[u]) {
                if (v == pa) continue;
                dfs(v, u);
            }
            outStamp[u] = tim;
            /*
            cerr << var(u) << var(inStamp[u]) << var(outStamp[u]) << endl;
            */
        };
        dfs(0, 0);
    }
    // dfs2: constraints using two pointers(+1, -1)
    // constraint:
    //   disagree (mark -1) on u: subtree rooted at u should not contain distinctive roots
    //   agree (mark 1) on u: subtree rooted at u may contain distinctive roots
    int ruleCnt = 0;
    vector<int> tag(n, 0); {
        function<int(int,int)> count_occur = [&] (int label, int rt) -> int {
            int l = inStamp[rt], r = outStamp[rt];
            auto &a = occur[label];
            return upper_bound(a.begin(), a.end(), r) - lower_bound(a.begin(), a.end(), l);
        };
        function<void(int,int)> dfs = [&] (int u, int pa) -> void {
            int decCnt = 0; // #arr[u] in decendents
            for (auto v : tree[u]) {
                if (v == pa) continue;
                int subT = count_occur(arr[u], v);
                decCnt += subT;
                if (subT > 0) {
                    ruleCnt++;
                    tag[v]++;
                }
                dfs(v, u);
            }
            int ancCnt = occur[arr[u]].size() - 1 - decCnt; // #arr[u] in ancestors
            /*
            cerr << var(u) << var(1+decCnt) << var(count_occur(arr[u], u)) << endl;
            cerr << var(u) << var(decCnt) << var(ancCnt) << endl;
            */
            if (ancCnt > 0) {
                tag[u]--;
            }
        };
        dfs(0, 0);
        /*
        cerr << var(ruleCnt) << endl;
        */
        
    }
    // dfs3: prefix sum on tree path
    // run prefix sum on tree, distinctive root iff ( #constraints == agree-disagree )
    int ans = 0; {
        function<int(int,int,int)> dfs = [&] (int u, int pa, int sum) -> int {
            sum += tag[u];
            int res = 0;
            if (sum == ruleCnt) res++;
            for (auto v : tree[u]) {
                if (v == pa) continue;
                res += dfs(v, u, sum);
            }
            return res;
        };
        ans = dfs(0, 0, 0);
    }
    cout << ans << endl;
}
