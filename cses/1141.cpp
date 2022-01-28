#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    map<int,int> window;
    int ans = 0;
    for (int i = 0, j = 0; j < n; j++) {
        window[arr[j]] += 1;
        while (window[arr[j]] > 1) {
            if (--window[arr[i]] == 0) {
                window.erase(arr[i]);
            }
            i += 1;
        }
        ans = max(ans, j - i + 1);
    }
    cout << ans << "\n";
}

