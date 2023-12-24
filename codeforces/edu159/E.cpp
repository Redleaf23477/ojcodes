#include <bits/stdc++.h>
using namespace std;
using LL = long long;

struct Trie {
    using IT = string::iterator;
    struct Node {
        Node* next[26];
        int cnt;
        LL len_sum;
        Node() : cnt(0), len_sum(0) {
            fill(next, next + 26, nullptr);
        }
        ~Node() {
        }
    };
    Node *root;
    vector<Node> pool;
    vector<Node>::iterator pool_it;
    Trie(int pool_sz) : pool(pool_sz) {
        pool_it = pool.begin();
        root = get_node();
    }
    Node* get_node() { Node *ptr = &(*pool_it); pool_it++; return ptr; }
    void insert(string &str) { 
        Node *ptr = root;
        for (auto it = str.begin(); it != str.end(); it++) {
            ptr->cnt += 1;
            ptr->len_sum += str.end() - it;
            char ch = *it;
            if (!ptr->next[ch - 'a']) ptr->next[ch - 'a'] = get_node();
            ptr = ptr->next[ch - 'a'];
        }
        ptr->cnt += 1;
    }
    LL query(string &str) { 
        LL ans = 0;
        Node *ptr = root;
        for (auto it = str.begin(); it != str.end(); it++) {
            ans += (str.end() - it) * ptr->cnt + ptr->len_sum;
            char ch = *it;
            if (!ptr->next[ch - 'a']) return ans;
            ans -= (str.end() - it) * ptr->next[ch - 'a']->cnt;
            ans -= ptr->next[ch - 'a']->len_sum + ptr->next[ch - 'a']->cnt;
            ptr = ptr->next[ch - 'a'];
        }
        ans += ptr->len_sum;
        return ans;
    }
};

void solve() {
    int n; cin >> n;
    vector<string> arr(n);
    int total_length = 0;
    for (auto &x : arr) {
        cin >> x;
        reverse(x.begin(), x.end());
        total_length += x.size();
    }
    
    Trie t(total_length + 1);
    for (auto &x : arr) {
        t.insert(x);
    }

    LL ans = 0;
    for (auto &x : arr) {
        reverse(x.begin(), x.end());
        ans += t.query(x);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    while (T--) solve();
}

