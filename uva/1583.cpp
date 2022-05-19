#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int add(int n) {
    int ans = n;
    while (n > 0) {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

constexpr int INF = 1e9, N = 100000;
vector<int> gen(N+100, INF);

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    for (int i = 0; i < N; i++) {
        int g = add(i);
        gen[g] = min(gen[g], i);
    }
    int q; cin >> q;
    while (q--) {
        int n; cin >> n;
        if (gen[n] == INF) cout << 0 << endl;
        else cout << gen[n] << endl;
    }
}