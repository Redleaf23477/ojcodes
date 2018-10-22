//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--)
    {
        process();
    }
    cout.flush();
    return 0;
}

void init()
{
}

int firstLower(string s)
{
    for(int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if('a' <= c && c <= 'z') return i;
    }
    return -1;
}

int firstUpper(string s)
{
    for(int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if('A' <= c && c <= 'Z') return i;
    }
    return -1;
}

int firstDigit(string s)
{
    for(int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if('0' <= c && c <= '9') return i;
    }
    return -1;
}

void process()
{
    string str; cin >> str;
    int fl = firstLower(str);
    int fu = firstUpper(str);
    int fd = firstDigit(str);
    if(fl >= 0 && fu >= 0 && fd >= 0) 
    {
        //
    }
    else if(fl >= 0 && fu >= 0)
    {
        for(int i = 0; i < str.size(); i++)
        {
            if(i != fl && i != fu) 
            {
                str[i] = '1'; break;
            }
        }
    }
    else if(fl >= 0 && fd >= 0)
    {
        for(int i = 0; i < str.size(); i++)
        {
            if(i != fl && i != fd) 
            {
                str[i] = 'A'; break;
            }
        }
    }
    else if(fd >= 0 && fu >= 0)
    {
        for(int i = 0; i < str.size(); i++)
        {
            if(i != fd && i != fu) 
            {
                str[i] = 'a'; break;
            }
        }
    }
    else if(fl >= 0)
    {
        if(fl > 2)
        {
            str[0] = 'A', str[1] = '1';
        }
        else if(fl+2 < str.size())
        {
            str[fl+1] = 'A', str[fl+2] = '1';
        }
        else
        {
            str[fl-1] = 'A', str[fl+1] = '1';
        }
    }
    else if(fu >= 0)
    {
        if(fu > 2)
        {
            str[0] = 'a', str[1] = '1';
        }
        else if(fu+2 < str.size())
        {
            str[fu+1] = 'a', str[fu+2] = '1';
        }
        else
        {
            str[fu-1] = 'a', str[fu+1] = '1';
        }
    }
    else if(fd >= 0)
    {
        if(fd > 2)
        {
            str[0] = 'A', str[1] = 'a';
        }
        else if(fd+2 < str.size())
        {
            str[fd+1] = 'A', str[fd+2] = 'a';
        }
        else
        {
            str[fd-1] = 'A', str[fd+1] = 'a';
        }
    }
    cout << str << endl;
}

