// by redleaf23477
#include <bits/stdc++.h>

// iostream macros
#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
#define name(x) #x
// chrono macros
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()
#define chrono_rand_seed chrono_now.time_since_epoch().count()
// random
std::mt19937_64 myrand(chrono_rand_seed);
// stl
#define range(seq) seq.begin(), seq.end()
template<typename Seq> // requires range
void print_seq(Seq &seq, std::ostream &out = std::cerr) {
    for (auto &&x : seq) out << x << " ";
}

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

int n, m;
vector<int> al, ar, bl, br;

void init() {
    cin >> n >> m;
    al.clear(), ar.clear(), bl.clear(), br.clear();
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x < 0) al.emplace_back(-x);
        else ar.emplace_back(x);
    }
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        if (x < 0) bl.emplace_back(-x);
        else br.emplace_back(x);
    }
    reverse(range(al)), reverse(range(bl));
    /*
    cerr << "al = "; print_seq(al); cerr << endl;
    cerr << "ar = "; print_seq(ar); cerr << endl;
    cerr << "bl = "; print_seq(bl); cerr << endl;
    cerr << "br = "; print_seq(br); cerr << endl;
    */
}

void process() {
    auto run = [&] (vector<int> &a, vector<int> &b) -> int {
        int special_cnt = 0;
        vector<bool> on_special(a.size(), false); {
            int bidx = 0;
            for (int i = 0; i < (int)a.size(); i++) {
                while (bidx < (int)b.size() && b[bidx] < a[i]) bidx++;
                on_special[i] = (bidx < (int)b.size() && b[bidx] == a[i]);
                special_cnt += on_special[i];
            }
        }
        int ans = special_cnt;
        for (int i = 0, j = 0, aidx = 0, box = 0; i < (int)b.size(); i++) {
            while (aidx < (int)a.size() && b[i] + box > a[aidx]) {
                special_cnt -= on_special[aidx];
                box++;
                aidx++;
            }
            while (j < (int)b.size() && b[i] + box > b[j]) {
                j++;
            }
            ans = max(ans, j-i+special_cnt);
        }
        return ans;
    };
    int left = run(al, bl), right = run(ar, br);
    cout << left+right << endl;
}

