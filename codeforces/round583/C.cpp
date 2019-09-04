//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;

int n;
string str;

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
    cin >> n >> str;
}

bool impossible()
{
    if(n&1) return true;
    int l = 0;
    for(auto b : str)
    {
        if(b == '(') l++;
        else l--;
    }
    return l != 0;
}

void process()
{
    if(impossible()) { cout << "No" << endl; return; }
    int l = 0;
    bool needFix = false;
    for(auto b : str)
    {
        if(b == '(') l++;
        else
        {
            if(l > 0) { l--; continue; }
            if(needFix) { cout << "No" << endl; return; }
            needFix = true;
        }
    }
    cout << "Yes" << endl;
}

