#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();

    vector<bool> guess(1001, false);

    for (int a = 1; a <= 1000; a++) for (int b = 1; b <= 1000; b++) {
        int area = 4 * a * b + 3 * a + 3 * b;
        if (area <= 1000) guess[area] = true;
    }

    int wa = 0;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int s; cin >> s;
        if (guess[s] == false) wa += 1;
    }
    cout << wa << "\n";
}

