#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n, k; cin >> n >> k;
    vector<LL> arr(n);
    for (auto &x : arr) cin >> x;

    // kill single 1
    for (int i = 1; i + 1 < n && k > 0; i++) {
        if (arr[i] == 1 && arr[i - 1] != 1 && arr[i + 1] != 1) {
            // cerr << "kill single 1: " << i << endl;
            arr[i] = 0, k--;
        }
    }

    vector<int> two, one;
    vector<pair<int,int>> seg1, seg;
    const int SEG1 = 1, SEG = 2, NONE = 0;
    int l = -1, r = -1, state = NONE;
    auto push = [&]() {
        if (state == SEG1) {
            seg1.emplace_back(l, r);
        } else if (state == SEG) {
            seg.emplace_back(l, r);
        }
        l = r = -1, state = NONE;
    };
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            push();
        } else if (arr[i] == 1) {
            if (state != SEG1) {
                push();
                l = i, r = i, state = SEG1;
            } else {
                r++;
            }
        } else if (i + 1 < n && arr[i + 1] != 1 && gcd(arr[i], arr[i + 1]) == 1) {
            if (state != SEG) {
                push();
                l = i, r = i + 1, state = SEG;
            } else {
                r++;
            }
        } else {
            push();
        }
    }
    push();

    for (auto [l, r] : seg) {
        for (int i = l + 1; i <= r; i += 2) {
            if (i == r) one.emplace_back(i);
            else two.emplace_back(i);
        }
    }
    sort(seg1.begin(), seg1.end(), [&](pair<int,int> const &lhs, pair<int,int> const &rhs) {
        LL len1 = lhs.second - lhs.first + 1;
        LL len2 = rhs.second - rhs.first + 1;
        LL val1 = len1 + 1 - (lhs.first == 0) - (lhs.second == n - 1);
        LL val2 = len2 + 1 - (rhs.first == 0) - (rhs.second == n - 1);
        if (val1 * len2 != val2 * len1) return val1 * len2 > val2 * len1;
        else if (lhs.first != rhs.first) return lhs.first < rhs.first;
        else return lhs.second < rhs.second;
    });

    /*
    cerr << "seg: ";
    for (auto [l, r] : seg) {
        cerr << "[" << l << ", " << r << "]";
    }
    cerr << endl;
    cerr << "seg1: ";
    for (auto [l, r] : seg1) {
        cerr << "[" << l << ", " << r << "]";
    }
    cerr << endl;
    */

    // deal with two
    for (auto x : two) {
        if (k == 0) break;
        arr[x] = 0, k--;
        // cerr << "kill two: " << x << endl;
    }
    // deal with 1-seg
    for (auto [l, r] : seg1) {
        if (l != 0) {
            for (int i = l; i <= r && k > 0; i++) {
                arr[i] = 0, k--;
                // cerr << "kill 1-seg: " << i << endl;
            }
        } else {
            for (int i = r; i >= l && k > 0; i--) {
                arr[i] = 0, k--;
                // cerr << "kill 1-seg: " << i << endl;
            }
        }
    }
    // deal with one
    for (auto x : one) {
        if (k == 0) break;
        arr[x] = 0, k--;
        // cerr << "kill one: " << x << endl;
    }

    // calcuate answer
    int ans = 0;
    for (int i = 0; i + 1 < n; i++) {
        if (gcd(arr[i], arr[i + 1]) == 1) {
            ans++;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

