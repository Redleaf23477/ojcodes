#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    string str; cin >> str;
    int n = str.size();
    int ans = 0;
    for (int i = 0, c = 0; i < n; i++) {
        if (i == 0 || str[i] != str[i-1]) {
            c = 1;
        } else if (str[i] == str[i-1]) {
            c += 1;
        }
        ans = max(ans, c);
    }
    cout << ans << endl;
}

