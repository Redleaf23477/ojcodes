#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int N; cin >> N;
    string S; cin >> S;
    vector<int> arr(N), child, adult;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        if (S[i] == '0') child.emplace_back(arr[i]);
        else adult.emplace_back(arr[i]);
    }
    sort(arr.begin(), arr.end());
    arr.emplace_back(arr.back() + 1);
    sort(child.begin(), child.end());
    sort(adult.begin(), adult.end());

    int ans = 0, i = -1, j = -1;
    int n = child.size(), m = adult.size();
    int ch = 0, ad = m;
    for (auto x : arr) {
        while (i + 1 < n && child[i + 1] < x) i++, ch++;
        while (j + 1 < m && adult[j + 1] < x) j++, ad--;
        ans = max(ans, ch + ad);
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



