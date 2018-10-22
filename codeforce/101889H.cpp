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
    ll arr[3], brr[3], tot = 0;
    for(int i = 0; i < 3; i++) cin >> arr[i];
    for(int i = 0; i < 3; i++) cin >> brr[i];
    for(int i = 0; i < 3; i++)
    {
        if(brr[i] > arr[i]) tot += brr[i]-arr[i];
    }
    cout << tot << endl;
}

