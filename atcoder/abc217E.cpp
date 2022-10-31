#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int Q; cin >> Q;
    priority_queue<int, vector<int>, greater<int>> part1;
    queue<int> part2;
    while (Q--) {
        int cmd; cin >> cmd;
        if (cmd == 1) {
            int x; cin >> x;
            part2.emplace(x);
        } else if (cmd == 2) {
            if (!part1.empty()) {
                cout << part1.top() << "\n";
                part1.pop();
            } else {
                cout << part2.front() << "\n";
                part2.pop();
            }
        } else {
            while (!part2.empty()) {
                part1.emplace(part2.front());
                part2.pop();
            }
        }
    }
}

