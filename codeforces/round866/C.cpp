#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int find(int val, vector<int> &arr, int start, int stop, int inc) {
    for (int i = start; i != stop; i += inc) {
        if (arr[i] == val) return i;
    }
    return -1;
}

int find_good(int mex, vector<int> &s) {
    if (s[0] > mex+1) return s[0];
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i-1]) return s[i];
        else if (s[i] > mex+1) return s[i];
    }
    return -1;
}

int get_mex(vector<int> &s) {
    int mex = 0;
    for (auto num : s) {
        if (mex < num) return mex;
        else if (mex == num) mex++;
    }
    return mex;
}

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    vector<int> s1(arr);
    sort(s1.begin(), s1.end());
    int mex = get_mex(s1);
    int L = find(mex + 1, arr, 0, n, 1);
    int R = find(mex + 1, arr, n-1, -1, -1);
    int G = find_good(mex, s1);
    if (L != -1) {
        for (int i = L; i <= R; i++) { 
            arr[i] = mex;
        }
    } else if (G != -1) {
        *find(arr.begin(), arr.end(), G) = mex;
    } 

    vector<int> s2(arr);
    sort(s2.begin(), s2.end());
    int mex2 = get_mex(s2);
    if (mex + 1 == mex2) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



