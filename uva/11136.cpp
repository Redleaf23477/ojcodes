#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n;
    while (cin >> n && n) {
        multiset<int> s;
        LL sum = 0;
        for (int d = 0; d < n; d++) {
            int k; cin >> k;
            while (k--) {
                int x; cin >> x;
                s.insert(x);
            }
            auto it = s.begin();
            auto jt = s.end(); jt--;
            sum += *jt - *it;
            s.erase(it), s.erase(jt);
        }
        cout << sum << endl;
    }
}

