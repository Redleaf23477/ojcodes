#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int ans = 1;
    char ch; cin >> ch; ans *= (ch - '0');
    cin >> ch;
    cin >> ch; ans *= (ch - '0');
    cout << ans << endl;
}