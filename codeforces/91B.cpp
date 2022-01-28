#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    vector<int> min_pos(n, 0);
    min_pos[n-1] = n-1;
    for (int i = n-2; i >= 0; i--) {
        if (arr[i] < arr[min_pos[i+1]]) {
            min_pos[i] = i;
        } else {
            min_pos[i] = min_pos[i+1];
        }
    }
    for (int i = 0; i < n; i++) {
        if (min_pos[i] == i) {
            cout << -1 << " ";
        } else {
            int l = i + 1, r = n - 1, mid, ans = n;
            while (l <= r) {
                mid = (l + r) / 2;
                if (arr[i] <= arr[min_pos[mid]]) ans = mid, r = mid - 1;
                else l = mid + 1;
            }
            cout << ans - i - 2 << " ";
        }
    }
    cout << "\n";
}

