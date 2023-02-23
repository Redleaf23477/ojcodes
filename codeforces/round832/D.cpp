#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    vector<int> arr(n+1, 0);
    for (int i = 1; i <= n; i++) cin >> arr[i];

    /*
    cerr << "arr: " << endl;
    for (auto x : arr) cerr << x << " ";
    cerr << endl;
    */

    vector<int> prefix_xor(n+1, 0);
    for (int i = 1; i <= n; i++) prefix_xor[i] = prefix_xor[i-1] ^ arr[i];
    vector<int> prefix_sum(n+1, 0);
    for (int i = 1; i <= n; i++) prefix_sum[i] = prefix_sum[i-1] + arr[i];

    map<int, vector<int>> odd_pos, even_pos;
    for (int i = 1; i <= n; i += 2) {
        odd_pos[prefix_xor[i]].emplace_back(i);
    }
    for (int i = 2; i <= n; i += 2) {
        even_pos[prefix_xor[i]].emplace_back(i);
    }

    while (q--) {
        int L, R; cin >> L >> R;
        if ((prefix_xor[R] ^ prefix_xor[L-1]) != 0) {
            cout << -1 << "\n"; continue;
        }
        if (prefix_sum[R] - prefix_sum[L-1] == 0) {
            cout << 0 << "\n"; continue;
        }
        if (R - L + 1 < 3) {
            if (arr[L] == 0 && arr[R] == 0) {
                cout << 0 << "\n"; continue;
            } else {
                cout << -1 << "\n"; continue;
            }
        }
        if ((R - L + 1) % 2 == 1) {
            cout << 1 << "\n";
        } else {
            int target = prefix_xor[L-1];
            if (L % 2 == 0) {
                // find even
                if (arr[L] == 0 || arr[R] == 0) {
                    cout << 1 << "\n"; continue;
                }
                int cnt = 0;
                auto it = even_pos.find(target);
                if (it != even_pos.end()) {
                    auto &pos = it->second;
                    cnt = upper_bound(pos.begin(), pos.end(), R) - lower_bound(pos.begin(), pos.end(), L);
                }
                if (cnt == 0) {
                    cout << -1 << "\n";
                } else {
                    cout << 2 << "\n";
                }
            } else {
                // find odd
                if (arr[L] == 0 || arr[R] == 0) {
                    cout << 1 << "\n"; continue;
                }
                int cnt = 0;
                auto it = odd_pos.find(target);
                if (it != odd_pos.end()) {
                    auto &pos = it->second;
                    cnt = upper_bound(pos.begin(), pos.end(), R) - lower_bound(pos.begin(), pos.end(), L);
                }
                if (cnt == 0) {
                    cout << -1 << "\n";
                } else {
                    cout << 2 << "\n";
                }
            }
        }
    }
}

