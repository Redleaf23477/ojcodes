#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<LL> arr(n);
    for (auto &x : arr) cin >> x;
    set<LL> tiger_blue;
    set<LL> ans;
    for (auto &x : arr) {
        set<LL> tmp;
        tmp.insert(x);
        for (auto y : tiger_blue) tmp.insert(gcd(x, y));
        for (auto y : tmp) ans.insert(y);
        swap(tiger_blue, tmp);
    }
    cout << ans.size() << "\n";
}

