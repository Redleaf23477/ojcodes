#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    LL k; cin >> k;
    string ans;
    for (; k > 0; k >>= 1) {
        if (k & 1) ans.push_back('2');
        else ans.push_back('0');
    }
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
}

