#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        int x; cin >> x;
        cout << "Division ";
        if (1900 <= x) cout << 1;
        else if (1600 <= x) cout << 2;
        else if (1400 <= x) cout << 3;
        else cout << 4;
        cout << "\n";
    }
}

