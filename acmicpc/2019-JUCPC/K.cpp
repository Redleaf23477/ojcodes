#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> arr(n); 
    for (auto &x : arr) cin >> x;

    LL ans = 0;
    for (int b = 0; b < (1<<n); b++) {
        LL x = 0;
        for (int i = 0; i < n; i++) {
            if ((b >> i) & 1) {
                x |= arr[i];
            }
        }
        ans += x;
    }

    cout << ans << "\n";
}

