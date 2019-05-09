//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

int n;
vector<int> even, odd;

void init();
void process();

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T, caseN = 0; cin >> T;
    while(T--)
    {
        cout << "Case #" << ++caseN << ": ";
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init()
{
    cin >> n;
    even.clear(), odd.clear();
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        if(i%2 == 0) even.push_back(x);
        else odd.push_back(x);
    }
}

void process()
{
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());
    int e = -1, o = -1;
    for(int i = 0; i < n; i++)
    {
        if(i%2 == 0) 
        {
            e = even[i/2];
            if(e < o) 
            {
                cout << i-1 << endl; return;
            }
        }
        else 
        {
            o = odd[i/2];
            if(o < e)
            {
                cout << i-1 << endl; return;
            }
        }
    }
    cout << "OK" << endl;
}

