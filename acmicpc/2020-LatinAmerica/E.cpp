#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void relabel(vector<int> &arr) {
    vector<int> tmp(arr);
    sort(tmp.begin(), tmp.end());
    auto it = unique(tmp.begin(), tmp.end());
    tmp.erase(it, tmp.end());
    for (auto &x : arr) {
        x = lower_bound(tmp.begin(), tmp.end(), x) - tmp.begin();
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    relabel(arr);

    vector<int> val2pos(n);
    for (int i = 0; i < n; i++) {
        val2pos[arr[i]] = i;
    }

    set<int> pos;
    vector<int> sweep(n+1, 0);
    for (int val = n-1; val >= 0; val--) {
        int p = val2pos[val];
        int succ_pos = n, pred_pos = -1;
        auto it = pos.upper_bound(p);
        if (it != pos.end()) {
            succ_pos = *it;
        }
        if (it != pos.begin()) {
            it--;
            pred_pos = *it;
        }
        int L = 0, R = n;
        if (pred_pos != -1) {
            L = (pred_pos + p) / 2 + 1;
        }
        if (succ_pos != n) {
            R = (succ_pos + p + 1) / 2;
        }
        sweep[L] += 1, sweep[R] += -1;

        // cerr << "val = " << val << ", L = " << L << ", R = " << R << endl;

        pos.insert(p);
    }

    for (int i = 1; i <= n; i++) {
        sweep[i] += sweep[i-1];
    }

    for (int i = 0; i < n; i++) {
        cout << sweep[i] - 1 << " ";
    }
    cout << "\n";
}

