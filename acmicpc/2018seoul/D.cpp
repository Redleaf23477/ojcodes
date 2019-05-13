#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long ll;

map<string, string> fix;

void init()
{
    fix["a"] = "as";
    fix["i"] = fix["y"] = "ios";
    fix["l"] = "les";
    fix["n"] = fix["ne"] = "anes";
    fix["o"] = "os";
    fix["r"] = "res";
    fix["t"] = "tas";
    fix["u"] = "us";
    fix["v"] = "ves";
    fix["w"] = "was";
}

void process()
{
    int T; cin >> T;
    while(T--)
    {
        string str; cin >> str;
        bool done = false;
        for(auto p:fix)
        {
            //			cout << p.first << " " << str.substr(str.size() - p.first.size()) << endl;
            if(str.size() >= p.first.size() && str.substr(str.size()-p.first.size()) == p.first)
            {
                str.erase(str.size()-p.first.size());
                str += p.second;
                done = true;
                break;
            }
        }
        if(!done) str += "us";
        cout << str << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    init();
    process();
    cout.flush();
    return 0;
}
