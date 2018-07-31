//codeforce 922D
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long int ll;

struct Seg
{
    string nstr;
    ll s, h, cnt;
    Seg(string str):nstr(str)
    {
        s = h = cnt = 0;
        for(auto c:str)
        {
            if(c == 's') s++;
            else h++, cnt += s;
        }
    }
    bool operator < (Seg &that)
    {
        return this->s*that.h > this->h*that.s;
    }
};

int n;
vector<Seg> noise;

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
    for(int i = 0; i < n; i++)
    {
        string s; cin >> s; noise.emplace_back(s);
    }
    sort(noise.begin(), noise.end());
}

void process()
{
    ll tot = 0, s = 0;
    for(auto x:noise)
    {
        tot += s*x.h + x.cnt;
        s += x.s;
    }
    cout << tot << endl;
}

