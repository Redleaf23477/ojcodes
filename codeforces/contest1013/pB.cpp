//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 100005;

int n, x;
int arr[N], after[N];

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
    cin >> n >> x;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < n; i++) after[i] = arr[i]&x;
    sort(arr, arr+n);
    sort(after, after+n);
}

void process()
{
    // zero
    for(int i = 0; i < n; i++)
    {
        if(binary_search(arr+i+1, arr+n, arr[i]))
        {
            cout << 0 << endl; return;
        }
    }
    // one
    for(int i = 0; i < n; i++)
    {
        if(binary_search(arr, arr+i, arr[i]&x) || binary_search(arr+i+1, arr+n, arr[i]&x))
        {
            cout << 1 << endl; return;
        }
    }
    // two
    for(int i = 0; i < n; i++)
    {
        if(binary_search(after+i+1, after+n, after[i]))
        {
            cout << 2 << endl; return;
        }
    }
    // gg
    cout << -1 << endl;
}

