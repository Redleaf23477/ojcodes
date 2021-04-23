// by redleaf23477
#include <bits/stdc++.h>

// iostream macros
#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
// chrono macros
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()
#define chrono_rand_seed chrono_now.time_since_epoch().count()
// random
std::mt19937_64 myrand(chrono_rand_seed);
// stl
#define range(seq) seq.begin(), seq.end()


using namespace std;
using LL = long long int;

void init();
void process();

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        init();
        process();
    }
    cout.flush();
    return 0;
}

int n, k;
string str;

void init() {
    cin >> n >> k >> str;
}

void process() {
    string ans(2*n, 'z');
    function<void(int)> run1 = [&](int len) {
        string tmp(n, 'x');
        vector<int> ch(26, 0);
        int notUsed = 0;
        // same as str
        for (int i = 0; i < len; i++) {
            char c = str[i];
            if (ch[c-'a'] == 0) ch[c-'a'] = k, notUsed += k;
            tmp[i] = c, ch[c-'a']--, notUsed--;
        }
        while (len < n && str[len] == 'z') {
            if (ch[25] == 0) ch[25] = k, notUsed += k;
            tmp[len] = 'z', ch[25]--, notUsed--;
            len++;
        }
        if (len == n) {
            if (notUsed == 0) ans = min(ans, tmp);
            return;
        }
        // one character bigger
        {
            if (ch[str[len]-'a'+1] == 0) ch[str[len]-'a'+1] = k, notUsed += k;
            tmp[len] = str[len]+1, ch[str[len]-'a'+1]--, notUsed--;
            len++;
        }
        // greedy make ans small
        for (int i = n-1, j = 25; i >= len; i--) {
            while (j >= 0 && ch[j] == 0) { j--; }
            if (j < 0) { j = 0, ch[0] += k, notUsed += k; }
            tmp[i] = 'a'+j, ch[j]--, notUsed--;
        }
        if (notUsed != 0) return;
        ans = min(ans, tmp);
    };
    function<void(int)> run2 = [&](int len) {
        string tmp(n, 'x');
        vector<int> ch(26, 0);
        int notUsed = 0;
        // same as str
        for (int i = 0; i < len; i++) {
            char c = str[i];
            if (ch[c-'a'] == 0) ch[c-'a'] = k, notUsed += k;
            tmp[i] = c, ch[c-'a']--, notUsed--;
        }
        while (len < n && str[len] == 'z') {
            if (ch[25] == 0) ch[25] = k, notUsed += k;
            tmp[len] = 'z', ch[25]--, notUsed--;
            len++;
        }
        if (len == n) {
            if (notUsed == 0) ans = min(ans, tmp);
            return;
        }
        // one character bigger
        {
            int idx = n; {
                for (idx = 0; idx < 26; idx++) {
                    if (ch[idx] > 0 && 'a'+idx > str[len]) break;
                }
            }
            if (idx == 26) return;
            tmp[len] = 'a'+idx, ch[idx]--, notUsed--;
            len++;
        }
        // greedy make ans small
        for (int i = n-1, j = 25; i >= len; i--) {
            while (j >= 0 && ch[j] == 0) { j--; }
            if (j < 0) { j = 0, ch[0] += k, notUsed += k; }
            tmp[i] = 'a'+j, ch[j]--, notUsed--;
        }
        if (notUsed != 0) return;
        ans = min(ans, tmp);
    };
    for (int prefixLen = 0; prefixLen <= n; prefixLen++) {
        run1(prefixLen);
        run2(prefixLen);
    }
    if (ans.size() != n) cout << -1 << endl;
    else cout << ans << endl;
}

