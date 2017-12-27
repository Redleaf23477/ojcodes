//
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

int n;
int letters;

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
    cin >> n;
    letters = -1;
}

void process()
{
    int posn = 26;
    int gg = 0;
    while(n--)
    {
        char ch; string str; cin >> ch >> str;
        if(ch == '.') //safe
        {
            for(auto c:str)
            {
                int p = c-'a';
                if(letters&(1<<p)) posn--, letters&=(~(1<<p));
            }
        }
        else if(ch == '!') //shock
        {
            if(posn == 1) 
            {
                gg++;
                continue;
            }
            int tmp = 0;
            for(auto c:str)
            {
                int p = c-'a';
                tmp|=(1<<p);
            }
            letters &= tmp;
            posn = 0;
            for(int i = 0; i < 32; i++) if(letters&(1<<i)) posn++;
        }
        else //qry
        {
            if(posn == 1) gg++;
            int p = str[0]-'a';
            if(letters&(1<<p)) posn--, letters &= (~(1<<p));
        }
    }
    cout << (gg>0?gg-1:gg) << endl;
}

