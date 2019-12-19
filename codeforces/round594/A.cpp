//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

ll odd[2], even[2];

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--)
    {
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init()
{
    for(int i = 0; i < 2; i++)
    {
        odd[i] = even[i] = 0;
        int n, x; cin >> n;
        while(n--)
        {
            cin >> x;
            if(x%2 == 0) even[i]++;
            else odd[i]++;
        }
    }
}

void process()
{
    cout << odd[0]*odd[1] + even[0]*even[1] << endl;
}

