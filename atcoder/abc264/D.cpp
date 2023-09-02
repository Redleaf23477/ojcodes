#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int N = 7;
    string atcoder("atcoder");
    vector<int> mp(26);
    for (size_t i = 0; i < atcoder.size(); i++) {
        mp[atcoder[i] - 'a'] = i;
    }

    string str; cin >> str;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        arr[i] = mp[str[i] - 'a'];
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j + 1 < N; j++) {
            if (arr[j] > arr[j + 1]) {
                ans++;
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//    int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



