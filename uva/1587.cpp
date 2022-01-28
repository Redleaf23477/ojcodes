#include <bits/stdc++.h>
using namespace std;

using P = pair<int,int>;
constexpr int N = 6;

bool good(vector<P> &arr) {
    sort(arr.begin(), arr.end());
    if (arr[0] != arr[1] || arr[2] != arr[3] || arr[4] != arr[5]) return false;
    vector<int> tmp;
    for (int i = 0; i < N; i += 2) {
        tmp.emplace_back(arr[i].first);
        tmp.emplace_back(arr[i].second);
    }
    sort(tmp.begin(), tmp.end());
    if (tmp[0] != tmp[1] || tmp[2] != tmp[3] || tmp[4] != tmp[5]) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    vector<P> arr(N);
    while (cin >> arr[0].first >> arr[0].second) {
        for (int i = 1; i < N; i++) {
            cin >> arr[i].first >> arr[i].second;
        }
        for (int i = 0; i < N; i++) {
            if (arr[i].first < arr[i].second) {
                swap(arr[i].first, arr[i].second);
            }
        }
        if (good(arr)) cout << "POSSIBLE" << endl;
        else cout << "IMPOSSIBLE" << endl;
    }
}

