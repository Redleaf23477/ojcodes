#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        if (n % 2 == 0) {
            for (int i = 1; i < n - 1; i += 2) {
                cout << i + 1 << " " << i << " ";
            }
        } else {
            cout << 1 << " " << 2 << " " << 3 << " ";
            for (int i = 4; i < n - 1; i += 2) {
                cout << i + 1 << " " << i << " ";
            }
        }
        cout << n - 1 << " " << n << "\n";
    }
}

