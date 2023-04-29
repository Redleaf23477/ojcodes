#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

inline LL CUBE(LL x) { return x * x * x; }

void solve() {
    LL M; cin >> M;
    // step1: maximize #cubes, minimize X
    int num_cubes = 0;
    vector<LL> cnt(1, 0);
    LL X = 0;
    for (LL c = 1; CUBE(c) <= M; c++) {
        LL ub = (min(M, CUBE(c + 1) - 1) - X) / CUBE(c);
        if (ub <= 0) break;
        cnt.emplace_back(ub);
        X += CUBE(c) * ub;
        num_cubes += ub;
    }
    /*
    cerr << "DEBUG: " << endl;
    for (LL c = 1; c < cnt.size(); c++) {
        cerr << "c = " << c << ", c^3 = " << CUBE(c) << ", cnt = " << cnt[c] << endl;
    }
    cerr << "num_cubes = " << num_cubes << endl;
    */
    // step2: maximize X
    for (int i = 0; i < num_cubes; i++) {
        for (LL c = 1, sum = 0; CUBE(c) <= M && c < cnt.size(); c++) {
            sum += CUBE(c) * cnt[c];
            LL next_ub = (CUBE(c+2) - 1 - sum) / CUBE(c+1);
            LL delta = CUBE(c+1) - CUBE(c);
            if (X + delta <= M) {
                if (c+1 == cnt.size()) {
                    X += delta, sum -= CUBE(c);
                    cnt[c]--, cnt.emplace_back(1);
                    // cerr << "change: " << c << " --> " << c+1 << endl;
                } else if (cnt[c+1] < next_ub) {
                    X += delta, sum -= CUBE(c);
                    cnt[c]--, cnt[c+1]++;
                    // cerr << "change: " << c << " --> " << c+1 << endl;
                }
            }
        }
    }
    // print answer
    cout << num_cubes << " " << X << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



