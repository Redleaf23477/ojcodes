//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;

string a, b;
ll x, y, z, l;

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
    cin >> a >> b >> x >> y >> z >> l;
}

void process()
{
    stringstream ss;
    ss << x+y+z;
    string n;
    ss >> n;
    reverse(n.begin(), n.end());
    if(l == 1) cout << n << a << b << endl;
    else if(l == 2) cout << a << n << b << endl;
    else cout << a << b << n << endl;
}

