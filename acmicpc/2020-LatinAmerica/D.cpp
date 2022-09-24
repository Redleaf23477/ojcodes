#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> arr(100000+2, 0);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        arr[x] += 1;
    }

    if (n == 1) {
        cout << "N\n";
    } else {
        int one_cnt = 0;
        for (size_t i = 0; i+1 < arr.size(); i++) {
            arr[i+1] += arr[i] / 2;
            arr[i] %= 2;
            if (arr[i] == 1) one_cnt += 1;
        }

        cout << (one_cnt == 1 || one_cnt == 2? "Y\n" : "N\n"); 
    }
}

