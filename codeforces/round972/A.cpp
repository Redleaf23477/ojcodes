#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n; cin >> n;
    int q = n / 5;
    int r = n % 5;
    vector<char> vowel = {'a', 'e', 'i', 'o', 'u'};
    for (int i = 0; i < 5; i++) {
        char ch = vowel[i];
        cout << string(q, ch);
        if (i < r) cout << ch;
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

