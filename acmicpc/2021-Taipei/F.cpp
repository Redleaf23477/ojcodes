#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using T5 = tuple<int,int,int,int,int>;

int relabel(vector<T5> &arr) {
    vector<int> x, y;
    for (auto &[x1, y1, x2, y2, c] : arr) {
        x.emplace_back(x1 - 1);
        x.emplace_back(x1);
        x.emplace_back(x2);
        x.emplace_back(x2 + 1);
        y.emplace_back(y1 + 1);
        y.emplace_back(y1);
        y.emplace_back(y2);
        y.emplace_back(y2 - 1);
    }
    sort(x.begin(), x.end());
    auto it = unique(x.begin(), x.end());
    x.erase(it, x.end());
    sort(y.begin(), y.end());
    it = unique(y.begin(), y.end());
    y.erase(it, y.end());
    for (auto &[x1, y1, x2, y2, c] : arr) {
        x1 = lower_bound(x.begin(), x.end(), x1) - x.begin();
        x2 = lower_bound(x.begin(), x.end(), x2) - x.begin();
        y1 = lower_bound(y.begin(), y.end(), y1) - y.begin();
        y2 = lower_bound(y.begin(), y.end(), y2) - y.begin();
    }
    return max(x.size(), y.size());
}

struct BlockDecomposition {
    int n, c_max;
    int block_len;
    int big_size;
    vector<int> small, big;
    vector<vector<int>> rows, cols;  // each row or col in big block, y for rows, x for cols
    BlockDecomposition(int _n, int _cm): n(_n), c_max(_cm), block_len(sqrt(n)), big_size((n + block_len - 1) / block_len), 
                                        small(n * n, -1), big(big_size * big_size, -1),
                                        rows(big.size(), vector<int>(block_len, -1)), cols(big.size(), vector<int>(block_len, -1)) {}
    void push(int x1, int y1, int x2, int y2, int t) {
        for (int y = y1; y <= y2; ) {
            bool y_is_block = (y % block_len == 0 && y + block_len - 1 <= y2);
            for (int x = x1; x <= x2; ) {
                bool x_is_block = (x % block_len == 0 && x + block_len - 1 <= x2);
                int block_r = y / block_len, block_c = x / block_len;
                int block_idx = block_r * big_size + block_c;
                if (x_is_block && y_is_block) {
                    // is big
                    big[block_idx] = t;
                } else if (y_is_block) {
                    // is small but use_col
                    cols[block_idx][x % block_len] = t;
                } else if (x_is_block) {
                    // is small but use_row
                    rows[block_idx][y % block_len] = t;
                } else {
                    // is small, pure brute force
                    small[y * n + x] = t;
                }
                x += (x_is_block? block_len : 1);
            }
            y += (y_is_block? block_len : 1);
        }
    }
    vector<bool> report_posters() {
        vector<bool> s(c_max, false);
        for (int y = 0; y < n; y++) for (int x = 0; x < n; x++) {
            int block_r = y / block_len, block_c = x / block_len;
            int block_idx = block_r * big_size + block_c;

            int color = small[y * n + x];
            color = max(color, big[block_idx]);
            color = max(color, cols[block_idx][x % block_len]);
            color = max(color, rows[block_idx][y % block_len]);

            if (color != -1) s[color] = true;
        }
        return s;
    }
    void debug() {
        cerr << "small" << endl;
        for (int x = 0; x < n; x++) for (int y = 0; y < n; y++) {
            cerr << small[y * n + x] << " \n"[y == n-1];
        }
        cerr << "big" << endl;
        for (auto b : big) cerr << b << endl;
        cerr << "rows" << endl;
        for (auto b : rows) {
            for (auto r : b) cerr << r << " ";
            cerr << endl;
        }
        cerr << "cols" << endl;
        for (auto b : cols) {
            for (auto c : b) cerr << c << " ";
            cerr << endl;
        }
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<T5> arr(n);
    for (auto &[x1, y1, x2, y2, c] : arr) {
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        c--, y1--, x2--;
    }
    int range = relabel(arr);

    BlockDecomposition block_decomp(range, n);
    for (int i = 0; i < n; i++) {
        auto &[x1, y1, x2, y2, c] = arr[i];
        block_decomp.push(x1, y2, x2, y1, i);
    }
    vector<bool> p = block_decomp.report_posters();
    vector<bool> use(n, false);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (p[i]) {
            int c = get<4>(arr[i]);
            if (!use[c]) use[c] = true, ans++;
        }
    }
    cout << ans << "\n";
}

