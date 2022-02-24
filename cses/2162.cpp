#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    list<int> cir(n);
    iota(cir.begin(), cir.end(), 1);

    auto it = cir.begin();
    while (!cir.empty()) {
        // advance
        it++;
        if (it == cir.end()) it = cir.begin();
        // print
        cout << *it << " ";
        // erase and advance
        it = cir.erase(it);
        if (it == cir.end()) it = cir.begin();
    }
    cout << "\n";
}

