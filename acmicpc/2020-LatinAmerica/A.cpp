#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using TII = tuple<int,int>;

struct Answer {
    vector<int> ans;
    bool operator < (Answer &that) {
        if (ans.empty()) return false;
        else if (that.ans.empty()) return true;
        else return ans.size() < that.ans.size();
    }
    TII get_origin(int idx) {
        for (int i = 0; i < idx; i++) for (int j = i; j < idx; j++) {
            if (ans[i] + ans[j] == ans[idx]) return TII(ans[i], ans[j]);
        }
        return TII(-1, -1);
    }
    void print() {
        if (ans.empty()) cout << "*\n";
        else {
            for (size_t i = 1; i < ans.size(); i++) {
                auto [x, y] = get_origin(i);
                cout << 1 << " " << x << "\n";
                cout << 1 << " " << y << "\n";
            }
        }
    }
};

struct BruteForce {
    int n;
    int max_dep;
    Answer best, cur;
    BruteForce(int Q) : n(Q), max_dep(9) {}

    void dfs(int depth) {
        // find answer
        if (cur.ans.back() == n) {
            if (cur < best) {
                best = cur;
                max_dep = best.ans.size();
            }
            return;
        }
        // search answer
        for (size_t i = 0; i < cur.ans.size(); i++) {
            for (size_t j = i; j < cur.ans.size(); j++) {
                // if best is updated, return
                if (depth >= max_dep) return;
                if ((cur.ans.back() << (max_dep - depth)) < n) return;

                int new_num = cur.ans[i] + cur.ans[j];
                if (new_num > n || new_num <= cur.ans.back()) continue;
                cur.ans.emplace_back(new_num);
                dfs(depth + 1);
                cur.ans.pop_back();
            }
        }
    }

    Answer run() {
        cur.ans.emplace_back(1);
        dfs(0);
        return best;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int P, Q; cin >> P >> Q;
    if (P != 1) {
        cout << "*\n";
    } else {
        Answer ans = BruteForce(Q).run();
        ans.print();
    }
}


