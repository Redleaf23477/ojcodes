#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        LL a, b, c; cin >> a >> b >> c;
        LL tmp;
        
        // a
        tmp = b - (c - b);
        if (tmp % a == 0 && tmp / a > 0) {
            cout << "Yes" << endl; continue;
        }
        // b
        if ((c - a) % 2 == 0) {
            tmp = (a + c) / 2;
            if (tmp % b == 0 && tmp / b > 0) {
                cout << "Yes" << endl; continue;
            }
        }
        // c
        tmp = b + (b - a);
        if (tmp % c == 0 && tmp / c > 0) {
            cout << "Yes" << endl; continue;
        }

        cout << "No" << endl;
    }
}

