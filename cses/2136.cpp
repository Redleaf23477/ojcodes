#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    vector<int> arr(n, 0);
    for (auto &x : arr) {
        string bits; cin >> bits;
        for (auto ch : bits) {
            x <<= 1;
            x += ch - '0';
        }
    }
    int dist = k;
    for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
        dist = min(dist, __builtin_popcount(arr[i] ^ arr[j]));
    }
    cout << dist << "\n";
}

