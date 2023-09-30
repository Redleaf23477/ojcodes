#include <bits/stdc++.h>
using namespace std;
using LL = long long;

bool query(bool is_row, int mid, int N) {
    if (is_row) {
        cout << "? " << 1 << " " << mid + 1 << " " << 1 << " " << N << endl;
    } else {
        cout << "? " << 1 << " " << N << " " << 1 << " " << mid + 1 << endl;
    }
    int res; cin >> res;
    return res == mid + 1;
}

int bs(bool is_row, int N) {
    int low = 0, high = N - 1, mid, ans = -1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (query(is_row, mid, N)) {
            ans = mid, low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

void solve() {
    int N; cin >> N;
    // binary search row
    int r = bs(true, N);
    // binary search col
    int c = bs(false, N);
    cout << "! " << r + 2 << " " << c + 2 << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}

