#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int R, C; cin >> R >> C;

    auto print_row = [](int C, string ctx, string end, int dot = 0) {
        for (int i = 0; i < dot; i++) cout << "..";
        for (int i = dot; i < C; i++) cout << ctx;
        cout << end << "\n";
    };

    for (int r = 0; r < R; r++) {
        if (r == 0) {
            print_row(C, "+-", "+", 1);
            print_row(C, "|.", "|", 1);
        } else {
            print_row(C, "+-", "+", 0);
            print_row(C, "|.", "|", 0);
        }
    }
    print_row(C, "+-", "+", 0);

}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ":\n";
        solve();
    }
}

