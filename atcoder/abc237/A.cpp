#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    LL a; cin >> a;
    if (-(1ll<<31) <= a && a <= (1ll<<31) - 1) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

