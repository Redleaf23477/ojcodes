#include <bits/stdc++.h>
using namespace std;
using LL = long long;

// binary trie
struct Trie {
    Trie* nxt[2];
    void ins(int data, int len) {
        if (len == 0) return;
        int me = (data >> (len - 1)) & 1;
        if (!nxt[me]) nxt[me] = new Trie();
        nxt[me]->ins(data, len - 1);
    }
    int xor_max(int data, int len) {
        if (len == 0) return 0;
        int me = (data >> (len - 1)) & 1;
        int go = (nxt[me ^ 1]? (me ^ 1) : me);
        return ((me ^ go) << (len - 1)) + nxt[go]->xor_max(data, len - 1);
    }
    Trie() {
        nxt[0] = nxt[1] = nullptr;
    }
    ~Trie() {
        for (auto t : nxt) {
            if (t) delete t;
        }
    }
};

bool ok(int b0, Trie *t, int n, int lg_n) {
    return t->xor_max(b0, lg_n) < n;
}

void print_ans(int b, vector<int> const &arr) {
    cout << b;
    for (auto x : arr) {
        cout << " " << (b ^ x);
    }
    cout << "\n";
}

void solve() {
    int n; cin >> n;
    int lg_n = __lg(n) + 1;
    Trie *t = new Trie();
    vector<int> arr(n - 1);
    for (auto &x : arr) {
        cin >> x;
    }
    for (int i = 0; i < n - 1; i++) {
        if (i != 0) {
            arr[i] ^= arr[i - 1];
        }
        t->ins(arr[i], lg_n);
    }
    for (int b0 = 0; b0 < n; b0++) {
        if (ok(b0, t, n, lg_n)) {
            print_ans(b0, arr); break;
        }
    }
    delete t;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}

