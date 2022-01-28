#include <bits/stdc++.h>
using namespace std;

bool good(const string &str, size_t k) {
    for (size_t i = k; i < str.size(); i++) {
        if (str[i] != str[i%k]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        string str; cin >> str;
        for (size_t k = 1; k <= str.size(); k++) {
            if (str.size() % k == 0 && good(str, k)) {
                cout << k << endl; 
                break;
            }
        }
        if (T > 0) cout << endl;
    }
}

