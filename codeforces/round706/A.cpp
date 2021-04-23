#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
using LL = long long int;

void solve() {
    int n, k; cin >> n >> k;
    string str; cin >> str;
    bool good = false;
    if (n%2 == 0) {
        for (int len = 0; n-2-2*len >= 2*k; len++) {
            // mid = [n/2-1-len, n/2+len]
            bool flag = true;
            for (int i = n/2-1-len-1, j = n/2+len+1; i >= 0; i--, j++) {
                if (str[i] != str[j]) { flag = false; break; }
            }
            if (flag) good = true;
        }
    } else {
        for (int len = 0; n-1-2*len >= 2*k; len++) {
            // mid = [(n/2)-len, (n/2)+len]
            bool flag = true;
            for (int i = n/2-len-1, j = n/2+len+1; i >= 0; i--, j++) {
                if (str[i] != str[j]) { flag = false; break; }
            }
            if (flag) good = true;
        }
    }
    cout << (good? "YES" : "NO") << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}


