//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;

bool cmp(const P &lhs, const P &rhs) { return lhs > rhs; }

const int N = 1010;
int n;
P arr[N];

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int caseN = 0;
    while(cin >> n && n)
    {
        cout << "Case " << ++caseN << ": ";
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init()
{
    for(int i = 0; i < n; i++) cin >> arr[i].second >> arr[i].first;
    sort(arr, arr+n, cmp);
}

void process()
{
    ll pre = 0, sum = 0;
    for(int i = 0; i < n; i++)
    {
        pre += arr[i].second;
        sum = max(sum, pre+arr[i].first);
    }
    cout << sum << endl;
}

