#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

vector<int> read_array() {
    vector<int> arr(8, 0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x; x--;
        arr[x]++;
    }
    return arr;
}

int axis[9][9][9][9][9][9][9][9];

void add_array(vector<int> const &arr, int val) {
    for (int a = 0; a <= arr[0]; a++)
        for (int b = 0; b <= arr[1]; b++)
            for (int c = 0; c <= arr[2]; c++)
                for (int d = 0; d <= arr[3]; d++)
                    for (int e = 0; e <= arr[4]; e++)
                        for (int f = 0; f <= arr[5]; f++)
                            for (int g = 0; g <= arr[6]; g++)
                                for (int h = 0; h <= arr[7]; h++) {
                                    auto &cell = axis[a][b][c][d]
                                                     [e][f][g][h];
                                    cell += val;
                                }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    memset(axis, 0, sizeof(axis));

    vector<vector<int>> rect;

    int n, k; cin >> n >> k;
    while (n--) {
        char op; cin >> op;
        if (op == 'C') {
            vector<int> arr = read_array();
            add_array(arr, 1);
            rect.emplace_back(arr);
        } else if (op == 'D') {
            int idx; cin >> idx; idx--;
            add_array(rect[idx], -1);
        } else {
            vector<int> arr = read_array();
            cout << axis[arr[0]][arr[1]][arr[2]][arr[3]]
                        [arr[4]][arr[5]][arr[6]][arr[7]] << "\n";
        }
    }
}

