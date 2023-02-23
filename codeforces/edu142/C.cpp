#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        pos[x-1] = i;
    }

    int ans_l = 0, ans_r = 0;
    int l = n / 2 - 1;
    int r = (n % 2 == 0? n / 2 : n / 2 + 1);
    int prev_pos = 0;

    int fix = (n % 2 == 0 && pos[l] > pos[r]);

    if (n % 2 == 0) {
        if (fix) prev_pos = -1;
        else prev_pos = pos[l];
        l--;
    } else {
        prev_pos = pos[n/2];
    }
    for (; l >= 0; l--) {
        int lpos = pos[l];
        if (lpos > prev_pos) {
            ans_l++;
            prev_pos = -1;
        } else {
            prev_pos = lpos;
        }
    }

    if (n % 2 == 0) {
        if (fix) prev_pos = n;
        else prev_pos = pos[r];
        r++;
    } else {
        prev_pos = pos[n/2];
    }
    for (; r < n; r++) {
        int rpos = pos[r];
        if (rpos < prev_pos) {
            ans_r++;
            prev_pos = n;
        } else {
            prev_pos = rpos;
        }
    }

    cout << max(ans_l, ans_r) + fix << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

