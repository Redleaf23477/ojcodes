#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    vector<tuple<string,int>> P(n);
    for (auto &[op, data] : P) {
        cin >> op;
        if (op == "echo") {
            char ch; cin >> ch;
            data = ch - 'a';
        } else {
            cin >> data;
        }
    }
    queue<tuple<int,int>> Q;
    Q.emplace(0, n);
    for (int i = 0; i < k && !Q.empty(); i++) {
        auto &[l, r] = Q.front();
        const auto &[op, data] = P[l];
        if (op == "echo") {
            cout << static_cast<char>('a' + data);
        } else {
            Q.emplace(0, data);
        }
        if (++l == r) Q.pop();
    }
    cout << "\n";
}

