#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int run(int time, int speed, int rest, int duration) {
    int iter = duration / (time + rest);
    int rem = duration - iter * (time + rest);
    int dist = speed * time * iter;
    dist += speed * min(time, rem);
    return dist;
}

void solve() {
    int A, B, C, D, E, F, X;
    cin >> A >> B >> C >> D >> E >> F >> X;
    int takahashi = run(A, B, C, X);
    int aoki = run(D, E, F, X);
    if (takahashi == aoki) {
        cout << "Draw\n";
    } else if (takahashi > aoki) {
        cout << "Takahashi\n";
    } else {
        cout << "Aoki\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//     int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



