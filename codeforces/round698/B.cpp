#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
#define endl '\n'

void solve() {
    int n, d; cin >> n >> d;
    vector<int> tmp(11); for (int i = 1; i <= 10; i++) tmp[i] = d*i;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        bool good = false;
        if (x >= 10*d) good = true;
        for (int i = 1; i <= 10; i++) {
            if (x >= tmp[i] && (x - tmp[i])%10 == 0) good = true;
        }
        if (good) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        solve();
    }
    cout.flush();
    return 0;
}

