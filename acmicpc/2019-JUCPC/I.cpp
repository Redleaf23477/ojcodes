#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

vector<int> parse(string &str) {
    vector<int> tok;
    string buff;
    auto flush = [&]() {
        if (buff.empty()) return;
        stringstream ss(buff);
        int n; ss >> n;
        tok.emplace_back(n);
        buff.clear();
    };
    for (auto ch : str) {
        if (ch == '(') {
            flush();
            tok.emplace_back(-1);
        } else if (ch == ')') {
            flush();
            tok.emplace_back(-2);
        } else {
            buff.push_back(ch);
        }
    }
    return tok;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    string str; cin >> str;
    vector<int> tok = parse(str);

    /*
    cerr << "tokens: ";
    for (auto x : tok) {
        if (x == -1) cerr << "( ";
        else if (x == -2) cerr << ") ";
        else cerr << x << " ";
    }
    cerr << endl;
    */

    vector<int> pa(n + 1, 0);
    stack<int> stk, peo;
    for (auto x : tok) {
        if (x == -1) {
            stk.push(-1);
        } else if (x == -2) {
            while (stk.top() != -1) stk.pop(), peo.pop();
            stk.pop();
        } else {
            if (!stk.empty()) pa[x] = peo.top();
            stk.push(x);
            peo.push(x);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << pa[i] << " ";
    }
    cout << "\n";
}

