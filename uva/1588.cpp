#include <bits/stdc++.h>
using namespace std;

int run(const string &t, const string &p) {
    int ans = t.size() + p.size();
    // right
    for (size_t i = 0; i < t.size(); i++) {
        bool good = true;
        for (size_t j = 0; j < p.size() && i + j < t.size(); j++) {
            if (p[j] == '2' && t[i+j] == '2') {
                good = false;
                break;
            }
        }
        if (good) {
            int tmp = t.size() + (i + p.size() > t.size()? i + p.size() - t.size() : 0);
            ans = tmp;
            break;
        }
    }
    // left
    for (size_t j = 0; j < p.size(); j++) {
        bool good = true;
        for (size_t i = 0; i + j < p.size(); i++) {
            if (p[i+j] == '2' && t[i] == '2') {
                good = false;
                break;
            }
        }
        if (good) {
            ans = min(ans, (int)(j + t.size()));
            break;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    string s1, s2;
    while (cin >> s1 >> s2) {
        if (s1.size() < s2.size()) swap(s1, s2);
        cout << run(s1, s2) << endl;
    }
}

