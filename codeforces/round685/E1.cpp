// by redleaf23477
#include <bits/stdc++.h>

// iostream macros
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
    init();
    process();
    cout.flush();
    return 0;
}

int n;
vector<int> x, ans;

int qry(string op, int i, int j) {
    cout << op << " " << i << " " << j << endl;
    int res; cin >> res;
    if (res == -1) exit(0);
    return res;
}

void init() {
    cin >> n;
    x.resize(n), ans.resize(n);
}

void process() {
    const string XOR = "XOR", AND = "AND", OR = "OR";
    for (int i = 1; i < n; i++) {
        x[i] = qry("XOR", 1, i+1);
    }
    int xor23 = x[1] ^ x[2];
    int and1 = qry(AND, 1, 2), and2 = qry(AND, 1, 3), and3 = qry(AND, 2, 3);
    int y1 = x[1] + 2*and1, y2 = x[2] + 2*and2, y3 = xor23 + 2*and3;
    ans[0] = (y1 + y2 - y3)/2, ans[1] = (y1-y2+y3)/2, ans[2] = (-y1+y2+y3)/2;
    for (int i = 3; i < n; i++) ans[i] = ans[0] ^ x[i];

    cout << "!";
    for (auto x : ans) cout << " " << x;
    cout << endl;

}

