#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL E12 = 1e12;

LL good(LL op_num, vector<LL> const &one_pos_suff, int n) {
    // bs on kept one
    LL low = 0, high = one_pos_suff.size(), ans = n * E12 + n, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        // LL swap_num = (n-1 + ... + n-mid) - suffix_sum(last mid one);
        LL swap_num = ((n+n-1-mid) * mid / 2) - (mid == 0? 0 : one_pos_suff[one_pos_suff.size()-mid]);
        LL kill_num = one_pos_suff.size() - mid;
        if (swap_num + kill_num <= op_num) {
            ans = swap_num * E12 + kill_num * (E12 + 1);
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

void solve() {
    string str; cin >> str;
    int n = str.size();
    vector<LL> one_pos;
    for (int i = 0; i < n; i++) {
        if (str[i] == '1') one_pos.emplace_back(i);
    }
    for (int i = one_pos.size() - 2; i >= 0; i--) {
        one_pos[i] += one_pos[i+1];
    }
    // bs on op num
    // ans is lowest cost
    LL low = 0, high = n, ans = n * E12 + n, mid = 0;
    while (low <= high) {
        mid = (low + high) / 2;
        LL res = good(mid, one_pos, n);
        if (res == -1) {
            low = mid + 1;
        } else {
            ans = res;
            high = mid - 1;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



