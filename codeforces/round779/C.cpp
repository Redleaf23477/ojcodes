#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

bool solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    int one_pos = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            if (one_pos == -1) one_pos = i;
            else return false;
        }
    }
    if (one_pos == -1) return false;
    auto inc = [&](int L, int R) {
        for (int i = L+1; i <= R; i++) {
            if (arr[i] < arr[i-1]) return false;
        }
        return true;
    };
//    cerr << "ONE = " << one_pos << endl;
    return inc(0, one_pos-1) && inc(one_pos+1, n-1);
}


int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        bool ans = solve();
        if (ans) cout << "YES\n";
        else cout << "NO\n";
    }
}

