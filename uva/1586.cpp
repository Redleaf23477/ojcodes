#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    vector<double> mass(26, 0);
    mass['C' - 'A'] = 12.01;
    mass['H' - 'A'] = 1.008;
    mass['O' - 'A'] = 16.00;
    mass['N' - 'A'] = 14.01;

    int T; cin >> T;
    while (T--) {
        string str; cin >> str;
        double ans = 0;
        int n = str.size();
        str.push_back('X');
        for (int i = 0; i < n; i++) {
            char elem = str[i];
            int buff = 0;
            while (isdigit(str[i+1])) {
                i += 1;
                buff = buff * 10 + (str[i] - '0');
            }
            if (buff == 0) buff = 1;
            ans += mass[elem - 'A'] * buff;
        }
        cout << fixed << setprecision(3) << ans << endl;
    }
}

