#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
using LL = long long;

void solve() {
    int N; cin >> N;
    vector<double> exp(N);
    exp[0] = 3.5;
    for (int i = 1; i < N; i++) {
        // if I draw a smaller point, discard it
        double discard_prob = 0;
        double use_exp = 0;
        for (int pt = 1; pt <= 6; pt++) {
            if (pt >= exp[i - 1]) {
                use_exp += pt / 6.0;
            } else {
                discard_prob += 1 / 6.0;
            }
        }
        exp[i] = use_exp + discard_prob * exp[i - 1];
    }
    cout << fixed << setprecision(10) << exp.back() << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}