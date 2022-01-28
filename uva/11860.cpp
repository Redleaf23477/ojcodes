#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T >> ws;
    int caseN = 0;
    while (T--) {
        string buff;
        vector<int> doc;
        int idx = 0;
        map<string, int> mp;
        while (getline(cin, buff)) {
            if (buff == "END") break;
            for (auto &c : buff) {
                if (!isalpha(c)) c = ' ';
            }
            stringstream ss(buff);
            while (ss >> buff) {
                if (mp.count(buff) == 0) {
                    mp[buff] = idx++;
                }
                doc.emplace_back(mp[buff]);
            }
        }

        /*
        for (auto x : doc) cerr << x << " ";
        cerr << endl;
        */

        int ans_l = 0, ans_r = doc.size()-1;
        vector<int> vis(idx, 0); vis[doc[0]] = 1;
        for (int l = 0, r = 0, vis_cnt = 1; l < (int)doc.size(); l++) {
            while (r+1 < (int)doc.size() && vis_cnt != idx) {
                r += 1;
                if (vis[doc[r]] == 0) vis_cnt += 1;
                vis[doc[r]] += 1;
            }
            if (vis_cnt != idx) break;

            if (r-l < ans_r-ans_l) {
                ans_l = l, ans_r = r;
            }

            vis[doc[l]]--;
            if (vis[doc[l]] == 0) vis_cnt -= 1;
        }

        cout << "Document " << ++caseN << ": " << ans_l + 1 << " " << ans_r + 1 << "\n";
    }
}

