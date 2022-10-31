#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void trim(string &str) {
    auto pos = find(str.begin(), str.end(), '1') - str.begin();
    str = str.substr(pos);
}

void update(string const &str, int L, int len, string &best) {
    int n = str.size();
    string tmp = str;
    for (int i = n - len, j = L; i < n; i++, j++) {
        if (str[j] == '1') tmp[i] = '1';
    }
    if (tmp > best) best = tmp;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    string str; cin >> str; trim(str);
    n = str.size();
    auto zp = find(str.begin(), str.end(), '0') - str.begin();
    int len = n - zp;
    string best = str;
    for (int i = 0; i + len <= n; i++) {
        update(str, i, len, best);
    }
    if (best.size() == 0) best = "0";
    cout << best << "\n";
}

