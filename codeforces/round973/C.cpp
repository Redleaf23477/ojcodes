#include <bits/stdc++.h>
using namespace std;
using LL = long long;

bool query(list<char> &qry) {
    cout << "? " << string(qry.begin(), qry.end()) << endl;
    int res; cin >> res;
    if (res == -1) exit(0);
    return res == 1;
}

void report(list<char> &ans) {
    cout << "! " << string(ans.begin(), ans.end()) << endl;
}

void solve() {
    int n; cin >> n;
    list<char> ans;
    int dir = 0;
    while ((int)ans.size() != n) {
        if (dir == 0) {
            // push front
            ans.push_front('0');
            if (query(ans)) continue;
            ans.pop_front();
            ans.push_front('1');
            if (query(ans)) continue;
            ans.pop_front();
            dir = 1;
        } else {
            // push back
            ans.push_back('0');
            if (query(ans)) continue;
            ans.pop_back();
            ans.push_back('1');
        }
    }
    report(ans);
}

int main() {
    int T; cin >> T;
    while (T--) solve();
}
