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
    int T = 1;
    for (int t = 1; t <= T; t++) {
        init();
        process();
    }
    cout.flush();
    return 0;
}

const int N = 502;

int n;
int arr[N][N];

void init() {
    cin >> n;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        cin >> arr[i][j];
    }
}

void process() {
    vector<int> pa(n, -1), high(n, -1); // father, current highest ancestor
    vector<int> money(n, 0); {
        for (int i = 0; i < n; i++) money[i] = arr[i][i], high[i] = i;
    }
    function<int(int)> addNode = [&](int salary) {
        int idx = pa.size();
        pa.emplace_back(-1);
        money.emplace_back(salary);
        return idx;
    };
    using Node = tuple<int,int,int>; // [val, r, c]
    vector<Node> nodes; {
        for (int i = 0; i < n; i++) for (int j = i+1; j < n; j++) {
            nodes.emplace_back(arr[i][j], i, j);
        }
        sort(range(nodes));
    }
    for (const auto& [val, r, c] : nodes) {
        int r_anc_money = money[high[r]];
        int c_anc_money = money[high[c]];
        int idx = -1;
        if (val > r_anc_money && val > c_anc_money) {
            idx = addNode(val);
        } else  {
            idx = (val == r_anc_money? high[r] : high[c]);
        }
        // cerr << var(val) << var(r) << var(c) << var(idx) << var(high[r]) << var(high[c]) << endl;
        if (idx != high[r]) {
            pa[high[r]] = idx, high[r] = idx;
        }
        if (idx != high[c]) {
            pa[high[c]] = idx, high[c] = idx;
        }
    }
    // output answer
    cout << money.size() << endl;
    for (auto&& m : money) cout << m << " ";
    cout << endl;
    cout << find(range(pa), -1)-pa.begin()+1 << endl;
    for (int i = 0; i < (int)pa.size(); i++) {
        if (pa[i] != -1) {
            cout << i+1 << " " << pa[i]+1 << endl;
        }
    }
}

