#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n, m; cin >> n >> m;
    map<int,int> ticket;
    for (int i = 0; i < n; i++) {
        int p; cin >> p;
        ticket[p] += 1;
    }
    for (int i = 0; i < m; i++) {
        int p; cin >> p;
        auto it = ticket.upper_bound(p);
        if (it == ticket.begin()) {
            cout << -1 << "\n";
        } else {
            it--;
            cout << it->first << "\n";
            if (--it->second == 0) ticket.erase(it);
        }
    }
}

