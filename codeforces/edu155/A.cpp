#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n; cin >> n;
    int my_str, my_end; cin >> my_str >> my_end;
    int ans = my_str;
    for (int i = 1; i < n; i++) {
        int s, e; cin >> s >> e;
        if (s >= my_str && e >= my_end) ans = -1;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
}

