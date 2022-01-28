#include <bits/stdc++.h>
using namespace std;

struct BigInt {
    using LL = long long int;
    static constexpr LL BASE = 1e8, WIDTH = 8;
    vector<LL> num;

    // constructors
    BigInt(string str) {
        while (str.size() > WIDTH) {
            num.emplace_back(atoll(str.substr(str.size() - WIDTH).c_str()));
            str.erase(str.size() - WIDTH);
        }
        if (str.size() > 0) {
            num.emplace_back(atoll(str.c_str()));
        }
    }

    BigInt() : num(1, 0) { }

    // operators
    BigInt operator + (BigInt rhs) {
        BigInt ans = *this;
        // add
        for (size_t i = 0; i < rhs.num.size(); i++) {
            if (ans.num.size() == i) ans.num.emplace_back(0);
            ans.num[i] += rhs.num[i];
        }
        // carry
        for (size_t i = 0; i < ans.num.size(); i++) {
            if (ans.num[i] >= BASE) {
                if (ans.num.size() == i+1) ans.num.emplace_back(0);
                ans.num[i+1] += ans.num[i] / BASE;
                ans.num[i] %= BASE;
            }
        }
        return ans;
    }
};

// ostream
ostream& operator << (ostream &out, BigInt &n) {
    out << n.num.back();
    for (int i = n.num.size() - 2; i >= 0; i--) {
        out << setw(n.WIDTH) << setfill('0') << n.num[i];
    }
    return out;
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        string a, b; cin >> a >> b;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        BigInt num = BigInt(a) + BigInt(b);

        stringstream ss; ss << num;
        string ans; ss >> ans;
        while (ans.back() == '0') ans.pop_back();
        reverse(ans.begin(), ans.end());

        cout << ans << endl;
    }
}
