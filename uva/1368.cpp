#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        int n, len; cin >> n >> len;
        vector<vector<int>> cnt(len, vector<int>(4, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < len; j++) {
                char ch; cin >> ch;
                if (ch == 'A') cnt[j][0] += 1;
                else if (ch == 'C') cnt[j][1] += 1;
                else if (ch == 'G') cnt[j][2] += 1;
                else cnt[j][3] += 1;
            }
        int dist = 0;
        char dna[] = {'A', 'C', 'G', 'T'};
        for (int i = 0; i < len; i++) {
            int idx = max_element(cnt[i].begin(), cnt[i].end()) - cnt[i].begin();
            cout << dna[idx];
            dist += n - cnt[i][idx];
        }
        cout << endl;
        cout << dist << endl;
    }
}

