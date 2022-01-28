#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        string str; cin >> str;
        int ans = 0;
        for (size_t i = 0, c = 0; i < str.size(); i++) {
            if (str[i] == 'O') c += 1;
            else c = 0;
            ans += c;
        }
        cout << ans << endl;
    }
}

