#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using Edge = pair<LL,int>;
constexpr LL INF = 1e18;

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    sort(arr.begin(), arr.end());

    vector<LL> cnt;
    for (int i = 0, m = 0; i < n; m++) {
        if (m != arr[i]) break;
        int c = 0;
        while (i < n && arr[i] == m) c++, i++;
        cnt.emplace_back(c);
    }
    /*
    cerr << "cnt = ";
    for (auto x : cnt) cerr << x << " ";
    cerr << endl;
    */

    int m = cnt.size() + 1;
    vector<LL> sssp(m, INF);
    sssp[0] = 0;
    for (int u = 0; u < m; u++) {
        for (int v = u + 1; v < m; v++) {
            LL w = (cnt[u] - 1) * v + 1 * u;
            sssp[v] = min(sssp[v], sssp[u] + w);
        }
    }
    cout << sssp[m - 1] << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
}

