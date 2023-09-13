#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    string S; cin >> S;
    if (S[0] == 'M') cout << 5 << "\n";
    else if (S == "Tuesday") cout << 4 << "\n";
    else if (S[0] == 'W') cout << 3 << "\n";
    else if (S[0] == 'T') cout << 2 << "\n";
    else if (S[0] == 'F') cout << 1 << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}