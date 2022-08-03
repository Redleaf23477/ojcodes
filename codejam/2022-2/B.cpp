#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void draw_circle_perimeter(LL R, vector<vector<int>> &B) {
    auto draw = [&](int x, int y, int val) {
        int len = B.size() / 2;
        B[x+len][y+len] = val;
    };
    for (LL x = -R; x <= R; x++) {
        LL y = sqrt(R * R - x * x) + 0.5;
        draw(x, y, R);
        draw(x, -y, R);
        draw(y, x, R);
        draw(-y, x, R);
    }
}

void draw_circle_filled_wrong(LL R, vector<vector<int>> &B) {
    for (int r = 0; r <= R; r++) {
        draw_circle_perimeter(r, B);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    /*
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
    }
    */
    int n; cin >> n;
    vector<vector<int>> B(n*2+2, vector<int>(n*2+2, 9));
    draw_circle_filled_wrong(n, B);
    for (size_t i = 0; i < B.size(); i++) {
        for (size_t j = 0; j < B.size(); j++) {
            cerr << B[i][j] << " ";
        }
        cerr << endl;
    }
}

