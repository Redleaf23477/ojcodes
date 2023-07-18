#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int N; cin >> N;
    unordered_map<string, int> cnt;
    vector<pair<string,string>> arr(N);
    for (auto &[s, t] : arr) {
        cin >> s >> t;
        cnt[s]++;
        if (s != t) cnt[t]++;
    }
    bool good = true;
    for (auto &[s, t] : arr) {
        if (cnt[s] != 1 && cnt[t] != 1) {
            good = false;
        }
    }
    cout << (good? "Yes\n" : "No\n");
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



