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

int n[3];
vector<LL> a[3];

void init() {
    cin >> n[0] >> n[1] >> n[2];
    for (int i = 0; i < 3; i++) {
        a[i].resize(n[i]);
        for (auto &x : a[i]) cin >> x;
        sort(a[i].begin(), a[i].end());
    }
}

void process() {
    LL ans = 0;
    LL s[3] = {0}; {
        for (int i = 0; i < 3; i++) {
            for (auto x : a[i]) s[i] += x;
        }
    }

    vector<int> perm {0, 1, 2};
    do {
        auto &s1 = s[perm[0]], &s2 = s[perm[1]], &s3 = s[perm[2]];
        auto &a1 = a[perm[0]], &a2 = a[perm[1]], &a3 = a[perm[2]];
        ans = max(ans, s1 + s2 + s3 - 2*a2[0] - 2*a3[0]);  // s1->sx->s1, s2->s3->s1, s3->s2->s1
        ans = max(ans, s1 + s2 - s3); // s1->s3->s1, s2->s3->s1
        ans = max(ans, s1 - s2 + s3); // s1->s3->s1, s2->s3->s1
    } while (next_permutation(perm.begin(), perm.end()));
    cout << ans << endl;
}

