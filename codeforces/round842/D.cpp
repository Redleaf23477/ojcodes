#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

struct DSU {
    int n;
    vector<int> pa;
    DSU(int _n): n(_n), pa(n, -1) {
        iota(pa.begin(), pa.end(), 0);
    }
    int findrt(int x) {
        if (pa[x] == x) return x;
        else return pa[x] = findrt(pa[x]);
    }
    bool same(int x, int y) {
        return findrt(x) == findrt(y);
    }
    void uni(int x, int y) {
        pa[findrt(x)] = findrt(y);
    }
};

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) { cin >> x; x--; }

    DSU dsu(n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        while (arr[i] != i) {
            dsu.uni(arr[i], arr[arr[i]]);
            swap(arr[i], arr[arr[i]]);
            cnt++;
        }
    }

    bool discount = false;
    for (int i = 0; i + 1 < n; i++) {
        if (dsu.same(i, i+1)) discount = true;
    }

    cout << cnt + (discount? -1 : 1) << "\n";


}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

