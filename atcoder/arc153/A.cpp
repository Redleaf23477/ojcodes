#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

// 123456789
// aabcddefe

void print(int num) {
    int f = num % 10; num /= 10;
    int e = num % 10; num /= 10;
    int d = num % 10; num /= 10;
    int c = num % 10; num /= 10;
    int b = num % 10; num /= 10;
    int a = num % 10; num /= 10;
    cout << a << a << b << c << d << d << e << f << e << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int num = 100000;
    while (--n) {
        num++;
    }
    print(num);
}

