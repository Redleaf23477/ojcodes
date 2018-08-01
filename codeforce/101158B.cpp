// codeforce gym 101158
// 2016-acmicpc-asia-tsukuba-regional-contest
// Problem B Quality of Check Digits
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

int arr[10][10];

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
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            cin >> arr[i][j];
}

int get(int i, int j) { return arr[i][j]; }

int check(int a, int b, int c, int d, int e)
{
    return get(get(get(get(a, b), c), d), e);
}

bool valid(int a, int b, int c, int d, int e)
{
    return get(get(get(get(get(0, a), b), c), d), e) == 0;
}

bool bad(int a, int b, int c, int d, int e)
{
    // adj swap
    if(a != b && valid(b, a, c, d, e)) return true;
    if(b != c && valid(a, c, b, d, e)) return true;
    if(c != d && valid(a, b, d, c, e)) return true;
    if(d != e && valid(a, b, c, e, d)) return true;
    // one mistake
    for(int x = 0; x < 10; x++)
    {
        if(x != a && valid(x, b, c, d, e)) return true;
        if(x != b && valid(a, x, c, d, e)) return true;
        if(x != c && valid(a, b, x, d, e)) return true;
        if(x != d && valid(a, b, c, x, e)) return true;
        if(x != e && valid(a, b, c, d, x)) return true;
    }
    return false;
}

void process()
{
    int cnt = 0;
    for(int a = 0; a < 10; a++)
        for(int b = 0; b < 10; b++)
            for(int c = 0; c < 10; c++)
                for(int d = 0; d < 10; d++)
                {
                    int e = check(0, a, b, c, d);
                    if(bad(a, b, c, d, e)) cnt++;
                }
    cout << cnt << endl;
}

