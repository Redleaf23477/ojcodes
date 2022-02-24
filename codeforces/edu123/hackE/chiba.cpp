#include <bits/stdc++.h>
#define debug(a) cout << #a << " = " << a << "\n";
using namespace std;

typedef long long ll;
ll MOD = 998244353LL;

ll n;
string s;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int _ ; cin >> _ ;
	while ( _ -- ) {
		cin >> n >> s;
		
		pair<int, int> now = {1, 1};
		vector<ll> x, y;
		
		if (s.front() == 'D') {
			for (auto &i : s) {
				i = 'R' + 'D' - i;
			}
		}
		
		reverse(s.begin(), s.end());
		ll ans = 0;
		while (!s.empty() && s.back() == 'R') {
			ans += n - 1;
			s.pop_back();
		}
		
		if (find(s.begin(), s.end(), 'D') == s.end()) {
			cout << n << "\n";
			continue;
		}
		
		for (auto i : s) {
			
			if (i == 'R') {
				x.push_back(n - now.first);
				now.second += 1;
			} else {
				y.push_back(n - now.second);
				now.first += 1;
			}
		}
		
		for (auto i : x) ans += i - (n - now.first);
		for (auto i : y) ans += i - (n - now.second);
		cout << n * n - ans << "\n";
	}
}
