#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    LL A, B, C, X; cin >> A >> B >> C >> X;
    if (X <= A) cout << 1 << "\n";
    else if (X <= B) cout << fixed << setprecision(10) << (double)C / (B - A) << "\n";
    else cout << 0 << "\n";
}



