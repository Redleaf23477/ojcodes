#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    vector<tuple<int,int>> ans;
    priority_queue<int,vector<int>,greater<int>> pq;
    while (n--) {
        string op; cin >> op;
        int x = 0;
        if (op != "removeMin") cin >> x;

        if (op == "insert") {
            pq.emplace(x);
            ans.emplace_back(0, x);
        } else if (op == "getMin") {
            if (pq.empty() || pq.top() != x) {
                while (!pq.empty() && pq.top() < x) {
                    pq.pop();
                    ans.emplace_back(2, 87);
                }
                if (pq.empty() || pq.top() != x) {
                    pq.emplace(x);
                    ans.emplace_back(0, x);
                }
            }
            ans.emplace_back(1, x);
        } else {
            if (pq.empty()) {
                pq.emplace(87);
                ans.emplace_back(0, 87);
            }
            pq.pop();
            ans.emplace_back(2, x);
        }
    }

    cout << ans.size() << "\n";
    for (auto [op, x] : ans) {
        if (op == 0) cout << "insert " << x << "\n";
        else if (op == 1) cout << "getMin " << x << "\n";
        else cout << "removeMin" << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



