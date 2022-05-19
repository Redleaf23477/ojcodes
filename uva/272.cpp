#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string str; 
    bool flag = true;
    while (getline(cin, str)) {
        for (auto c : str) {
            if (c == '\"') {
                cout << (flag? "``" : "''");
                flag = !flag;
            } else {
                cout << c;
            }
        }
        cout << endl;
    }
}