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

int n;
string str[3];

void init() {
    cin >> n >> str[0] >> str[1] >> str[2];
}

void process() {
    for (int i = 0; i < 3; i++) for (int j = i+1; j < 3; j++) for (int m = 0; m < 2; m++) {
        string buff;
        auto &a = str[i], &b = str[j];
        int x = 0, y = 0;

        while (x < 2*n || y < 2*n) {
            while (x < 2*n && a[x] != '0'+m) buff.push_back(a[x++]);
            while (y < 2*n && b[y] != '0'+m) buff.push_back(b[y++]);
            if (x < 2*n || y < 2*n) buff.push_back('0'+m), x++, y++;
        }


        while (buff.size() < 3*n) buff.push_back('0');
        if (buff.size() == 3*n) {
            cout << buff << endl; return;
        }
    }
}

