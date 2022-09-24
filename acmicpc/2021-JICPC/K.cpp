#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    vector<LL> len {0, 2};
    for (int i = 2; i <= 30; i++) {
        len.emplace_back(len.back() + i * (1ll << (i-1)));
    }

    /*
    for (int i = 0; i <= 30; i++) {
        cerr << i << " : " << len[i] << endl;
    }
    */

    int T; cin >> T;
    while (T--) {
        int k; cin >> k;
        int ans = 0;

        for (int i = 1; i <= 30; i++) {
            if (k < len[i]) break;
            if (k >= len[i]) ans = max(ans, i);
            if (k > len[i]) ans = max(ans, i + 1);
        }

        cout << ans << "\n";
    }
}

