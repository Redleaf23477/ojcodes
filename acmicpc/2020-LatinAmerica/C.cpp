#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    LL sum = accumulate(arr.begin(), arr.end(), 0ll);
    LL avg = sum / n;

    auto run = [n, avg](vector<int> arr) {
        LL cost = 0, bag = 0;
        for (int i = 0; i < 2 * n; i++) {
            int idx = i % n;
            // bag
            LL delta = avg - arr[idx];
            if (delta > 0) {
                arr[idx] += min(bag, delta);
                bag -= min(bag, delta);
            } else {
                bag += -delta;
                arr[idx] = avg;
            }

            // move
            cost += bag;
        }
        return cost;
    };

    LL ans = run(arr);
    reverse(arr.begin(), arr.end());
    ans = min(ans, run(arr));
    cout << ans << "\n";
}

