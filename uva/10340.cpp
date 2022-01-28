#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    string s1, s2; 
    while (cin >> s1 >> s2) {
        size_t i = 0;
        for (size_t j = 0; i < s1.size() && j < s2.size(); j++) {
            if (s1[i] == s2[j]) i++;
        }
        if (i == s1.size()) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}

