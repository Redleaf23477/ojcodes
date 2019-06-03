//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

string str;

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
    cin >> str;
}

bool invalid()
{
    if(str.back() == '1') return true;
    if(str[0] != '1') return true;
    for(size_t i = 0; i < str.size()-1; i++)
    {
        if(str[i] != str[str.size()-2-i]) return true;
    }
    return false;
}

void process()
{
    if(invalid()) cout << -1 << endl;
    else
    {
        int cnt1 = 0;
        for(auto c:str) cnt1 += (c=='1'? 1 : 0);
        // middle
        // 1 2 ... (cnt1)+1, cnt1 edges
        for(int i = 0; i < cnt1; i++)
        {
            cout << i+1 << " " << i+2 << endl;
        }
        for(size_t i = 1, j = 2, k = cnt1+2, skip = 0; i < str.size(); i++)
        {
            if(str[i] == '1')
            {
                for(size_t c = 0; c < skip; c++) cout << j << " " << k++ << endl;
                j++;
                skip = 0;
            }
            else skip++;
        }
    }
}

