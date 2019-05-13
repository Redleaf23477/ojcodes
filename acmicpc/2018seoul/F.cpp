//
#include <bits/stdc++.h>

#define endl '\n'
#define int ll
using namespace std;
typedef long long ll;

enum Res
{
    ERR,
    IMP,
    PRO
};

int idx;
vector<char> input;

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
    char ch;
    while(cin >> ch) input.push_back(ch);
}

bool isOp()
{
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%') return true;
    return false;
}

Res parseBinary();
Res parseOp();
Res parseProper();
Res parseVar();

Res parseOp()
{
    if(idx == input.size()) return ERR;
    char ch = input[idx++];
    if(isOp()) return PRO;
    else return ERR;
}

Res parseBinary()
{
    if(idx == input.size()) return ERR;
    char ch = input[idx];
    if(ch == '(')
    {
        Res res = PRO;
        idx++; // '('
        res = parseBinary();
        idx++; // ')'
        return (res == ERR || idx > input.size() ? ERR : IMP);
    }
    else
    {
        Res res1, res2, res3;
        res1 = parseProper();
        res2 = parseOp();
        res3 = parseProper();
        if(res1 == ERR || res2 == ERR || res3 == ERR) return ERR;
        else if(res1 == IMP || res2 == IMP || res3 == IMP) return IMP;
        else return PRO;
    }
}

Res parseVar()
{
    char ch = input[idx++];
    if(isOp(ch)) return ERR;
    else return PRO;
}

Res parseProper()
{

}

void process()
{
    idx = 0;
    Res res = parseBinary();
    if(idx != input.size()) cout << "error" << endl;
    else if(res == ERR) cout << "error" << endl;
    else if(res == IMP) cout << "improper" << endl;
    else cout << "proper" << endl;
}

