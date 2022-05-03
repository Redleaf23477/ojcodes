#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    constexpr int N = 1000000;

    vector<int> sp(N+1);
    iota(sp.begin(), sp.end(), 0);
    for (int i = 2; i <= N / i; i++) {
        if (sp[i] == i) {
            for (int j = i * i; j <= N; j += i) {
                if (sp[j] == j) sp[j] = i;
            }
        }
    }

    LL n; cin >> n;
    vector<int> vis(N+1, 0);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        vis[x] += 1;
    }

    auto is_good_number = [&](int x) {
        set<int> p;
        for (; x > 1; x /= sp[x]) {
            if (p.count(sp[x]) != 0) return -1;
            p.insert(sp[x]);
        }
        return (int)p.size();
    };

    LL ans = 0;
    for (int i = 2; i <= N; i++) {
        if (sp[i] == i) {
            LL cnt = 0;
            for (int j = i; j <= N; j += i) {
                cnt += vis[j];
            }
            ans += cnt * (cnt - 1) / 2;
        } else {
            int x = is_good_number(i);
            if (x == -1) continue;
            LL cnt = 0;
            for (int j = i; j <= N; j += i) {
                cnt += vis[j];
            }
            ans += (x % 2 == 0? -1 : 1) * cnt * (cnt - 1) / 2;
        }
    }
    cout << n * (n-1) / 2 - ans << "\n";
}