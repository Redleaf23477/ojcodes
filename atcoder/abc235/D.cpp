#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

/*
int str_rotate(int x) {
    stringstream ss; ss << x;
    string s; ss >> s;
    ss.clear();
    ss << s.back() << s.substr(0, s.size()-1);
    ss >> x;
    return x;
}
*/

int rotate(int x) {
    int pw = 1, tmp = x;
    while (tmp >= 10) {
        pw *= 10;
        tmp /= 10;
    }
    int y = x % 10;
    y = y * pw + x / 10;
    /*
    int y2 = str_rotate(x);
    if (y != y2) {
        cerr << "x = " << x << ", y = " << y << ", y2 = " << y2 << endl;
        cerr << "pw = " << pw << endl;
        assert(y == str_rotate(x));
    }
    */
    return y;
}

int bfs(LL a, LL n) {
    using T = tuple<LL,LL>;  // state, step
    queue<T> q;
    const LL MX = 1000000;
    vector<bool> s(MX, false);
    q.emplace(1, 0), s[1] = true;
//    cerr << "MX = " << MX << endl;
    while (!q.empty()) {
        auto [x, len] = q.front(); q.pop();
//        cerr << "x = " << x << ", len = " << len << endl;
        if (x == n) return len;

        vector<LL> next_step;
        if (x * a < MX) next_step.emplace_back(x*a);
        if (x >= 10 && x % 10 != 0) next_step.emplace_back(rotate(x));
        for (auto y : next_step) {
            if (s[y] == false) {
                q.emplace(y, len+1);
                s[y] = true;
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    LL a, n; cin >> a >> n;
    cout << bfs(a, n) << "\n";
}

