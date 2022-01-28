#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void print_median(multiset<int> &lhs, multiset<int> &rhs, int k) {
    if (k % 2 == 0) {
        auto it = lhs.end(); it--;
        cout << *it << " ";
    } else {
        cout << *rhs.begin() << " ";
    }
}

void balance(multiset<int> &lhs, multiset<int> &rhs, int k) {
    while (lhs.size() != k/2) {
        lhs.insert(*rhs.begin());
        rhs.erase(rhs.begin());
    }
    if (!lhs.empty()) {
        while (true) {
            auto it = lhs.end(); it--;
            if (*it > *rhs.begin()) {
                int l = *it, r = *rhs.begin();
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
    for (int i = 0; i < k; i++) rhs.insert(arr[i]);
    balance(lhs, rhs, k);
    print_median(lhs, rhs, k);
    for (int i = k; i < n; i++) {
        // remove arr[i-k]
        if (lhs.count(arr[i-k]) != 0) {
            auto it = lhs.find(arr[i-k]);
            lhs.erase(it);
        } else {
            auto it = rhs.find(arr[i-k]);
            rhs.erase(it);
        }
        // add arr[i] to rhs
        rhs.insert(arr[i]);
        // balance lhs, rhs
        balance(lhs, rhs, k);
        // print
        print_median(lhs, rhs, k);
    }
    cout << "\n";
}

