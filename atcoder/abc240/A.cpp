#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int a, b; cin >> a >> b;
    if (a > b) swap(a, b);
    if (a + 1 == b) cout << "Yes\n";
    else if (a == 1 && b == 10) cout << "Yes\n";
    else cout << "No\n";
}

