#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n, m; cin >> n >> m;
    map<int,int> A;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        A[x]++;
    }
    vector<int> B(m);
    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }
    for (auto b : B) {
        auto it = A.find(b);
        if (it == A.end()) {
            cout << "No\n";
            return;
        }
        if (--it->second == 0) {
            A.erase(it);
        }
    }
    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



