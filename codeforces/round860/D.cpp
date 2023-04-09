#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

// pure guess, I don't know if it works

void solve() {
    int n; cin >> n; 
    multiset<LL> neg, non_neg;
    for (int i = 0; i < n; i++) {
        LL x; cin >> x;
        if (x < 0) neg.insert(x);
        else non_neg.insert(x);
    }
    bool good = true;
    LL min_pref = 0, pref = 0;
    LL D = *non_neg.rbegin() - (neg.empty()? 0 : *neg.begin());
    vector<LL> ans(n);
    for (auto &x : ans) {
        auto it = non_neg.lower_bound(D + min_pref - pref);
        if (it != non_neg.begin()) {
            // put the largest non-neg elem
            it--;
            x = *it;
            non_neg.erase(it);
        } else if (neg.empty()) {
            // gg
            good = false; break;
        } else {
            // put the smallest neg elem
            x = *neg.begin();
            neg.erase(neg.begin());
        }
        pref += x;
        min_pref = min(min_pref, pref);
    }

    if (good) {
        cout << "Yes\n";
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



