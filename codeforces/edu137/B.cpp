#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        cout << 1 << " " << n;
        for (int i = 2; i < n; i++) cout << " " << i;
        cout << "\n";
    }
}

