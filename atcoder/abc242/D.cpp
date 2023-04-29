#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve(string const &str, LL t, LL k) {
    k--;
    vector<int> mem;
    while (t > 0 && k > 0) {
        mem.emplace_back(k % 2);
        k /= 2, t--;
    }
    int root = (str[k] - 'A' + t) % 3;
    while (!mem.empty()) {
        root = (root + 1 + mem.back()) % 3;
        mem.pop_back();
    }
    cout << (char)('A' + root) << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string str; cin >> str;
    LL Q; cin >> Q;
    while (Q--) {
        LL t, k; cin >> t >> k;
        solve(str, t, k);
    }
}



