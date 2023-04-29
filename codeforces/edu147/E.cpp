#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

string fix(string str) {
    int n = str.size();
    vector<int> paired(n);
    vector<int> penalty(n, 0);
    vector<int> stk;
    vector<int> timeline;  // prefix sum, in_time of each '(' is i+1
    timeline.emplace_back(0); 
    for (int i = 0; i < n; i++) {
        char ch = str[i];
        if (ch == '(') {
            stk.emplace_back(i);
            timeline.emplace_back(timeline.back());
        } else {
            int l = stk.back(); stk.pop_back();
            paired[l] = i, paired[i] = l;
            penalty[l] = timeline.back() - timeline[l];
            timeline.emplace_back(timeline.back() + 1);
        }
    }
    int bad = max_element(penalty.begin(), penalty.end()) - penalty.begin();
    str.insert(paired[bad], "(");
    str.erase(bad, 1);

    // cerr << "fix: " << str << endl;

    return str;
}

LL cnt(string str) {
    int n = str.size();
    vector<int> stk;
    LL ans = 0;
    for (int i = 0; i < n; i++) {
        char ch = str[i];
        if (ch == '(') {
            stk.emplace_back(i);
        } else {
            stk.pop_back();
            ans += stk.size();
        }
    }
    return ans;
}

void solve() {
    int k; cin >> k;
    string str; cin >> str;
    while (k--) {
        str = fix(str);
    }
    cout << cnt(str) << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



