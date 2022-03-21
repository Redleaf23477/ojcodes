#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n, q; cin >> n >> q;
    vector<int> arr(n), pos(n+1);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        pos[arr[i]] = i;
    }
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        if (i != 1) ans += (pos[i-1] > pos[i]);
    }
    while (q--) {
        int x, y; cin >> x >> y;
        if (x == y) {
            cout << ans << "\n";
            continue;
        }
        int a = arr[x-1], b = arr[y-1];

        if (a > b) swap(a, b);
        
        int l = min(pos[a], pos[b]), r = max(pos[a], pos[b]);
        if (a - 1 >= 1) {
            if (l < pos[a-1] && pos[a-1] < r) {
                if (pos[a] > pos[a-1]) ans += 1;
                else ans -= 1;
            }
        }
        if (b + 1 <= n) {
            if (l < pos[b+1] && pos[b+1] < r) {
                if (pos[b] > pos[b+1]) ans -= 1;
                else ans += 1;
            }
        }
        if (b - a > 1) {
            // a + 1
            if (l < pos[a+1] && pos[a+1] < r) {
                if (pos[a] > pos[a+1]) ans -= 1;
                else ans += 1;
            }
            // b - 1
            if (l < pos[b-1] && pos[b-1] < r) {
                if (pos[b] > pos[b-1]) ans += 1;
                else ans -= 1;
            }
        } else {
            // a + 1 == b
            if (pos[a] < pos[b]) ans += 1;
            else ans -= 1;
        }
        swap(pos[a], pos[b]);
        swap(arr[x-1], arr[y-1]);

        cout << ans << "\n";
    }
}

