#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    // init sp
    const int N = 1000001;
    vector<int> sp(N, 0);
    iota(sp.begin(), sp.end(), 0);
    for (LL i = 2; i < N; i++) {
        if (sp[i] != i) continue;
        for (LL j = i * i; j < N; j += i) {
            if (sp[j] == j) sp[j] = i;
        }
    }
    // input
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) {
        cin >> x;
    }
    auto decomp = [&](int x) {
        set<int> ans;
        while (x > 1) {
            ans.insert(sp[x]);
            x /= sp[x];
        }
        return vector<int>(ans.begin(), ans.end());
    };
    vector<int> vis(N, 0);
    for (auto x : arr) vis[x] = 2;
    for (size_t i = 0; i < arr.size(); i++) {
        int x = arr[i];
        auto f_arr = decomp(x);
        for (auto f : f_arr) {
            int y = x / f;
            if (vis[y] == 2) continue;
            vis[y] += 1;
            if (vis[y] == 2) arr.emplace_back(y);
        }
    }
    /*
    for (auto x : arr) {
        vis[x] = 2;
    }
    */

    /*
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (vis[i] >= 2) {
            cerr << "report " << i << endl;
            ans += 1;
        }
    }
    */
    cout << arr.size() - n << endl;
}

