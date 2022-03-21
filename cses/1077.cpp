#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void print_median(multiset<int> &lhs, multiset<int> &rhs, int k, LL &lsum, LL &rsum) {
    LL med;
    if (k % 2 == 0) {
        auto it = lhs.end(); it--;
        med = *it;
    } else {
        med = *rhs.begin();
    }
    cout << med * lhs.size() - lsum + rsum - med * rhs.size() << " ";
}

void balance(multiset<int> &lhs, multiset<int> &rhs, int k, LL &lsum, LL &rsum) {
    while (lhs.size() != k/2) {
        lsum += *rhs.begin();
        rsum -= *rhs.begin();
        lhs.insert(*rhs.begin());
        rhs.erase(rhs.begin());
    }
    if (!lhs.empty()) {
        while (true) {
            auto it = lhs.end(); it--;
            if (*it > *rhs.begin()) {
                int l = *it, r = *rhs.begin();
                lsum -= l, lsum += r;
                rsum -= r, rsum += l;
                lhs.erase(it), rhs.erase(rhs.begin());
                lhs.insert(r), rhs.insert(l);
            } else {
                break;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;

    // lhs: k/2, rhs: k - k/2
    multiset<int> lhs, rhs;
    LL lsum = 0, rsum = 0;
    for (int i = 0; i < k; i++) rhs.insert(arr[i]), rsum += arr[i];
    balance(lhs, rhs, k, lsum, rsum);
    print_median(lhs, rhs, k, lsum, rsum);
    for (int i = k; i < n; i++) {
        // remove arr[i-k]
        if (lhs.count(arr[i-k]) != 0) {
            auto it = lhs.find(arr[i-k]);
            lsum -= *it;
            lhs.erase(it);
        } else {
            auto it = rhs.find(arr[i-k]);
            rsum -= *it;
            rhs.erase(it);
        }
        // add arr[i] to rhs
        rhs.insert(arr[i]), rsum += arr[i];
        // balance lhs, rhs
        balance(lhs, rhs, k, lsum, rsum);
        // print
        print_median(lhs, rhs, k, lsum, rsum);
    }
    cout << "\n";
}

