#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

LL dist2(LL x, LL y, LL x1, LL y1) {
    return (x - x1) * (x - x1) + (y - y1) * (y - y1);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    LL x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    bool ans = false;
    for (LL x = x1 - 5; x <= x1 + 5; x++) {
        for (LL y = y1 - 5; y <= y1 + 5; y++) {
            if (dist2(x, y, x1, y1) == 5 && dist2(x, y, x2, y2) == 5) {
                ans = true;
            }
        }
    }
    cout << (ans? "Yes\n" : "No\n");
}

