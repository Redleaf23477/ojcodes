#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    constexpr int N = 5; 
    int caseNum = 0;
    char arr[N][N], peek;
    while ((peek = cin.peek()) && peek != 'Z') {
        // input
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                arr[i][j] = cin.get();
            }
            char nl = cin.get();  // newline
            cerr << "nl = " << nl << endl;
            assert(nl == '\n');
        }

        if (caseNum != 0) cout << endl;
        cout << "Puzzle #" << ++caseNum << ":" << endl;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cerr << arr[i][j] << "/";
            }
            cerr << endl; 
        }

        // find blank
        int r = -1, c = -1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (arr[i][j] == ' ') {
                    r = i, c = j;
                }
            }
        }
        assert(r != -1 && c != -1);
        // input & process cmd
        bool good = true;
        char cmd;
        while (cin >> cmd && cmd != '0') {
            int nr = -1, nc = -1;
            if (cmd == 'A') {
                if (r == 0) good = false;
                nr = r - 1, nc = c;
            } else if (cmd == 'B') {
                if (r == N-1) good = false;
                nr = r + 1, nc = c;
            } else if (cmd == 'L') {
                if (c == 0) good = false;
                nr = r, nc = c - 1;
            } else if (cmd == 'R') {
                if (c == N-1) good = false;
                nr = r, nc = c + 1;
            } else {
                cerr << "cmd = " << cmd << endl;
                assert(false);
            }
            if (good) {
                swap(arr[r][c], arr[nr][nc]);
                r = nr, c = nc;
            }
        }
        char nl = cin.get();  // newline
        // output
        if (good) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    cout << arr[i][j] << " \n"[j==N-1];
                }
            }
        } else {
            cout << "This puzzle has no final configuration." << endl;
        }
    }
}

