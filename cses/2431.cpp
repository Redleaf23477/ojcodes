#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

constexpr int N = 19;

vector<LL> digit_cnt(N), num_cnt(N);

int get_len(LL num) {
    int ans = 0;
    while (num > 0) {
        ans += 1, num /= 10;
    }
    return ans;
}

pair<int,int> good(LL num, LL k) {
    int len = get_len(num);
    LL acc = digit_cnt[len - 1];
    acc += (num - num_cnt[len-1] - 1) * len;
    // cerr << "num = " << num << ", len = " << len << ", acc = " << acc << endl;
    if (acc < k && k <= acc + len) {
        k -= acc;
        int div = len - k;
        while (div--) num /= 10;
        return make_pair(num % 10, 1);
    } else if (acc + len < k) {
        return make_pair(-1, 0);
    } else {
        return make_pair(-1, 1);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie();

    num_cnt[0] = 0, num_cnt[1] = 9;
    for (int i = 2; i < N; i++) {
        num_cnt[i] = 10 * num_cnt[i-1];
    }

    digit_cnt[0] = 0;
    for (int i = 1; i < N; i++) {
        digit_cnt[i] = digit_cnt[i-1] + i * num_cnt[i];
    }

    for (int i = 1; i < N; i++) num_cnt[i] += num_cnt[i-1];

    /*
    for (int i = 0; i < 5; i++) {
        cerr << "len = " << i 
            << ", num_cnt = " << num_cnt[i] 
            << ", acc_digit_cnt = " << digit_cnt[i] << endl;
    }
    */

    int T; cin >> T;
    while (T--) {
        LL k; cin >> k;
        LL l = 1, r = 1e18, mid; 
        int ans = -1;
        while (l <= r) {
            mid = (l + r) / 2;
            auto [digit, res] = good(mid, k);
            // cerr << "mid = " << mid << ", d = " << digit << ", res = " << res << endl;
            if (digit != -1) {
                ans = digit; break;
            }
            if (res) r = mid - 1;
            else l = mid + 1;
        }
        cout << ans << "\n";
    }
}

