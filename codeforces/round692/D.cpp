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

using namespace std;
using LL = long long int;

void init();
void process();

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    for (int t = 1; t <= T; t++) {
        init();
        process();
    }
    cout.flush();
    return 0;
}

string s;
LL x, y;

void init() {
    cin >> s >> x >> y;
}

const int N = 100005;

void process() {
    int n = s.size();
    LL original = 0;
    // non-question mark
    LL z = (s[0] == '0'), o = (s[0] == '1'), q = (s[0] == '?');
    for (int i = 1; i < n; i++) {
        if (s[i] == '1') {
            o++;
            original += z*x;
        } else if (s[i] == '0') {
            z++;
            original += o*y;
        } else {
            q++;
        }
    }
    // question marks
    LL pre[N][2], suf[N][2]; {
        pre[0][0] = (s[0] == '0'), pre[0][1] = (s[0] == '1');
        for (int i = 1; i < n; i++) {
            if (s[i] == '0') {
                pre[i][0] = pre[i-1][0]+1;
                pre[i][1] = pre[i-1][1];
            } else if (s[i] == '1') {
                pre[i][0] = pre[i-1][0];
                pre[i][1] = pre[i-1][1]+1;
            } else {
                pre[i][0] = pre[i-1][0];
                pre[i][1] = pre[i-1][1];
            }
        }
        suf[n-1][0] = (s[n-1] == '0'), suf[n-1][1] = (s[n-1] == '1');
        for (int i = n-2; i >= 0; i--) {
            if (s[i] == '0') {
                suf[i][0] = suf[i+1][0]+1;
                suf[i][1] = suf[i+1][1];
            } else if (s[i] == '1') {
                suf[i][0] = suf[i+1][0];
                suf[i][1] = suf[i+1][1]+1;
            } else {
                suf[i][0] = suf[i+1][0];
                suf[i][1] = suf[i+1][1];
            }
        }
    }
    LL ans = 1e18;
    if (x < y) {  // use 01
        LL c01 = 0, c10 = 0, qq = 0;
        // initially: 11111111111
        for (int i = 0; i < n; i++) if (s[i] == '?') c01 += pre[i][0], c10 += suf[i][0];
        ans = c01*x + c10*y;
        // sliding: 000|111111
        for (int i = 0; i < n; i++) {
            if (s[i] != '?') continue;
            qq++;
            c01 -= pre[i][0], c10 -= suf[i][0];
            c01 += suf[i][1], c10 += pre[i][1];
            ans = min(ans, c01*x + c10*y + qq*(q-qq)*x);
        }
    } else { // use 10
        LL c01 = 0, c10 = 0, qq = 0;
        // initially: 0000000000
        for (int i = 0; i < n; i++) if (s[i] == '?') c10 += pre[i][1], c01 += suf[i][1];
        ans = c01*x + c10*y;
        // sliding: 111|00000000
        for (int i = 0; i < n; i++) {
            if (s[i] != '?') continue;
            qq++;
            c10 -= pre[i][1], c01 -= suf[i][1];
            c10 += suf[i][0], c01 += pre[i][0];
            ans = min(ans, c01*x + c10*y + qq*(q-qq)*y);
        }
    }
    cout << original+ans << endl;
}

