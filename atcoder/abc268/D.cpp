#include <bits/stdc++.h>
using namespace std;
using LL = long long;

vector<int> get_perm(string t, vector<string> &S) {
    for (auto &ch : t) {
        if (ch == '_') ch = ' ';
    }
    stringstream ss(t);
    vector<int> perm, used(S.size(), 0);
    string buff;
    while (ss >> buff) {
        size_t idx = find(S.begin(), S.end(), buff) - S.begin();
        if (idx == S.size()) return vector<int>();
        if (used[idx]) return vector<int>();
        perm.emplace_back(idx);
        used[idx] = true;
    }
    if (perm.size() != S.size()) return vector<int>();
    return perm;
}
vector<int> get_dash(string t, int N) {
    for (auto &ch : t) {
        if (ch != '_') ch = ' ';
    }
    stringstream ss(t);
    vector<int> dash;
    string buff;
    while (ss >> buff) {
        dash.emplace_back(buff.length());
    }
    if ((int)dash.size() != N - 1) return vector<int> {-1};
    return dash;
}

vector<int> get_ans(vector<int> &ans, vector<string> &S, map<vector<int>,vector<vector<int>>> &T) {
    if (T.count(ans) == 0) return vector<int>(S.size() - 1, 1);
    int quota = 16;
    for (auto &s : S) quota -= s.length();
    auto &dash_set = T[ans];
    sort(dash_set.begin(), dash_set.end());
    for (auto dash : dash_set) {
        int sum = accumulate(dash.begin(), dash.end(), 0);
        for (auto &x : dash) {
            if (x > 1) {
                x--;
                if (!binary_search(dash_set.begin(), dash_set.end(), dash)) {
                    return dash;
                }
                x++;
            }
            if (sum + 1 <= quota) {
                x++;
                if (!binary_search(dash_set.begin(), dash_set.end(), dash)) {
                    return dash;
                }
                x--;
            }
        }
    }
    return vector<int> {-1};
}

void print(vector<int> ans, vector<int> dash, vector<string> S) {
    if (ans.size() == 1 && S[ans[0]].size() < 3) {
        cout << -1 << "\n"; return;
    }
    cout << S[ans[0]];
    for (size_t i = 1; i < ans.size(); i++) {
        cout << string(dash[i - 1], '_');
        cout << S[ans[i]];
    }
    cout << "\n";
}

void solve() {
    int N, M; cin >> N >> M;
    vector<string> S(N);
    for (auto &x : S) cin >> x;
    map<vector<int>,vector<vector<int>>> T;
    for (int i = 0; i < M; i++) {
        string t; cin >> t;
        vector<int> perm = get_perm(t, S);
        vector<int> dash = get_dash(t, N);
        if (!perm.empty() && dash != vector<int> {-1}) {
            T[perm].push_back(dash);
        }
    }
    vector<int> ans(N);
    iota(ans.begin(), ans.end(), 0);
    do {
        vector<int> dash = get_ans(ans, S, T);
        if (dash != vector<int> {-1}) {
            print(ans, dash, S); return;
        }
    } while (next_permutation(ans.begin(), ans.end()));
    cout << -1 << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}