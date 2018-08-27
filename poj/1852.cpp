//
#include <iostream>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 1000000;

int n, len;
int arr[N];

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
    cin >> len >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
}

int small()
{
    int mn = 0;
    for(int i = 0; i < n; i++)
    {
        mn = max(mn, min(arr[i], len-arr[i]));
    }
    return mn;
}

int big()
{
    int mx = 0;
    for(int i = 0; i < n; i++)
    {
        mx = max(mx, max(arr[i], len-arr[i]));
    }
    return mx;
}

void process()
{
    cout << small() << " " << big() << endl;
}

