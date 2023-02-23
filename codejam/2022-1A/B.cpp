#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

constexpr LL MAX = 1'000'000'000;
mt19937_64 myrand;

void report(vector<int> &arr) {
    for (auto x : arr) cout << x << " ";
    cout << endl;
}

void solve() {
    int n; cin >> n;
    vector<int> arr;
    // push power of 2
    for (LL p = 1; p <= MAX; p *= 2) {
        arr.emplace_back(p);
    }
    // push random until full
    while (arr.size() != n) {
        int x = myrand() % MAX + 1;
        if (__builtin_popcount(x) == 1) continue;
        arr.emplace_back(x);
    }

    // first send
    report(arr);

    // receive response
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        arr.emplace_back(x);
    }

    // partition
    sort(arr.begin(), arr.end());
    LL non_ans_sum = 0, ans_sum = 0;
    vector<int> ans;
    while (!arr.empty()) {
        int x = arr.back(); arr.pop_back();
        if (ans_sum < non_ans_sum) {
            ans_sum += x;
            ans.emplace_back(x);
        } else {
            non_ans_sum += x;
        }
    }

    // second send
    report(ans);
}

int main() {
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

