#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int x; cin >> x;
    int c = x%10; x /= 10;
    int b = x%10; x /= 10;
    int a = x%10;
    cout << (a+b+c) * (111) << endl;
}

