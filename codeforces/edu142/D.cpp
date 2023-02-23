#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

struct Trie {
    struct Node {
        int cnt;
        vector<Node*> nxt;
        Node(): cnt(0), nxt(10, nullptr) {}
        ~Node() {
            for (auto &x : nxt) {
                if (x) delete x;
            }
        }
    };
    using NodePtr = Node*;
    NodePtr root;
    Trie() : root(new Node()) {}
    ~Trie() { delete root; }
    void insert(vector<int> &arr) {
        NodePtr ptr = root;
        for (auto x : arr) {
            if (!ptr->nxt[x]) {
                ptr->nxt[x] = new Node();
            }
            ptr = ptr->nxt[x];
        }
        ptr->cnt++;
    }
    int query(vector<int> &arr) {
        NodePtr ptr = root;
        int ans = 0;
        for (auto &x : arr) {
            if (ptr->nxt[x]) {
                ptr = ptr->nxt[x];
                ans++;
            } else {
                break;
            }
        }
        return ans;
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (auto &p : arr) {
        for (auto &x : p) {
            cin >> x; x--;
        }
    }
    Trie t;
    for (auto &p : arr) {
        vector<int> inv(m);
        for (int i = 0; i < m; i++) {
            inv[p[i]] = i;
        }
        t.insert(inv);
    }
    for (auto &p : arr) {
        cout << t.query(p) << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

