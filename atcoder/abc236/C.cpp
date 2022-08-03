#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n, m; cin >> n >> m;
    vector<string> A(n), B(m);
    for (auto &a : A) cin >> a;
    for (auto &b : B) cin >> b;

    vector<bool> ans(n, false);
    for (int a = 0, b = 0; b < m; b++) {
        while (A[a] != B[b]) {
            ans[a] = false;
            a++;
        }
        ans[a] = true;
        a++;
    }
    for (auto x : ans) {
        cout << (x? "Yes\n" : "No\n");
    }
}

