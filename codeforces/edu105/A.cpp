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

string str;

void init() {
    cin >> str;
}

bool good(int i) {
    char A = ((i>>0)&1)? '(' : ')';
    char B = ((i>>1)&1)? '(' : ')';
    char C = ((i>>2)&1)? '(' : ')';
    string tmp = str; {
        for (auto &c : tmp) {
            if (c == 'A') c = A;
            if (c == 'B') c = B;
            if (c == 'C') c = C;
        }
    }
    int stk = 0;
    for (auto c : tmp) {
        if (c == '(') stk++;
        else if (stk == 0) return false;
        else stk--;
    }
    return stk == 0;
}

void process() {
    for (int i = 0; i < 8; i++) {
        if (good(i)) {
            cout << "YES" << endl; return;
        }
    }
    cout << "NO" << endl;
}

