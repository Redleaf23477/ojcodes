#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int get_money() {
    char ch; cin >> ch;
    int x; cin >> x;
    cin >> ch;
    int y; cin >> y;
    return y;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int ans = 0;
    int money = get_money();
    for (int i = 0; i < n; i++) {
        int x = get_money();
        money += x;
        if (money % 100 != 0) ans++;
    }
    cout << ans << "\n";
}

