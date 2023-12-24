#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n, q; cin >> n >> q;
    int sum = 0;
    vector<int> arr(n);
    set<int> one_pos;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
        if (arr[i] == 1) one_pos.insert(i);
    }
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int s; cin >> s;
            if (sum < s) {
                cout << "NO\n";
            } else {
                int must2 = sum;
                if (one_pos.size() == 1) {
                    int p = *one_pos.begin();
                    must2 = min(2 * p, 2 * (n - p - 1));
                } else if (one_pos.size() > 1) {
                    int p = *one_pos.begin();
                    must2 = min(must2, 2 * p);
                    p = *one_pos.rbegin();
                    must2 = min(must2, 2 * (n - p - 1));
                }
                int delta = sum - s;
                if (delta % 2 == 0) {
                    cout << "YES\n";
                } else if (delta < must2) {
                    cout << "NO\n";
                } else {
                    cout << "YES\n";
                }
            }
        } else {
            int pos, val; cin >> pos >> val; pos--;
            if (arr[pos] == val) continue;
            sum -= arr[pos];
            if (arr[pos] == 1) {
                one_pos.erase(pos);
            }
            if (val == 1) {
                one_pos.insert(pos);
            }
            arr[pos] = val;
            sum += arr[pos];
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

