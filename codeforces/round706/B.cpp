#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
using LL = long long int;

void solve() {
    LL n, k; cin >> n >> k;
    vector<LL> arr(n); for (auto &x : arr) cin >> x;
    set<LL> s(arr.begin(), arr.end());
    auto it = s.end(); it--;
    LL mx = *it;
    if (k == 0) {
        cout << s.size() << endl;
    } else if (mx == s.size()-1) {
        cout << s.size()+k << endl;
    } else {
        LL mex = 0;
        for (auto x : s) {
            if (x == mex) mex++;
            else break;
        }
        s.insert((mx+mex+1)/2);
        cout << s.size() << endl;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}


