#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    string s, t; cin >> s >> t;
    vector<int> cnt(27, 0);
    for (auto c : s) {
        if (c == '?') cnt[26]++;
        else cnt[c - 'a']++;
    }
    vector<char> q_mark;
    for (bool succ = true; succ; ) {
        for (char c : t) {
            if (cnt[c - 'a'] > 0) cnt[c - 'a']--;
            else if (cnt[26] > 0) cnt[26]--, q_mark.emplace_back(c);
            else { succ = false; break; }
        }
    }
    for (auto c : s) {
        if (c == '?') {
            cout << (q_mark.empty()? 'a' : q_mark.back());
            if (!q_mark.empty()) q_mark.pop_back();
        } else {
            cout << c;
        }
    }
    cout << "\n";
}

