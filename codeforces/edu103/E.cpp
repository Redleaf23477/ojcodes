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

int n, m, k;
vector<string> pat, str;
vector<int> mat;

void init() {
    cin >> n >> m >> k;
    pat.resize(n), str.resize(m), mat.resize(m);
    for (int i = 0; i < n; i++) {
        cin >> pat[i]; 
        for (auto &c : pat[i]) if (c == '_') c = 'z'+1;
    }
    for (int i = 0; i < m; i++) {
        cin >> str[i] >> mat[i]; mat[i]--;
    }
}

struct Trie {
    struct Node {
        int label;
        Node *ptr[27];
        Node():label(-1) {
            for (int i = 0; i < 27; i++) ptr[i] = nullptr;
        }
        ~Node() {
            for (int i = 0; i < 27; i++) 
                if (ptr[i] != nullptr) delete ptr[i];
        }
    };
    Node *rt;
    Trie():rt(new Node){}
    ~Trie() {
        delete rt;
    }
    void insert(string &s, int idx, Node *nd, int label) {
        if (idx == k) {
            nd->label = label; return;
        }
        int pid = s[idx]-'a';
        if (nd->ptr[pid] == nullptr) {
            nd->ptr[pid] = new Node(); 
        }
        insert(s, idx+1, nd->ptr[pid], label);
    }
    void insert(string s, int label) { insert(s, 0, rt, label); }
    void match(string &s, int idx, Node *nd, vector<int> &res) {
        if (idx == k) {
            res.emplace_back(nd->label); return;
        }
        // match character
        int pid = s[idx]-'a';
        if (nd->ptr[pid] != nullptr) {
            match(s, idx+1, nd->ptr[pid], res);
        }
        // match wildcard
        if (nd->ptr[26] != nullptr) {
            match(s, idx+1, nd->ptr[26], res);
        }
    }
    vector<int> match(string s) {
        vector<int> res;
        match(s, 0, rt, res);
        return res;
    }
};

void process() {
    Trie trie; {
        for (int i = 0; i < n; i++) {
            trie.insert(pat[i], i);
        }
    }
    vector<int> indeg(n, 0);
    vector<vector<int>> graph(n); {
        for (int i = 0; i < m; i++) {
            vector<int> res = trie.match(str[i]);
            int u = mat[i];
            bool found = false;
            for (auto v : res) {
                if (u == v) { found = true; continue; }
                graph[u].emplace_back(v);
                indeg[v]++;
            }

            /*
            cerr << str[i] << " matches: " << endl;
            for (auto x : res) {
                cerr << pat[x] << endl;
            }
            */

            if (!found) { cout << "NO" << endl; return; }
        } 
        /*
        cerr << "graph: " << endl;
        for (int i = 0; i < n; i++) {
            cerr << i << " => ";
            for (auto j : graph[i]) cerr << j << " ";
            cerr << endl;
        }
        */
    }
    queue<int> q; {
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) q.emplace(i);
        }
    }
    vector<int> ans;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        ans.emplace_back(u);
        for (auto v : graph[u]) {
            if (--indeg[v] == 0) {
                q.emplace(v);
            }
        }
    }
    if (ans.size() != n) { cout << "NO" << endl; return; }
    cout << "YES" << endl;
    for (auto x : ans) cout << x+1 << " ";
    cout << endl;
}

