#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    int n; cin >> n;
    cout << 1 << endl;
    vector<bool> num_set(n + n + 2, false);
    num_set[0] = num_set[1] = true;
    int it = 2;
    int aoki;
    while (cin >> aoki && aoki != 0) {
        num_set[aoki] = true;
        while (num_set[it]) it++;
        cout << it << endl;
        num_set[it] = true;
    }
}



