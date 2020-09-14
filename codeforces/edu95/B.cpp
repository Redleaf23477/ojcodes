// by redleaf23477
#include <bits/stdc++.h>

// iostream macros
#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"

using namespace std;
using LL = long long int;

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    for(int t = 1; t <= T; t++)
    {
        init();
        process();
    }
    cout.flush();
    return 0;
}

int n;
vector<int> arr, lk;

void init()
{
    cin >> n;
    arr.resize(n), lk.resize(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < n; i++) cin >> lk[i];
}

void process()
{
    vector<int> unl;
    for(int i = 0; i < n; i++) 
        if(lk[i] == 0) 
            unl.emplace_back(arr[i]);
    sort(unl.begin(), unl.end());
    reverse(unl.begin(), unl.end());
    for(int i = 0, j = 0; i < n; i++)
    {
        if(lk[i] == 1) cout << arr[i] << " ";
        else cout << unl[j++] << " ";
    }
    cout << endl;
}

