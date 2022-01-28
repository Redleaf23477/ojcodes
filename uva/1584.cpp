#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        string str; cin >> str;
        string ans = str;
        for (size_t i = 0; i < str.size(); i++) {
            char f = str.front();
            for (size_t j = 0; j+1 < str.size(); j++) {
                str[j] = str[j+1];
            }
            str.back() = f;
            ans = min(ans, str);
        }
        cout << ans << endl;
    }
}

