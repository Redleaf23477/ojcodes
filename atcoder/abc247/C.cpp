#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void f(int n) {
    if (n == 1) {
        cout << 1 << " ";
        return;
    }
    f(n-1);
    cout << n << " ";
    f(n-1);
}

void solve() {
    int N; cin >> N; 
    f(N);
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



