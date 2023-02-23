#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    vector<int> sp(300, 0);
    iota(sp.begin(), sp.end(), 0);
    for (int i = 2; i < 300; i++) {
        if (sp[i] == i) {
            for (int j = i * i; j < 300; j += i) {
                if (sp[j] == j) sp[j] = i;
            }
        }
    }
    int A, B, C, D; cin >> A >> B >> C >> D;
    bool flg = false;
    for (int t = A; t <= B; t++) {
        bool find_ans = false;
        for (int a = C; a <= D; a++) {
            if (sp[t + a] == t + a) {
                find_ans = true;
            }
        }
        if (find_ans == false) flg = true;
    }
    cout << (flg? "Takahashi\n" : "Aoki\n");
}

