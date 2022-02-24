//#pragma GCC optimize ("O3", "unroll-loops")
//#pragma GCC target ("avx2")
//#pragma comment(linker, "/stack:200000000")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define LL long long
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define all_of(v) (v).begin(), (v).end()
#define fi first
#define se second
//const int MAXN = 300005;
//const LL INF = (LL) 1e9 + 8763;
//const LL MOD = (LL) 998244353;
using namespace std;
template <class T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <class T> using max_heap = priority_queue<T, vector<T>, less<T>>;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// function<vector<int>(int, int, int)> func = [&] (int m, int l, int c) {};

void solve() {
	LL n;
	cin >> n;
	string s;
	cin >> s;
	LL m = s.size();
	
	LL cx = 1, cy = 1;
	for (char ch : s) {
		if (ch == 'D') {
			cx++;
		}
		else {
			cy++;
		}
	}
	LL ex = cx, ey = cy;
	
	LL rlim = n - ey, dlim = n - ex;
	LL rocc = (s[0] == 'R'), docc = (s[0] == 'D');
	LL ans = (s[0] == 'D' ? dlim + 2 : rlim + 2);
	for (int i = 1; i < m; i++) {
		char ch = s[i];
		if (ch == 'R') {
			if (docc && !rocc) {
				ans += (1 + dlim) * (1 + rlim);
			}
			else if (!docc) {
				ans += 1;
			}
			else {
				ans += (dlim + 1);
			}
			rocc = 1;
		}
		else {
			if (rocc && !docc) {
				ans += (1 + dlim) * (1 + rlim);
			}
			else if (!rocc) {
				ans += 1;
			}
			else {
				ans += (rlim + 1);
			}
			docc = 1;
		}
	}
	cout << ans << '\n';
}

int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc = 1;
	cin >> tc;
	for (int i = 1; i <= tc; i++) {
		solve();
	}

	return 0;
}

