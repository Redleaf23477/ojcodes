//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 40;

int n;
int arr[N];  // pos of the right '1'

void init();
void process();

int main()
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
    fill(arr, arr+n, 0);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            char x; cin >> x;
            if(x == '1') arr[i] = j;
        }
    }
}

void process()
{
    ll tot = 0;
    for(int i = 0; i < n; i++)
    {
        // find
        int pos = -1;
        for(int j = i; j < n && pos < 0; j++)
        {
            if(arr[j] <= i) pos = j;
        }
        // move
        for(int j = pos; j > i; j--)
        {
            swap(arr[j], arr[j-1]);
            tot++;
        }
    }
    cout << tot << endl;
}

