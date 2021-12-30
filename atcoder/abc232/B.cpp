#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string a, b; cin >> a >> b;
    int d = (b[0] - a[0] + 26) % 26;
    for (size_t i = 0; i < a.size(); i++) {
        int x = a[i] - 'a' + d;
        if (x >= 26) x -= 26;
        int y = b[i] - 'a';
        if (x != y) {
            cout << "No" << endl; return 0;
        }
    }
    cout << "Yes" << endl;
}