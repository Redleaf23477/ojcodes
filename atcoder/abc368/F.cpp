#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    LL MAX = 100000;
    vector<LL> div(MAX + 1, 0);
    iota(div.begin(), div.end(), 0);
    for (LL i = 2; i <= MAX; i++) {
        if (div[i] != i) continue;
        for (LL j = i * i; j <= MAX; j += i) {
            div[j] = i;
        }
    }

    int n; cin >> n;
    int prime = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        prime += (div[x] == x);
    }
    int composite = n - prime;
    
    cout << (((prime % 2) ^ (composite % 2)) ? "Anna" : "Bruno") << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    while (T--) solve();
}

