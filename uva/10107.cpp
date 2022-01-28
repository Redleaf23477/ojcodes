#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    priority_queue<int, vector<int>, less<int>> lhs;
    priority_queue<int, vector<int>, greater<int>> rhs;

    int x;
    while (cin >> x) {
        lhs.emplace(x);
        while (lhs.size() > rhs.size()) {
            rhs.emplace(lhs.top());
            lhs.pop();
        }
        if (!lhs.empty()) {
            while (lhs.top() > rhs.top()) {
                int l = lhs.top(); lhs.pop();
                int r = rhs.top(); rhs.pop();
                lhs.emplace(r), rhs.emplace(l);
            }
        }
        if (lhs.size() == rhs.size()) {
            cout << (lhs.top() + rhs.top()) / 2 << '\n';
        } else {
            cout << rhs.top() << '\n';
        }
    }
}

