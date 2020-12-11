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

vector<LL> arr;
string s;
vector<bool> op;
const int ADD = 0, SUB = 1, MUL = 2;

void init() {
    int n; cin >> n;
    arr.resize(n+1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    op.resize(3, false);
    cin >> s;
    for (auto c : s) {
        if (c == '+') op[ADD] = true;
        else if (c == '-') op[SUB] = true;
        else op[MUL] = true;
    }
}

void process() {
    if (s.size() == 1) {
        cout << arr[0];
        for (int i = 1; i < n; i++) cout << s << arr[i];
        cout << endl;
    } if (s.size() == 2 && op[SUB]) {
        cout << arr[0];
        string op2 = (op[ADD]? "+" : "*");
        for (int i = 1; i < n; i++) {
            if (arr[i] == 0) cout << "-" << arr[i];
            else cout << op2 << arr[i];
        }
        cout << endl;
    } else {
        cout << arr[0];
        int mul = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i-1] == 0) { cout << "+" << arr[i]; mul = 0; }
            else if (arr[i] == 0) { cout << "+" << arr[i]; mul = 0; }
            else if (arr[i-1] == 1 && mul == 0) cout << "+" << arr[i];
            else if (arr[i-1] == 1 && mul != 0) { cout << "*" << arr[i]; mul++; }
        }
    }
}

