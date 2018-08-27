//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    process();
    cout.flush();
    return 0;
}

void init()
{
}

void process()
{
    const int N = 1010;
    int arr[N] = {0};
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        int l, r; cin >> l >> r;
        arr[l]++, arr[r+1]--;
    }
    int ptr = 0;
    vector<int> ans;
    for(int i = 1; i <= m; i++)
    {
        ptr += arr[i];
        if(ptr == 0) ans.push_back(i);
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << " \n"[i==ans.size()-1];
}

