#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    LL x; cin >> x;
    if (x >= 0) {
        cout << x / 10 << "\n";
    } else {
        cout << (x - 9) / 10 << "\n";
    }
}

