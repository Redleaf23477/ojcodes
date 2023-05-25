#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n, m; cin >> n >> m;
    int L = 0, R = 0;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x == -1) L++;
        else if (x == -2) R++;
        else arr.emplace_back(x);
    }
    sort(arr.begin(), arr.end());
    auto it = unique(arr.begin(), arr.end());
    arr.erase(it, arr.end());
    n = arr.size();

    int ans = 0;

    // case 1: sit from 1 (use R)
    auto try_R = [m](vector<int> const &arr, int R) {
        int ans = 0, l = 0;
        for (auto x : arr) {
            int space = x - l - 1;
            int use = min(R, space);
            R -= use;
            ans += 1 + use;
            l = x;
        }
        int space = m - l;
        ans += min(space, R);
        return ans;
    };
    ans = max(ans, try_R(arr, R));

    // case 2: sit fromt m (use L)
    auto try_L = [m](vector<int> arr, int L) {
        reverse(arr.begin(), arr.end());
        int ans = 0, r = m;
        for (auto x : arr) {
            int space = r - x;
            int use = min(L, space);
            L -= use;
            ans += 1 + use;
            r = x - 1;
        }
        ans += min(r, L);
        return ans;
    };
    ans = max(ans, try_L(arr, L));


    // case 3: sit from middle
    for (int i = 0; i < n; i++) {
        int left_space = arr[i] - 1;
        int right_space = m - arr[i];

        int left_buddy = L + i;
        int right_buddy = R + n - i - 1;

        /*
        cerr << "i = " << i << ", arr[i] = " << arr[i] << endl;
        cerr << "left = " << left_space << ", " << left_buddy << endl;
        cerr << "right = " << right_space << ", " << right_buddy << endl;
        */

        ans = max(ans, 1 + min(left_space, left_buddy) + min(right_space, right_buddy));
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



