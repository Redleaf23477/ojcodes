#include <bits/stdc++.h>
const int MAXN = 1000005;
const int LOG = 21;
#define int long long
#define PII pair<int, int>
#define fi first
#define se second
using namespace std;

int n, a[MAXN], link[LOG][MAXN];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }

    for (int i = 0; i < LOG; i++) {
        for (int j = 0; j < 2 * n; j++) {
            link[i][j] = -1;
        }
    }

    vector<PII> stk;
    for (int i = 0; i < 2 * n; i++) {
        if (!stk.empty()) {
            int l = 0, r = stk.size() - 1, res = -1;
            while (l <= r) {
                int m = (l + r) / 2;
                if (stk[m].fi >= i - a[i]) {
                    r = m - 1;
                    res = m;
                }
                else {
                    l = m + 1;
                }
            }
            link[0][i] = stk[res].fi;
        }
//        cerr << "Sheep say: " << i << " to " << link[0][i] << '\n';
        while (!stk.empty() && stk.back().se >= i - a[i]) {
            stk.pop_back();
        }
        stk.push_back(PII(i, i - a[i]));
    }

    //	cout << "Here" << endl;
    for (int i = 1; i < LOG; i++) {
        for (int j = 0; j <= 2 * n; j++) {
            if (link[i - 1][j] != -1) {
                link[i][j] = link[i - 1][link[i - 1][j]];
            }
        }
    }

    int ans = 0;
    for (int i = n; i < 2 * n; i++) {
        int tgt = i - n + 1;
        if (i - a[i] <= tgt) {
            ans++;
            cerr << "[start=" << i << "]" << "[mn=" << 1 << "]" << endl;
        }
        else {
            int cur = i, dist = 0;
            for (int j = LOG - 1; j >= 0; j--) {
                if (link[j][cur] == -1) {
                    continue;
                }
                int to = link[j][cur];
                if (to - a[to] > tgt) {
                    //cout << "At " << i << ' ' << j << " " << to << '\n';
                    dist += (1 << j);
                    cur = to;
                }
            }

            dist += 2;
            ans += dist;
            cerr << "[start=" << i << "]" << "[mn=" << dist << "]" << endl;
        }
    }

    cout << ans << '\n';

    return 0;
} 

