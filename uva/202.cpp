#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int a, b;
    while (cin >> a >> b) {
        int cyc_len = 0;
        vector<int> rem(b, -1);
        int i, r;
        for (i = 0, r = a % b; rem[r] == -1; i++) {
            rem[r] = i;
            r = r * 10 % b;
        }
        cyc_len = i - rem[r];
        cout << a << "/" << b << " = " << a/b << ".";

        int printed = 0;
        for (int r2 = a % b; r2 != r; r2 = r2 * 10 % b) {
            cout << r2 * 10 / b;
            printed += 1;
        }
        cout << "(";
        for (int i = 0; i < cyc_len; i++) {
            if (printed == 50) {
                cout << "...";
                break;
            }
            cout << r * 10 / b;
            r = r * 10 % b;
            printed += 1;
        }
        cout << ")" << endl;
        cout << "   " << cyc_len << " = number of digits in repeating cycle" << endl;
        cout << endl;
    }
}

