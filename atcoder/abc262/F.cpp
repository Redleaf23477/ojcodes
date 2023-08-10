#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int get_shift_time(vector<int> &P, int N, int K) {
    int mn = P[0], mn_shift = 0;
    for (int i = 1; i <= K; i++) {
        if (P[N - i] < mn) {
            mn = P[N - i], mn_shift = i;
        }
    }
    return mn_shift;
}

int get_kill_time(vector<int> &P, int N, int K) {
    int mn = P[0], mn_kill = 0;
    for (int i = 1; i <= K; i++) {
        if (P[i] < mn) {
            mn = P[i], mn_kill = i;
        }
    }
    return mn_kill;
}

void shift(vector<int> &P, int N, int x) {
    vector<int> Q(N);
    for (int i = 0; i < N; i++) {
        Q[i] = P[(i - x + N) % N];
    }
    swap(P, Q);
}

void normalize(vector<int> &P) {
    vector<int> Q;
    for (auto x : P) {
        if (x != -1) Q.emplace_back(x);
    }
    swap(P, Q);
}

void kill_pref(vector<int> &P, int N, int x) {
    P.erase(P.begin(), P.begin() + x);
}

void kill_num(vector<int> &P, int N, int K, int shift_time = 0) {
    vector<int> stk {0};
    for (int i = 1; i < N; i++) {
        while (!stk.empty() && P[stk.back()] > P[i] && K >= 0) {
            if (stk.back() >= shift_time) K--;
            if (K >= 0) {
                P[stk.back()] = -1;
                stk.pop_back();
            }
        }
        if (K < 0) {
            stk.clear();
            K = 0;
        }
        stk.emplace_back(i);
    }
    // clear stack
    while (!stk.empty() && K >= 0) {
        if (stk.back() >= shift_time) K--;
        if (K >= 0) {
            P[stk.back()] = -1;
            stk.pop_back();
        }
    }
}

vector<int> shift_strat(vector<int> P, int N, int K) {
    int shift_time = get_shift_time(P, N, K);
    shift(P, N, shift_time);
    K -= shift_time;
    kill_num(P, N, K, shift_time);
    normalize(P);
    return P;
}

vector<int> kill_strat(vector<int> P, int N, int K) {
    int kill_time = get_kill_time(P, N, K);
    kill_pref(P, N, kill_time);
    N -= kill_time;
    K -= kill_time;
    kill_num(P, N, K);
    normalize(P);
    return P;
}

void solve() {
    int N, K; cin >> N >> K;
    vector<int> P(N);
    for (auto &x : P) cin >> x;

    vector<int> Q_shift = shift_strat(P, N, K);
    vector<int> Q_kill = kill_strat(P, N, K);

    vector<int> &ans = (Q_shift < Q_kill? Q_shift : Q_kill);
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //    int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



