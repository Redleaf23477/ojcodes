#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n, s; cin >> n >> s;
    vector<LL> arr(n);
    for (auto &x : arr) cin >> x;
    int ans = 0;
    LL sum = arr[0];
    for (int i = 0, j = 0; i < n; i++) {
        while (j+1 < n && sum < s) { 
            sum += arr[j+1];
            j++;
        }
        if (sum == s) ans += 1;
        sum -= arr[i];
    }
    cout << ans << "\n";
}

