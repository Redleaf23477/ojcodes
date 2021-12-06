#include <iostream>
#include <algorithm>
using namespace std;
using LL = long long int;

bool in_op1(LL x, LL y, LL A, LL B, LL N) {
    LL k1 = x - A, k2 = y - B;
    return (k1 == k2) && max(1-A, 1-B) <= k1 && k1 <= min(N-A, N-B);
}

bool in_op2(LL x, LL y, LL A, LL B, LL N) {
    LL k1 = x - A, k2 = B - y;
    return (k1 == k2) && max(1-A, B-N) <= k1 && k1 <= min(N-A, B-1);
}

int main() {
    LL N, A, B, P, Q, R, S;
    cin >> N >> A >> B >> P >> Q >> R >> S;
    for (LL x = P; x <= Q; x++) {
        for (LL y = R; y <= S; y++) {
            if (in_op1(x, y, A, B, N) || in_op2(x, y, A, B, N)) {
                cout << "#";
            } else {
                cout << ".";
            }
        }
        cout << endl;
    }
}