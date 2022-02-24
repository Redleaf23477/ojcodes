#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T = 100;
    cout << T << endl;
    mt19937 myrand;
    while (T--) {
        int n = myrand() % 1000;
        string str(n, 'R');
        for (auto &x : str) {
            if (myrand() % 2) x = 'D';
        }
        cout << n << "\n" << str << "\n";
    }
}

