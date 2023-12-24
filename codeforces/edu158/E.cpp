#include <bits/stdc++.h>
using namespace std;
using LL = long long;

bool is_chain(vector<vector<int>> &tree) {
    for (auto x : tree) {
        if (x.size() > 2) return false;
    }
    return true;
}

void chain_case(vector<LL> &arr) {
    sort(arr.begin(), arr.end());
    LL ans = 0;
    for (int i = 0; i < 2; i++) {
        if (arr.back() > 0) {
            ans += arr.back();
            arr.pop_back();
        } else {
            break;
        }
    }
    cout << ans << "\n";
}

void solve() {
    int n; cin >> n;
    vector<LL> arr(n);
    for (auto &x : arr) cin >> x;
    vector<vector<int>> tree(n);
    vector<int> deg(n, 0);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v; u--, v--;
        tree[u].emplace_back(v);
        tree[v].emplace_back(u);
    }
    
    if (is_chain(tree)) {
        chain_case(arr); return;
    }

    int rt = -1;
    for (int i = 0; i < n; i++) {
        if (tree[i].size() > 2) {
            rt = i; break;
        }
    }
    /*
    cerr << "rt = " << rt << endl;
    */

    LL ans = max(0ll, *max_element(arr.begin(), arr.end()));
    vector<LL> max_decendant(n, -1e18);
    function<void(int,int)> dfs = [&](int u, int pa) {
        // dfs
        vector<LL> child_res;
        for (auto v : tree[u]) {
            if (v == pa) continue;
            dfs(v, u);
            child_res.emplace_back(max_decendant[v]);
        }
        sort(child_res.begin(), child_res.end(), greater<LL>());

        /*
        cerr << "u = " << u << ": ";
        for (auto x : child_res) cerr << x << " ";
        cerr << endl;
        */

        // part 1: parent is missing
        {
            // case: I have degree = 0, only me (counted)
            ans = max(ans, arr[u]);

            // case: I have degree = 1, me + a good child
            if (child_res.size() >= 1) {
                ans = max(ans, arr[u] + child_res.front());
            }

            // case: I have degree = 2, two good children
            if (child_res.size() >= 2) {
                ans = max(ans, child_res[0] + child_res[1]);
            }

            // case: I have degree > 2, me + my good children
            if (child_res.size() > 2) {
                LL tmp = arr[u] + child_res[0] + child_res[1] + child_res[2];
                for (int i = 3; i < (int)child_res.size(); i++) {
                    if (child_res[i] < 0) break;
                    tmp += child_res[i];
                }
                ans = max(ans, tmp);
            }
        }

        // part 2: I have a parent
        {
            // case: I have degree = 1, only me
            max_decendant[u] = max(max_decendant[u], arr[u]);

            // case: I have degree = 2, I am not counted, but my child is
            if (child_res.size() >= 1) {
                max_decendant[u] = max(max_decendant[u], child_res.front());
            }

            // case: I have degree > 2, I am counted, and at least two of my children are
            if (child_res.size() >= 2) {
                LL tmp = arr[u] + child_res[0] + child_res[1];
                for (int i = 2; i < (int)child_res.size(); i++) {
                    if (child_res[i] < 0) break;
                    tmp += child_res[i];
                }
                max_decendant[u] = max(max_decendant[u], tmp);
            }
        }
    };
    dfs(rt, rt);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    for (int i = 1; i <= T; i++) {
        solve();
    }
}

