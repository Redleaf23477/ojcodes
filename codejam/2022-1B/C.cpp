#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

struct Solver {
    int r_rotate(int x) {
        return (x >> 1) | ((x & 1) << 7);
    }
    string bit(int x) {
        string ans(8, '0');
        for (int i = 0; i < 8; i++) {
            ans[i] += (x >> i) & 1;
        }
        return ans;
    }

    vector<int> table;
    void build_table() {
        table.clear();
        vector<bool> _table(1 << 8, false);
        for (int i = 0; i < (1 << 8); i++) {
            bool good = true;
            for (int r = 0, x = i; r < 8 && good; r++, x = r_rotate(x)) {
                if (_table[x]) good = false;
            }
            if (good) {
                _table[i] = true;
            }
        }
        for (int i = 0; i < (1 << 8); i++) {
            if (_table[i]) {
                table.emplace_back(i);
            }
        }
        /*
        cerr << "table(" << table.size() << "): ";
        for (auto x : table) {
            cerr << x << " " << bit(x) << endl;
        }
        */
    }

    string query(int n) {
        return "meow";
    }
};

int main() {
    Solver solver;
    solver.build_table();
    while (true) {
        int N; cin >> N;
        if (N == 0) break;
        string s = solver.query(N);
        cout << s << endl;
    }
}
