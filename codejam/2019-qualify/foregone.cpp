//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

string str;
string a, b;

void init();
void process();

int32_t main()
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
    cin >> str;
    a = b = str;
}

void print(string &str)
{
    bool first = true;
    for(size_t i = 0; i < str.size(); i++)
    {
        if(str[i] == '0')
        {
            if(first) continue;
            else cout << str[i];
        }
        else
        {
            cout << str[i];
            first = false;
        }
    }
}

void process()
{
    for(size_t i = 0; i < str.size(); i++)
    {
        if(str[i] == '0') a[i] = '0', b[i] = '0';
        if(str[i] == '1') a[i] = '0', b[i] = '1';
        if(str[i] == '2') a[i] = '1', b[i] = '1';
        if(str[i] == '3') a[i] = '2', b[i] = '1';
        if(str[i] == '4') a[i] = '3', b[i] = '1';
        if(str[i] == '5') a[i] = '2', b[i] = '3';
        if(str[i] == '6') a[i] = '5', b[i] = '1';
        if(str[i] == '7') a[i] = '6', b[i] = '1';
        if(str[i] == '8') a[i] = '7', b[i] = '1';
        if(str[i] == '9') a[i] = '8', b[i] = '1';
    }
    print(a);
    cout << " ";
    print(b);
    cout << endl;
}

