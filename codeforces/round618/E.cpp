// by redleaf23477
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"

using namespace std;
using ll = long long int;

int n;
vector<ll> arr;

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    init();
    process();
    cout.flush();
    return 0;
}

void init()
{
    cin >> n;
    arr.resize(n);
    for(auto &x : arr) cin >> x;
}

#define val first
#define len second

void blah(vector<pair<double, int>> &ans, double x)
{
    pair<double, int> tmp(x, 1);
    while(!ans.empty() && tmp.first <= ans.back().val)
    {
        double sum = tmp.val * tmp.len + ans.back().val * ans.back().len;
        int len = tmp.len + ans.back().len;
        tmp = make_pair(sum/len, len);
        ans.pop_back();
    }
    ans.push_back(tmp);
}

void process()
{
    vector<pair<double, int>> ans;
    ans.emplace_back(arr[0], 1);
    for(int i = 1; i < n; i++)
    {
        blah(ans, arr[i]);
    }
    for(auto x : ans)
    {
        while(x.len--) cout << fixed << setprecision(10) << x.val << endl;
    }
}

