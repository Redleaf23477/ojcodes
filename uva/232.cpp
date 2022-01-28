#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    constexpr int N = 10;
    int R, C;
    char arr[N][N];
    int start[N][N];
    int caseN = 0;
    while (cin >> R && R) {
        if (caseN > 0) cout << endl;
        cout << "puzzle #" << ++caseN << ":" << endl;

        cin >> C;
        int cnt = 0;
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++) {
                cin >> arr[i][j];
                start[i][j] = 0;
                if (arr[i][j] != '*') {
                    if (i-1 < 0 || j-1 < 0 || arr[i-1][j] == '*' || arr[i][j-1] == '*') {
                        start[i][j] = ++cnt;
                    }
                }
            }
        cout << "Across" << endl;
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++) {
                if (start[i][j] && (j-1 < 0 || arr[i][j-1] == '*')) {
                    cout << setw(3) << start[i][j] << ".";
                    for (int k = j; k < C; k++) {
                        if (arr[i][k] == '*') break;
                        cout << arr[i][k];
                    }
                    cout << endl;
                }
            }
        cout << "Down" << endl;
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++) {
                if (start[i][j] && (i-1 < 0 || arr[i-1][j] == '*')) {
                    if (start[i][j] == 0) continue;
                    cout << setw(3) << start[i][j] << ".";
                    for (int k = i; k < R; k++) {
                        if (arr[k][j] == '*') break;
                        cout << arr[k][j];
                    }
                    cout << endl;
                }
            }
    }
}

