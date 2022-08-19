#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

bool all_a(string &str) {
    return str == string(str.size(), 'a');
}

void dec(string &str) {
    int i;
    for (i = str.size() - 1; i >= 0; i--) {
        if (str[i] != 'a') break;
    }
    str[i]--;
    for (int j = i + 1; j < (int)str.size(); j++) {
        str[j] = 'z';
    }
}

void add_z(string &str, int m) {
    str = str + string(m - str.size(), 'z');
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    string str; cin >> str;
    if (str.back() == 'a') {
        cout << str.substr(0, n-1) << "\n";
    } else {
        dec(str);
        add_z(str, m);
        cout << str << "\n";
    }
}

