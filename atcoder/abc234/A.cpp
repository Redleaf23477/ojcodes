#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int f(int x) {
    return x * x + 2 * x + 3; 
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    cout << f(f(f(t) + t) + f(f(t))) << "\n";
}

