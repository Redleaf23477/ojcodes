#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    vector<bool> group(n+1, false);
    vector<LL> sum(2, 0), sz(2, 0);
    for (int i = n; i > 0; i--) {
        if (sum[0] < sum[1]) {
            group[i] = 0;
            sum[0] += i;
            sz[0] += 1;
        } else {
            group[i] = 1;
            sum[1] += i;
            sz[1] += 1;
        }
    }
    if (sum[0] == sum[1]) {
        cout << "YES\n";
        for (int g = 0; g < 2; g++) {
            cout << sz[g] << "\n";
            for (int i = 1; i <= n; i++) {
                if (group[i] == g) cout << i << " ";
            }
            cout << "\n";
        }
    } else {
        cout << "NO\n";
    }
}

