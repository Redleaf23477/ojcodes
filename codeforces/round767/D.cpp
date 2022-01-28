#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

bool solve() {
    int n; cin >> n;
    vector<string> arr(n);
    for (auto &x : arr) cin >> x;

    // obvious palindroms
    for (auto s : arr) {
        if (s.size() == 1) return true;
        if (s.size() == 2 && s[0] == s[1]) return true;
        if (s.size() == 3 && s.front() == s.back()) return true;
    }

    map<string,int> rev2, rev3, rev3_2;
    for (auto s : arr) {
        if (s.size() == 2) {
            reverse(s.begin(), s.end());
            rev2[s] += 1;
        } else {
            reverse(s.begin(), s.end());
            rev3[s] += 1;
            s.pop_back();
            rev3_2[s] += 1;
        }
    }

    /*
    cerr << "rev2" << endl;
    for (auto [x, _] : rev2) cerr << x << endl;
    cerr << "rev3" << endl;
    for (auto [x, _] : rev3) cerr << x << endl;
    cerr << "rev3_2" << endl;
    for (auto [x, _] : rev3_2) cerr << x << endl;
    */

    for (auto s : arr) {
        if (s.size() == 2) {
            if (rev2.count(s) != 0) return true;
            if (rev3_2.count(s) != 0) return true;

            reverse(s.begin(), s.end());
            rev2[s] -= 1;
            if (rev2[s] == 0) rev2.erase(s);
        } else {
            string tmp = s; reverse(tmp.begin(), tmp.end());
            if (rev3.count(s) != 0) return true;
            rev3[tmp] -= 1;
            if (rev3[tmp] == 0) rev3.erase(tmp);

            s = s.substr(0, 2);
            if (rev2.count(s) != 0) return true;
            tmp.pop_back();
            rev3_2[tmp] -= 1;
            if (rev3_2[tmp] == 0) rev3_2.erase(tmp);
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        cout << (solve()? "YES" : "NO") << "\n";
    }
}

