#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using T = tuple<int,LL>;  // (val, cnt)

vector<T> input(int n) {
    vector<T> ans;
    int buff;
    for (int i = 0; i < n; i++) {
        cin >> buff;
        if (ans.empty() || get<0>(ans.back()) != buff) {
            ans.emplace_back(buff, 1);
        } else {
            get<1>(ans.back())++;
        }
    }
    return ans;
}

void break_down(vector<T> &arr, int m) {
    for (auto &[val, cnt] : arr) {
        while (val % m == 0) {
            cnt *= m;
            val /= m;
        }
    }
}

vector<T> fix(vector<T> &arr) {
    vector<T> ans;
    for (auto [val, cnt] : arr) {
        if (ans.empty() || get<0>(ans.back()) != val) {
            ans.emplace_back(val, cnt);
        } else {
            get<1>(ans.back()) += cnt;
        }
    }
    return ans;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<T> arr = input(n);
    int k; cin >> k;
    vector<T> target = input(k);

    break_down(arr, m);
    break_down(target, m);

    arr = fix(arr);
    target = fix(target);

    if (arr == target) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

