#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int xor_sum = 0;
        while (n--) {
            int x; cin >> x;
            xor_sum ^= x;
        }
        cout << (xor_sum == 0? "second\n" : "first\n");
    }
}

