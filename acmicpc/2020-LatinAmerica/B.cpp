#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;

    // calcuate max_inc
    vector<int> max_inc(n, -1);
    queue<int> q;
    for (int l = 0, r = 0; l < n; l++) {
        // pop outdated elements
        while (!q.empty() && q.front() < l) q.pop();
        // extend right
        for (; r < n; r++) {
            if (arr[r] == -1) {
                if (r == n-1) q.emplace(n-1);
            } else if (q.empty() || arr[r] >= arr[q.back()]) q.emplace(r);
            else break;
        }
        // update max_inc
        max_inc[l] = r - 1;
    }

    // calculate max_dec
    vector<int> max_dec(n, -1);
    q = queue<int>();
    for (int l = n-1, r = n-1; r >= 0; r--) {
        // pop outdated elements
        while (!q.empty() && q.front() > r) q.pop();
        // extend left
        for (; l >= 0; l--) {
            if (arr[l] == -1) {
                if (l == 0) q.emplace(0);
            } else if (q.empty() || arr[l] >= arr[q.back()]) q.emplace(l);
            else break;
        }
        // update max_dec
        max_dec[r] = l + 1;
    }

    // calculate answer
    bool ans = false;
    for (int len = 3; len <= n; len++) {
        bool good = true;
        for (int l = 0; l < n; l += len) {
            int r = min(n-1, l + len - 1);
            if (r - l + 1 < 3) good = false;
            if (max_inc[l] == l) good = false;
            if (max_dec[r] == r) good = false;
            if (max_inc[l] < max_dec[r]) good = false;
        }
        if (good) ans = true;
    }
    cout << (ans? "Y\n" : "N\n");
}

