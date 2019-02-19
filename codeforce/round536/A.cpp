//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

const int N = 550;
int n;
string arr[N];

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
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
}

bool isCross(int r, int c)
{
    return (arr[r][c] == 'X' && arr[r-1][c-1] == 'X' && arr[r+1][c-1] == 'X' && arr[r-1][c+1] == 'X' && arr[r+1][c+1] == 'X');
}

void process()
{
    int cnt = 0;
    for(int i = 1; i < n-1; i++)
        for(int j = 1; j < n-1; j++)
            cnt += isCross(i, j);
    cout << cnt << endl;
}

