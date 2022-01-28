#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int query(int c) {
    cout << "+ " << c << endl;
    int res; cin >> res;
    return res;
}

void guess(int ans, int q_sum) {
    cout << "! " << ans + q_sum << endl;
}

bool ans_lt(int mid, int &q_sum, int n) {
    // cerr << "mid = " << mid << endl;
    int r = q_sum % n;
    int c = n - mid - r;
    if (c < 0) c += n;
    int res = query(c);
    q_sum += c;
    res -= q_sum / n;


    return res == 0;
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    int l = 1, r = n-1, mid, ans = -1;
    int q_sum = 0;
    while (l <= r) {
        mid = (l + r)/2;
        if (ans_lt(mid, q_sum, n)) r = mid - 1;
        else ans = mid, l = mid + 1;  // x >= mid
    }
    guess(ans, q_sum);
}

