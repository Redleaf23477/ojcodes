#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        LL r, c; cin >> r >> c;
        LL layer = max(r, c);
        if (layer % 2 == 0) {
            if (layer == r) {
                cout << layer * layer - c + 1 << "\n";
            } else {
                cout << (layer-1) * (layer-1) + r << "\n";
            }
        } else {
            if (layer == r) {
                cout << (layer-1) * (layer-1) + c << "\n";
            } else {
                cout << layer * layer - r + 1 << "\n";
            }
        }
    }
}

