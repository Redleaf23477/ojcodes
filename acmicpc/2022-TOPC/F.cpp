#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int N; cin >> N;
    vector<tuple<double, string>> arr(6);
    for (auto &[val, name] : arr) {
        cin >> name;
        int pt, pu, rt, ru, f; cin >> pt >> pu >> rt >> ru >> f;
        val = 0.56 * ru + 0.24 * rt + 0.14 * pu + 0.06 * pt + 0.3 * f;
    }
    sort(arr.begin(), arr.end());
    vector<int> ticket(6, 0);
    for (int i = 5; N > 0; i = (i + 5) % 6, N--) {
        ticket[i]++;
    }
    for (int i = 0; i < 6; i++) {
        if (get<1>(arr[i]) == "Taiwan") cout << ticket[i] << "\n";
    }
}

