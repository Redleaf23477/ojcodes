#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void test(int n) {
    vector<int> arr(n);
    /*
    for (int i = 1; i < n; i += 2) {
        arr[i-1] = i + 1;
        arr[i] = i;
    }
    */

    auto good = [&]() {
        /*
        cerr << "test: ";
        for (auto x : arr) cerr << x << " ";
        cerr << endl;
        */
        set<int> s(arr.begin(), arr.end());
        if (s.size() != n) return false;
        if (*s.begin() != 1) return false;
        if (*s.rbegin() != n) return false;
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                int sum = 0;
                for (int j = 0; j < len; j++) {
                    sum += arr[i+j];
                }
                if (sum % len == 0) return false;
            }
        }
        return true;
    };
    /*
    cerr << "n = " << n << endl;
    for (auto x : arr) cerr << x << " ";
    cerr << endl;
    assert(good());
    */
    iota(arr.begin(), arr.end(), 1);
    do {
        if (good()) {
            for (auto x : arr) cout << x << " ";
            cout << "\n";
        }
    } while (next_permutation(arr.begin(), arr.end()));
}

void solve() {
    int n; cin >> n;
    if (n == 1) cout << 1 << "\n";
    else if (n == 2) cout << 1 << " " << 2 << "\n";
    else if (n % 2 == 1) cout << -1 << "\n";
    else {
        vector<int> arr(n);
        for (int i = 1; i < n; i += 2) {
            arr[i-1] = i + 1;
            arr[i] = i;
        }
        for (auto x : arr) cout << x << " ";
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    /*
       cerr << "=== 2 ===" << endl;
       test(2);
       cerr << "=== 4 ===" << endl;
       test(4);
       cerr << "=== 6 ===" << endl;
       test(6);
       cerr << "=== 8 ===" << endl;
       test(8);
       */
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



