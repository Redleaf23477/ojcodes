//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;

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
    cin >> str;
}

vector<int> buildKmp(const string &str)
{
    vector<int> fail(str.size());
    fail[0] = -1;
    for(int i = 1, fp = -1; i < str.size(); i++)
    {
        while(fp >= 0 && str[fp+1] != str[i]) fp = fail[fp];
        if(str[fp+1] == str[i]) fp++;
        fail[i] = fp;
    }
    return fail;
}

void process()
{
    vector<int> fail = buildKmp(str);
    int mx = *max_element(fail.begin(), fail.end());
    if(mx == -1) cout << "IMPOSSIBLE" << endl;
    else cout << mx << endl;
}
