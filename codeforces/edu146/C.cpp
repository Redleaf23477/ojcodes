#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n, s1, s2; cin >> n >> s1 >> s2;
    vector<pair<int,int>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i+1;
    }
    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());
    vector<int> A, B;
    for (auto [sec, num] : arr) {
        int t1 = s1 * (A.size() + 1);
        int t2 = s2 * (B.size() + 1);
        if (t1 < t2) A.emplace_back(num);
        else B.emplace_back(num);
    }
    cout << A.size() << " ";
    for (auto x : A) cout << x << " ";
    cout << "\n";
    cout << B.size() << " ";
    for (auto x : B) cout << x << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



