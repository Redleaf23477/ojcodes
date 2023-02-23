#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<pair<int,int>> ans;
        for (int b = 1, a = 3*n-1; b < a; b += 3, a -= 3) {
            ans.emplace_back(a, b);
        }
        cout << ans.size() << "\n";
        for (auto [a, b] : ans) {
            cout << a << " " << b << "\n";
        }
    }
}

