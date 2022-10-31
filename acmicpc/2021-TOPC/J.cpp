#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string lhs, rhs; cin >> lhs >> rhs;
    auto is_nan = [](string s) {
        for (auto c : s) {
            if (!isdigit(c)) return true;
        }
        return false;
    };
    auto num = [](string s) {
        stringstream ss(s);
        LL ans; ss >> ans;
        return ans;
    };
    if (is_nan(lhs) || is_nan(rhs)) {
        cout << "NaN\n";
    } else {
        cout << num(lhs) - num(rhs) << "\n";
    }
}

