#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

/*
map<LL,LL> enumerate(vector<LL>::iterator L, vector<LL>::iterator R, LL x) {
    map<LL,LL> ans;
    function<void(vector<LL>::iterator, LL)> dfs = [&](vector<LL>::iterator it, LL sum) {
        if (sum > x) return;
        if (it == R) {
            ans[sum] += 1; return;
        }
        dfs(it + 1, sum);
        dfs(it + 1, sum + *it);
    };
    dfs(L, 0);
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    LL x; cin >> x;
    vector<LL> arr(n);
    for (auto &x : arr) cin >> x;
    int m = n / 2;
    map<LL,LL> left = enumerate(arr.begin(), arr.begin() + m, x);
    map<LL,LL> right = enumerate(arr.begin() + m, arr.end(), x);
    LL ans = 0;
    for (auto [val, cnt] : left) {
        auto it = right.find(x - val);
        if (it != right.end()) ans += cnt * it->second;
    }
    cout << ans << "\n";
}
*/

vector<LL> enumerate(vector<LL>::iterator L, vector<LL>::iterator R, LL x) {
    vector<LL> ans;
    int size = R - L;
    for (int s = 0; s < (1 << size); s++) {
        LL sum = 0;
        for (int b = 0; b < size; b++) {
            if ((s >> b) & 1) {
                sum += *(L + b);
            }
        }
        if (sum <= x) ans.emplace_back(sum);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    LL x; cin >> x;
    vector<LL> arr(n);
    for (auto &x : arr) cin >> x;
    int m = n / 2;
    auto left = enumerate(arr.begin(), arr.begin() + m, x);
    auto right = enumerate(arr.begin() + m, arr.end(), x);
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    LL ans = 0;
    for (auto l : left) {
        ans += upper_bound(right.begin(), right.end(), x - l) - lower_bound(right.begin(), right.end(), x - l);
    }
    cout << ans << "\n";
}

