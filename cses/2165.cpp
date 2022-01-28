#include <bits/stdc++.h>
using namespace std;

void h(int n, int from, int to, int tmp) {
    if (n == 0) return;
    h(n-1, from, tmp, to);
    cout << from << " " << to << endl;
    h(n-1, tmp, to, from);
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    cout << (1<<n) - 1 << endl;
    h(n, 1, 3, 2);
}

