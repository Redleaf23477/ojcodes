//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;

double h, l;

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
    cin >> h >> l;
}

void process()
{
    cout << fixed << setprecision(10) << (l*l - h*h)/2.0/h << endl;
}

