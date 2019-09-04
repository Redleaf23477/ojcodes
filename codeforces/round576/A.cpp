//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;

int n, x, y;
vector<int> arr;

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
    cin >> n >> x >> y;
    arr.resize(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
}

bool ok(int day)
{
    for(int i = 1; i <= x; i++)
        if(day-i >= 0 && arr[day] >= arr[day-i]) return false;
    for(int i = 1; i <= y; i++)
        if(day+i < n && arr[day] >= arr[day+i]) return false;
    return true;
}

void process()
{
    for(int i = 0; i < n; i++)
        if(ok(i))
        {
            cout << i+1 << endl; break;
        }
}

