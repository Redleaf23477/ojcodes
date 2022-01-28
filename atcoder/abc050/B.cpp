#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    int sum = accumulate(arr.begin(), arr.end(), 0);
    
    int T; cin >> T;
    while (T--) {
        int p, x; cin >> p >> x;
        cout << sum - arr[p-1] + x << endl;
    }
}

