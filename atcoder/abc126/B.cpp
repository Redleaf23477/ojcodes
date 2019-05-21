//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

int a, b;

void init();
void process();

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    init();
    process();
    cout.flush();
    return 0;
}

void init()
{
    int tmp; cin >> tmp;
    a = tmp/100;
    b = tmp%100;
}

void process()
{
    bool a_m = false, b_m = false;
    if(1 <= a && a <= 12) a_m = true;
    if(1 <= b && b <= 12) b_m = true;

    if(a_m && b_m) cout << "AMBIGUOUS" << endl;
    else if(a_m) cout << "MMYY" << endl;
    else if(b_m) cout << "YYMM" << endl;
    else cout << "NA" << endl;
}

