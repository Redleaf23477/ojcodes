#include <bits/stdc++.h>
using namespace std;
using LL = long long;

pair<int,int> get_index(string &str, LL pos) {
    int i = 0, n = str.size();
    while (pos >= n) {
        pos -= n;
        n--;
        i++;
    }
    return make_pair(i, pos);
}

char gen_char(string &str, int i, int j) {
    int n = str.size();
    vector<char> stk;
    int k = 0;
    while (i--) {
        while (k < n && (stk.empty() || stk.back() <= str[k])) {
            stk.push_back(str[k]), k++;
        }
        stk.pop_back();
    }
    for (; k < n; k++) {
        stk.push_back(str[k]);
    }
    return stk[j];
}

void solve() {
    string str; cin >> str;
    LL pos; cin >> pos; pos--;
    auto [i, j] = get_index(str, pos);
    cout << gen_char(str, i, j);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
    cout << "\n";
}

