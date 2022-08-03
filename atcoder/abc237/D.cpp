#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    string str; cin >> str;
    list<int> ans(1, 0);
    auto it = ans.begin();
    for (int i = 1; i <= n; i++) {
        if (str[i-1] == 'L') {
            it = ans.insert(it, i);
        } else {
            it++;
            it = ans.insert(it, i);
        }
    }
    for (auto x : ans) cout << x << " ";
    cout << "\n";
}

