#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    const int N = 1000006;
    vector<int> sp(N);
    iota(sp.begin(), sp.end(), 0);
    for (int i = 2; i < N / i; i++) {
        if (sp[i] == i) {
            for (int j = i * i; j < N; j += i) {
                if (sp[j] == j) sp[j] = i;
            }
        }
    }
    int n; cin >> n;
    while (n--) {
        int m; cin >> m;
        map<int,int> pd;
        while (m > 1) {
            pd[sp[m]] += 1;
            m /= sp[m];
        }
        LL ans = 1;
        for (auto [x, cnt] : pd) {
            ans *= cnt + 1;
        }
        cout << ans << "\n";
    }
}