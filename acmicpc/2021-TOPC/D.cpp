#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    double n; cin >> n;
    cout << fixed << setprecision(10) << 1.0 / (n - 1) + (n - 2) / (n - 1) * 0.5 << endl;
}

