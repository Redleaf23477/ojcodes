#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    vector<int> small_primes {2, 3, 5, 7};
    vector<int> more_primes {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    for (auto p : small_primes) {
        cout << p << endl;
        string res; cin >> res;
        if (res == "yes") {
            for (auto p2 : more_primes) {
                if (p * p2 >= 100) break;
                cout << p * p2 << endl;
                cin >> res;
                if (res == "yes") {
                    cout << "composite" << endl;
                    return;
                }
            }
            cout << "prime" << endl;
            return;
        }
    }
    cout << "prime" << endl;
}

int main() {
    solve();
}



