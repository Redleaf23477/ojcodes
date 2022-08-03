#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; 
    while (cin >> n && n) {
        int a = 0, b = 0;
        for (int i = 0, cnt = 0; i < 32; i++) {
            if ((n >> i) & 1) {
                cnt = 1 - cnt;
                if (cnt == 1) a |= (1 << i);
                else b |= (1 << i);
            }
        }
        cout << a << " " << b << "\n";
    }
}

