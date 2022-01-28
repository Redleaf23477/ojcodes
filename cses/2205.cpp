#include <bits/stdc++.h>
using namespace std;

vector<int> arr;

void print_arr() {
    for (int i = arr.size() - 1; i >= 0; i--) {
        cout << arr[i];
    }
    cout << endl;
}

void g(int n) {
    if (n == 0) {
        print_arr();
    } else {
        g(n-1);
        arr[n-1] ^= 1;
        g(n-1);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    arr.assign(n, 0);
    g(n);
}

/*
00
01
11
10
 */
