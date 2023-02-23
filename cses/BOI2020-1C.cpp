#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using T = tuple<int,int>;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<T> arr(n);
    for (auto &[a, b] : arr) cin >> a >> b;
    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());
    vector<int> tmp;
    for (auto [_, x] : arr) {
        auto it = upper_bound(tmp.begin(), tmp.end(), x);
        if (it == tmp.end()) tmp.emplace_back(x);
        else *it = x;
    }
    cout << tmp.size() << "\n";
}

