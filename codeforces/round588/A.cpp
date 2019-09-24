//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

int arr[4];

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
    for(int i = 0; i < 4; i++) cin >> arr[i];
}

void process()
{
    int sum = 0;
    for(int i = 0; i < 4; i++) sum += arr[i];
    if(sum%2 != 0) { cout << "NO" << endl; return; }
    for(int i = 0; i < (1<<4); i++)
    {
        int tmp = 0;
        for(int d = 0; d < 4; d++)
            if((i>>d)&1) tmp += arr[d];
        if(tmp == sum/2) { cout << "YES" << endl; return; }
    }
    cout << "NO" << endl;
}

