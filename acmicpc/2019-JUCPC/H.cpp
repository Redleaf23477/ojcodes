#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    double PI = acos(-1);

    double V, S; cin >> V >> S;

    double theta = PI / V;

    double R = S / 2.0 / sin(theta);

    cout << fixed << setprecision(10) << R * R * PI << "\n";
}

