//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

int n, k;
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
    cin >> n >> k >> str;
}

void process()
{
    for(int i = 0; i < n && k > 0; i++)
    {
        if(i == 0)
        {
            if(n == 1)
            {
                str[i] = '0', k--;
            }
            else
            {
                if(str[i] == '1') continue;
                else str[i] = '1', k--;
            }
        }
        else
        {
            if(str[i] == '0') continue;
            else str[i] = '0', k--;
        }
    }
    cout << str << endl;
}

