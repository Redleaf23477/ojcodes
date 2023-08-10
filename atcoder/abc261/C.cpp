#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int N; cin >> N;
    unordered_map<string,int> db;
    while (N--) {
        string fname; cin >> fname;
        if (db.count(fname) == 0) {
            db[fname] = 0;
            cout << fname << "\n";
        } else {
            db[fname]++;
            cout << fname << "(" << to_string(db[fname]) << ")" << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//    int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



