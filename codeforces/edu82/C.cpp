// by redleaf23477
#include <bits/stdc++.h>

#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"

using namespace std;
using ll = long long int;

string str;

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--)
    {
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init()
{
    cin >> str;
}

bool ok(int pos[], int x)
{
    for(int i = 0; i < 26; i++) if(pos[i] == x) return false;
    return true;
}

void process()
{
    int pos[26]; for(int i = 0; i < 26; i++) pos[i] = 7122;
    int n = str.size();
    pos[str[0]-'a'] = 1;
    int cur = 1;
    bool good = true;
    for(int i = 1; i < n && true; i++)
    {
        if(str[i] == str[i-1]) continue;
        char ch = str[i];
        if(pos[ch-'a'] == 7122)
        {
            if(ok(pos, cur+1))
            {
                pos[ch-'a'] = cur = cur+1;
            }
            else if(ok(pos, cur-1))
            {
                pos[ch-'a'] = cur = cur-1;
            }
            else good = false;
        }
        else if(pos[ch-'a'] == cur-1)
        {
            cur = cur-1;
        }
        else if(pos[ch-'a'] == cur+1)
        {
            cur = cur+1;
        }
        else
        {
            good = false;
        }
    }
    if(good)
    {
        int mn = *min_element(pos, pos+26);
        char keyboard[26]; for(int i = 0; i < 26; i++) keyboard[i] = -1;
        for(int i = 0; i < 26; i++)
        {
            if(pos[i] == 7122) continue;
            keyboard[pos[i]-mn] = 'a'+i;
        }
        for(int i = 0; i < 26; i++)
        {
            if(pos[i] == 7122)
            {
                for(int j = 0; j < 26; j++)
                {
                    if(keyboard[j] == -1)
                    {
                        keyboard[j] = 'a'+i; break;
                    }
                }
            }
        }
        cout << "YES" << endl;
        for(int i = 0; i < 26; i++) cout << keyboard[i];
        cout << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}
