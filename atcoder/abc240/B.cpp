#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        s.insert(x);
    }
    cout << s.size() << "\n";
}

