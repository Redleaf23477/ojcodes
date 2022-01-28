#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

bool search(vector<tuple<LL,int>> &arr, LL sum) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j+1 < n; j++) {
            LL s = get<0>(arr[i]) + get<0>(arr[j]);
            auto it = lower_bound(arr.begin() + j + 1, arr.end(), make_tuple(sum - s, 0));
            if (get<0>(*it) + s == sum) {
                cout << get<1>(arr[i]) << " "
                    << get<1>(arr[j]) << " "
                    << get<1>(*it) << "\n";
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n;
    LL sum;
    cin >> n >> sum;
    vector<tuple<LL,int>> arr(n);
    for (int i = 0; i < n; i++) {
        LL x; cin >> x;
        arr[i] = make_tuple(x, i+1);
    }
    sort(arr.begin(), arr.end());

    if (!search(arr, sum)) cout << "IMPOSSIBLE" << endl;
}

